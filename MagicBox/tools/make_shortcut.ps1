# 在桌面创建 "MagicBox 台架工具" 快捷方式（boxbench GUI）
#   powershell -ExecutionPolicy Bypass -File tools\make_shortcut.ps1
#   powershell ... -NoIcon        不设自定义图标
#   powershell ... -Name "xxx"    换快捷方式名字
param(
    [string]$Name = 'MagicBox 台架工具',
    [switch]$NoIcon,
    [string]$Python = 'D:\Apply\Python311\pythonw.exe'
)

$repo = Split-Path -Parent $PSScriptRoot
$desktop = [Environment]::GetFolderPath('Desktop')
$lnk = Join-Path $desktop ("{0}.lnk" -f $Name)

if (-not (Test-Path $Python)) {
    # 退回到 PATH 里的 pythonw
    $Python = (Get-Command pythonw.exe -ErrorAction SilentlyContinue).Source
    if (-not $Python) { throw 'pythonw.exe not found' }
}

$sh = New-Object -ComObject WScript.Shell
$s = $sh.CreateShortcut($lnk)
$s.TargetPath = $Python
$s.Arguments = '"{0}"' -f (Join-Path $repo 'tools\boxbench_gui.py')
$s.WorkingDirectory = $repo
if (-not $NoIcon) {
    $ico = Join-Path $repo 'tools\boxbench.ico'
    if (Test-Path $ico) { $s.IconLocation = "$ico,0" }
}
$s.Description = 'MagicBox 台架工具 boxbench（控制口 GUI：状态/轨迹/事件/测试）'
$s.WindowStyle = 1
$s.Save()

Write-Host "已创建: $lnk"
Write-Host "  目标: $($sh.CreateShortcut($lnk).TargetPath)"
Write-Host "  参数: $($sh.CreateShortcut($lnk).Arguments)"
Write-Host "  目录: $($s.WorkingDirectory)"
Write-Host ''
Write-Host '提示：双击前先关掉已开着的 boxbench 窗口（串口独占），'
Write-Host '      GUI 闪退时用 tools\boxbench.cmd 启动可看到报错。'
