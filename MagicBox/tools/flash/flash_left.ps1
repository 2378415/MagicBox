# 官方固件 LEFT（V3.2）刷写脚本：探测 → 备份 → 刷写 → 校验
# 用法: pwsh -File tools\flash\flash_left.ps1 [-Port COM9] [-SkipBackup]
param(
  [string]$Port = "",
  [switch]$SkipBackup,
  [switch]$Force
)

$ErrorActionPreference = 'Stop'
$root = 'D:\JinPeng\MagicBox'
Set-Location $root
$img  = '官方固件\V3.2_LEFT.bin'
$log  = 'backups\flash_left.log'
New-Item -ItemType Directory -Force -Path backups, backups\probe | Out-Null
function Log($m) { $t = (Get-Date).ToString('HH:mm:ss'); "$t $m" | Tee-Object -FilePath $log -Append }

function Find-Port {
  $p = [System.IO.Ports.SerialPort]::GetPortNames()
  if ($p.Count -eq 1) { return $p[0] }
  # 优先 USB-Serial/JTAG (VID_303A)
  $dev = Get-PnpDevice -PresentOnly -ErrorAction SilentlyContinue |
         Where-Object { $_.Class -eq 'Ports' -and $_.InstanceId -match 'VID_303A' } |
         Select-Object -First 1
  if ($dev -and $dev.FriendlyName -match '\((COM\d+)\)') { return $Matches[1] }
  if ($p.Count -gt 0) { return $p[0] }
  return $null
}

if (-not $Port) { $Port = Find-Port }
if (-not $Port) { Log 'ERR 未找到串口，设备不在下载模式'; exit 2 }
Log "port=$Port"

$py = 'python'
$esp = @('-m','esptool','-p',$Port,'-c','esp32s3','-b','921600')

# 1) 探测：读当前 app 区首块，判定左右片
Log '--- 探测当前芯片身份 ---'
& $py @esp read-flash 0x10000 0x2000 backups\probe\app_head.bin 2>&1 | ForEach-Object { Log $_ }
Start-Sleep -Seconds 2
& $py tools\flash\probe_side.py backups\probe\app_head.bin 0x10000 2>&1 | ForEach-Object { Log $_ }
$side = (& $py tools\flash\probe_side.py backups\probe\app_head.bin 0x10000 2>&1 | Select-String '判定').ToString()

if ($side -match 'RIGHT' -and -not $Force) {
  Log 'ERR 当前连接的是 RIGHT 片，拒绝刷 LEFT 镜像（双片不可混刷）。确认无误会用 -Force。'
  exit 3
}

# 2) 备份
if (-not $SkipBackup) {
  Log '--- 全片备份 0x0..0x400000 ---'
  & $py @esp read-flash 0x0 0x400000 backups\stock_full_before_left.bin 2>&1 | ForEach-Object { Log $_ }
  Log '--- NVS 备份 0x9000..0xF000 ---'
  Start-Sleep -Seconds 2
  & $py @esp read-flash 0x9000 0x6000 backups\nvs_before_left.bin 2>&1 | ForEach-Object { Log $_ }
  Start-Sleep -Seconds 2
}

# 3) 刷写（整片 0x0，DIO/80MHz/4MB，与镜像头一致）
Log '--- write-flash 0x0 V3.2_LEFT.bin ---'
& $py @esp write-flash --flash-mode dio --flash-freq 80m --flash-size 4MB 0x0 $img --after no-reset 2>&1 | ForEach-Object { Log $_ }
if ($LASTEXITCODE -ne 0) { Log "ERR write-flash 失败 exit=$LASTEXITCODE"; exit 4 }

# 4) 回读校验（stub 仍在运行，用 --before no-reset 重连）
Log '--- verify-flash ---'
& $py -m esptool -p $Port -c esp32s3 -b 921600 --before no-reset verify-flash --flash-mode dio --flash-freq 80m --flash-size 4MB 0x0 $img 2>&1 | ForEach-Object { Log $_ }
$verifyExit = $LASTEXITCODE

# 5) 复位启动
Log '--- 复位启动 ---'
& $py -m esptool -p $Port -c esp32s3 --before no-reset --after hard-reset run 2>&1 | ForEach-Object { Log $_ }
Log "verify_exit=$verifyExit"
if ($verifyExit -ne 0) { exit 5 }
Log 'DONE'
