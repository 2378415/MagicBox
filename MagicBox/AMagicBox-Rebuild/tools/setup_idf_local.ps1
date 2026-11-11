# setup_idf_local.ps1 - install the build environment on a machine where the
# paths from docs (D:\esp-idf, D:\esp-tools) do not exist yet.
#
# Difference from setup_idf.ps1: github.com:443 is blocked here, so the IDF tree
# comes from the gitee mirror and the xtensa toolchain from dl.espressif.com
# (github_assets proxy).  Everything is idempotent: re-run after a network hiccup.
#
#   pwsh -File tools\setup_idf_local.ps1
#   pwsh -File tools\setup_idf_local.ps1 -SkipToolchain    # sources only
param(
    [string]$IdfPath   = 'D:\esp-idf',
    [string]$ToolsPath = 'D:\esp-tools',
    [string]$IdfTag    = 'v5.4.1',
    [string]$ToolchainUrl = 'https://dl.espressif.com/github_assets/espressif/crosstool-NG/releases/download/esp-14.2.0_20241119/xtensa-esp-elf-14.2.0_20241119-x86_64-w64-mingw32.zip',
    [switch]$SkipToolchain,
    [switch]$SkipSubmodules
)

$ErrorActionPreference = 'Stop'
function Step($m) { Write-Host "== $m" -ForegroundColor Cyan }
$py = 'D:\Apply\Python311\python.exe'

# ------------------------------------------------------------------ 1. host bits
Step 'pip: cmake<4 / ninja / idf-component-manager'
& $py -m pip install --quiet 'cmake<4' ninja idf-component-manager

# ------------------------------------------------------------------ 2. IDF tree
if (-not (Test-Path (Join-Path $IdfPath 'tools\idf.py'))) {
    Step "clone esp-idf $IdfTag from gitee -> $IdfPath"
    git clone --depth 1 --branch $IdfTag https://gitee.com/EspressifSystems/esp-idf.git $IdfPath
} else {
    Step "esp-idf already present at $IdfPath"
}

# --------------------------------------------------------------- 3. submodules
if (-not $SkipSubmodules) {
    Step 'submodules (gitee mirror; retry 3x)'
    Push-Location $IdfPath
    try {
        for ($i = 1; $i -le 3; $i++) {
            git submodule update --init --depth 1 --recursive 2>&1 | Out-Host
            $missing = git submodule status | Where-Object { $_ -match '^-' }
            if (-not $missing) { break }
            Write-Warning "retry $i, still missing: $($missing.Count)"
            Start-Sleep -Seconds 5
        }
        $missing = git submodule status | Where-Object { $_ -match '^-' }
        if ($missing) { Write-Warning "still missing $($missing.Count) submodules:`n$($missing -join "`n")" }
    } finally { Pop-Location }
}

# --------------------------------------------------------------- 4. toolchain
$tcRoot = Join-Path $ToolsPath 'tools\xtensa-esp-elf\esp-14.2.0_20241119'
$gcc    = Join-Path $tcRoot 'xtensa-esp-elf\bin\xtensa-esp-elf-gcc.exe'
if (-not $SkipToolchain -and -not (Test-Path $gcc)) {
    Step "download xtensa-esp-elf 14.2.0 (~386 MB)"
    $zip = Join-Path $env:TEMP 'xtensa-esp-elf.zip'
    if (-not (Test-Path $zip) -or (Get-Item $zip).Length -lt 300MB) {
        curl.exe -L --retry 3 --retry-delay 5 -o $zip $ToolchainUrl
    }
    Step "extract -> $tcRoot"
    New-Item -ItemType Directory -Force -Path $tcRoot | Out-Null
    Expand-Archive -Path $zip -DestinationPath $tcRoot -Force
} else {
    Step "toolchain already present: $gcc"
}

# ------------------------------------------------------------------ 5. python env
$venv = Join-Path $ToolsPath 'python_env\idf5.4_py3.11_env'
if (-not (Test-Path (Join-Path $venv 'Scripts\python.exe'))) {
    Step "create IDF python env -> $venv"
    & $py -m venv $venv
    $req = Get-ChildItem (Join-Path $IdfPath 'tools\requirements') -Filter 'requirements.core.txt' -ErrorAction SilentlyContinue
    if ($req) {
        & (Join-Path $venv 'Scripts\python.exe') -m pip install --quiet -r $req.FullName
    } else {
        & (Join-Path $venv 'Scripts\python.exe') -m pip install --quiet esptool pyparsing kconfiglib
    }
    & (Join-Path $venv 'Scripts\python.exe') -m pip install --quiet idf-component-manager
} else {
    Step "python env already present: $venv"
}

Step 'done - now run: powershell -File tools\build_app.ps1 -App app_left -Define "-DMB_DEBUG_OPCODE=ON,-DMB_HID_DEVICE=ON,-DMB_CLONE_FIXTURE=1,-DMB_TUSB_DEBUG=3"'
