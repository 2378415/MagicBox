<#
.SYNOPSIS
    清理 MagicBox 仓库中不属于源码/文档的文件（构建产物、第三方工具链、临时脚本、重复大文件）。

.DESCRIPTION
    本仓库是 D:\JinPeng\MagicBox 与 D:\JinPeng\MagicBullet 的发布副本（除 .git 外逐字节一致），
    因此这里的一切删除都可由 origin 目录复制回来，见 -RestoreHint 输出。

    分类：
      build   构建产物 / 缓存，构建时可再生
      vendor  第三方工具链、安装包、预编译包
      scratch 一次性脚本、日志、抓包、中间转储
      dup     与别处重复的大文件
      junk    空壳 / 404 占位 / 未参与编译的死文件

.EXAMPLE
    pwsh -File scripts\clean-repo.ps1              # 预演（默认，不删）
    pwsh -File scripts\clean-repo.ps1 -Apply       # 真正删除
    pwsh -File scripts\clean-repo.ps1 -Apply -Only build,vendor
#>
[CmdletBinding()]
param(
    [switch]$Apply,
    [string[]]$Only = @('build', 'vendor', 'scratch', 'dup', 'junk')
)

$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot

$targets = @(
    # ---- build：构建产物 / 缓存 -------------------------------------------------
    @{ Cat = 'build'; Path = 'MagicBullet\.gradle' }
    @{ Cat = 'build'; Path = 'MagicBullet\build' }
    @{ Cat = 'build'; Path = 'MagicBullet\app\build' }
    @{ Cat = 'build'; Path = 'MagicBullet\app\.cxx' }
    @{ Cat = 'build'; Path = 'MagicBullet\libuvc\build' }
    @{ Cat = 'build'; Path = 'MagicBox\AMagicBox-Rebuild\app_left\build' }
    @{ Cat = 'build'; Path = 'MagicBox\AMagicBox-Rebuild\app_right\build' }
    @{ Cat = 'build'; Path = 'MagicBox\AMagicBox-Rebuild\managed_components' }
    @{ Cat = 'build'; Path = 'MagicBox\AMagicBox-Rebuild\app_left\managed_components' }
    @{ Cat = 'build'; Path = 'MagicBox\AMagicBox-Rebuild\app_right\managed_components' }
    @{ Cat = 'build'; Path = 'MagicBox\AMagicBox-Rebuild\.pytest_cache' }
    @{ Cat = 'build'; Path = 'MagicBox\AMagicBox-Rebuild\btn_trace.log' }
    @{ Cat = 'build'; Path = 'MagicBox\AMagicBox-Rebuild\work' }

    # ---- vendor：第三方工具链 / 安装包 / 未引用的预编译包 ------------------------
    @{ Cat = 'vendor'; Path = 'MagicBox\tools\rizin' }
    @{ Cat = 'vendor'; Path = 'MagicBox\tools\rizin-static.zip' }
    @{ Cat = 'vendor'; Path = 'MagicBox\官方固件\烧录工具1_7.exe' }
    @{ Cat = 'vendor'; Path = 'MagicBullet\libuvc\aar' }

    # ---- scratch：一次性脚本 / 日志 / 抓包 / 中间转储 ---------------------------
    @{ Cat = 'scratch'; Path = 'MagicBox\work' }
    @{ Cat = 'scratch'; Path = 'MagicBox\ghidra-projects' }
    @{ Cat = 'scratch'; Path = 'MagicBullet\.research' }
    @{ Cat = 'scratch'; Path = 'MagicBullet\extract_pdf.py' }

    # ---- dup：与别处重复的大文件 ------------------------------------------------
    @{ Cat = 'dup'; Path = 'MagicBullet\models\venv-tflite' }
    @{ Cat = 'dup'; Path = 'MagicBullet\models\ort-aar' }
    @{ Cat = 'dup'; Path = 'MagicBullet\models\qnn-aar' }
    @{ Cat = 'dup'; Path = 'MagicBullet\models\aar' }
    @{ Cat = 'dup'; Path = 'MagicBullet\models\calib' }
    @{ Cat = 'dup'; Path = 'MagicBullet\models\yolov8n.pt' }
    @{ Cat = 'dup'; Path = 'MagicBullet\models\yolov8n.onnx' }
    @{ Cat = 'dup'; Path = 'MagicBullet\models\yolov8n_int8_qdq.onnx' }
    @{ Cat = 'dup'; Path = 'MagicBullet\模型' }

    # ---- junk：空壳 / 占位 / 死文件 ---------------------------------------------
    @{ Cat = 'junk'; Path = 'MagicBox\rea-docs' }
)

