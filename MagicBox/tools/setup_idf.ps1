# setup_idf.ps1 - reproduce the build environment for the MAKCU rebuild.
#
# Target state (docs/00-facts.md):
#   ESP-IDF  v5.4.1        at D:\esp-idf
#   toolchain xtensa-esp-elf (the image was built with 14.2.0_20241119)
#
# Steps, in order.  Each step is idempotent; re-run the whole script after a
# network hiccup.
#
#   pwsh -File tools\setup_idf.ps1                 # full run
#   pwsh -File tools\setup_idf.ps1 -SubmodulesOnly # only finish the submodules
#
param(
    [string]$IdfPath = 'D:\esp-idf',
    [string]$ToolsPath = 'D:\esp-tools',
    [string]$Mirror = 'https://gitee.com/EspressifSystems',
    [switch]$SubmodulesOnly,
    [switch]$UseMirror
)

$ErrorActionPreference = 'Stop'
function Step($msg) { Write-Host "== $msg" -ForegroundColor Cyan }

# ---------------------------------------------------------------- 1. sources
if (-not (Test-Path $IdfPath)) {
    Step "clone esp-idf v5.4.1 -> $IdfPath"
    git clone --depth 1 --branch v5.4.1 https://github.com/espressif/esp-idf.git $IdfPath
}

Step "fetch submodules (retry 3x, then optional gitee mirror)"
Push-Location $IdfPath
try {
    for ($i = 1; $i -le 3; $i++) {
        git submodule update --init --recursive --depth 1 2>&1 | Out-Host
        $missing = git submodule status | Where-Object { $_ -match '^-' }
        if (-not $missing) { break }
        Write-Host "retry $i, still missing:" ($missing -join ', ')
        Start-Sleep -Seconds 5
    }

    $missing = git submodule status | Where-Object { $_ -match '^-' }
    if ($missing -and $UseMirror) {
        Step "switching submodule remotes to $Mirror"
        foreach ($line in $missing) {
            $path = ($line -split ' ')[2]
            $name = (Split-Path $path -Leaf)
            try {
                git config submodule.$path.url "$Mirror/$name.git"
                git submodule update --init --depth 1 $path
            } catch {
                Write-Warning "mirror failed for $path : $($_.Exception.Message)"
            }
        }
    }

    $missing = git submodule status | Where-Object { $_ -match '^-' }
    if ($missing) {
        Write-Warning "still missing: $($missing -join ', ')"
        Write-Warning "Neither app requires mbedtls/openthread/unity, so the build may still work."
    }
} finally {
    Pop-Location
}

if ($SubmodulesOnly) { return }

# ---------------------------------------------------------------- 2. tools
Step "install the minimal toolset (xtensa-esp-elf + python deps) into $ToolsPath"
$env:IDF_TOOLS_PATH = $ToolsPath
python "$IdfPath\tools\idf_tools.py" install xtensa-esp-elf
python "$IdfPath\tools\idf_tools.py" install python

# The host already has 14.2.0 at D:\Apply\toolchains\xtensa-esp-elf; if you want
# to reuse it instead of downloading, point IDF_TOOLS_PATH at a directory whose
# tools/xtensa-esp-elf/esp-14.2.0_20241119 layout links to it.

# ---------------------------------------------------------------- 3. build
Step "export environment and build both apps"
. "$IdfPath\export.ps1"

foreach ($app in 'app_left', 'app_right') {
    Step "idf.py build in $app"
    Push-Location (Join-Path $PSScriptRoot "..\$app")
    try {
        idf.py set-target esp32s3 | Out-Host
        idf.py build | Out-Host
    } finally {
        Pop-Location
    }
}

# ---------------------------------------------------------------- 4. baseline
Step "P0 gate: compare rebuilt IDF functions against the official image"
python "$PSScriptRoot\lib_fingerprint.py" index --old-repo 'D:\JinPeng\MagicBox'
python "$PSScriptRoot\lib_fingerprint.py" compare `
    --firmware "$PSScriptRoot\..\verification\fingerprints\left.json" `
    --map (Join-Path $PSScriptRoot "..\app_left\build\makcu_left.map") `
    --min-hit 0.95

Write-Host @"
Next:
  - gate PASS -> start porting (docs/10-abi.md): proto -> link -> mouse -> keyboard -> hid
  - gate FAIL -> tune sdkconfig.defaults (FREERTOS_HZ, log level, heap options) and retry
"@ -ForegroundColor Green