function Get-TreeStat([string]$p) {
    if (Test-Path -LiteralPath $p -PathType Leaf) {
        $i = Get-Item -LiteralPath $p
        return @{ Files = 1; Bytes = $i.Length }
    }
    if (-not (Test-Path -LiteralPath $p -PathType Container)) { return $null }
    $f = Get-ChildItem -LiteralPath $p -Recurse -Force -File -ErrorAction SilentlyContinue
    return @{ Files = $f.Count; Bytes = ($f | Measure-Object Length -Sum).Sum }
}

# __pycache__ / *.pyc：全仓库范围
$pycacheDirs = Get-ChildItem -LiteralPath $root -Recurse -Force -Directory -Filter __pycache__ -ErrorAction SilentlyContinue |
    Where-Object { $_.FullName -notmatch '\\\.git\\' }

$plan = @()
foreach ($t in $targets) {
    if ($Only -notcontains $t.Cat) { continue }
    $full = Join-Path $root $t.Path
    $stat = Get-TreeStat $full
    if ($null -eq $stat) { continue }
    $plan += [pscustomobject]@{ Cat = $t.Cat; Path = $t.Path; Files = $stat.Files; MB = [math]::Round($stat.Bytes / 1MB, 1) }
}
if ($Only -contains 'build') {
    foreach ($d in $pycacheDirs) {
        $stat = Get-TreeStat $d.FullName
        if ($null -eq $stat) { continue }
        $plan += [pscustomobject]@{ Cat = 'build'; Path = $d.FullName.Substring($root.Length + 1); Files = $stat.Files; MB = [math]::Round($stat.Bytes / 1MB, 1) }
    }
}

$plan | Sort-Object -Property @{ Expression = 'MB'; Descending = $true } |
    Format-Table -AutoSize Cat, MB, Files, Path

$totalMB = [math]::Round((($plan | Measure-Object MB -Sum).Sum), 1)
$totalFiles = ($plan | Measure-Object Files -Sum).Sum
$before = (Get-ChildItem -LiteralPath $root -Recurse -Force -File | Where-Object { $_.FullName -notmatch '\\\.git\\' } | Measure-Object Length -Sum)
Write-Host ("目标 {0} 项 / {1} 个文件 / {2} MB" -f $plan.Count, $totalFiles, $totalMB) -ForegroundColor Cyan
Write-Host ("仓库当前 {0} 个文件 / {1} MB" -f $before.Count, [math]::Round($before.Sum / 1MB, 1)) -ForegroundColor Cyan

if (-not $Apply) {
    Write-Host '预演模式（未删除）。加 -Apply 执行。' -ForegroundColor Yellow
    return
}

foreach ($p in ($plan | Sort-Object Path)) {
    $full = Join-Path $root $p.Path
    if (Test-Path -LiteralPath $full) { Remove-Item -LiteralPath $full -Recurse -Force }
}

$after = (Get-ChildItem -LiteralPath $root -Recurse -Force -File | Where-Object { $_.FullName -notmatch '\\\.git\\' } | Measure-Object Length -Sum)
Write-Host ("已删除。仓库现在 {0} 个文件 / {1} MB（释放 {2} MB）" -f $after.Count, [math]::Round($after.Sum / 1MB, 1), [math]::Round(($before.Sum - $after.Sum) / 1MB, 1)) -ForegroundColor Green
Write-Host '回滚：从 D:\JinPeng\MagicBox 与 D:\JinPeng\MagicBullet 复制对应目录回来即可（两边除 .git 外内容一致）。' -ForegroundColor DarkGray
