# build_app.ps1 - reproducible build wrapper (P0).
#
# Why a wrapper: this machine has a hand-assembled IDF environment (no
# idf_tools-installed toolchain, CMake/Ninja from pip, pruned submodules), so the
# env vars matter.  Run this instead of calling idf.py directly.
#
#   pwsh -File tools\build_app.ps1 -App app_left
#   pwsh -File tools\build_app.ps1 -App app_right -Clean
#
param(
    [Parameter(Mandatory = $true)][ValidateSet('app_left', 'app_right')][string]$App,
    [switch]$Clean,
    [string]$Action = 'build',
    [string]$Define = ''
)

$ErrorActionPreference = 'Stop'
$proj = Split-Path -Parent $PSScriptRoot

$env:IDF_PATH = 'D:\esp-idf'
$env:IDF_TOOLS_PATH = 'D:\esp-tools'
$env:ESP_IDF_VERSION = '5.4.1'
$env:IDF_PYTHON_ENV_PATH = 'D:\esp-tools\python_env\idf5.4_py3.11_env'
# esp-rom-elfs is not installed (github release download is blocked here); point
# it at the in-tree ROM descriptions so gdbinit generation stays happy.
$env:ESP_ROM_ELF_DIR = 'D:\esp-idf\components\esp_rom\esp32s3'
# The IDF cmake layer re-runs `git submodule update --init` for every '-'-status
# submodule at configure time, and this network cannot clone them (github:443 and
# the gitee mirror both time out; the sources were populated via codeload tarballs
# + tools/fix_idf_gitmodules.py).  Without this the first reconfigure after any
# .gitmodules/HEAD change fails before compiling anything.
$env:IDF_SKIP_CHECK_SUBMODULES = '1'
$env:PATH = @(
    'D:\esp-tools\tools\xtensa-esp-elf\esp-14.2.0_20241119\xtensa-esp-elf\bin',
    'D:\esp-tools\python_env\idf5.4_py3.11_env\Scripts',
    'D:\Apply\Python311\Scripts',
    $env:PATH
) -join ';'

$python = Join-Path $env:IDF_PYTHON_ENV_PATH 'Scripts\python.exe'
$idfPy = Join-Path $env:IDF_PATH 'tools\idf.py'

Push-Location (Join-Path $proj $App)
try {
    if ($Clean -and (Test-Path build)) { Remove-Item -Recurse -Force build }
    $defs = @()
    if ($Define) {
        $defs = @($Define -split ',' | Where-Object { $_ -ne '' })
    }
    if ($defs.Count -gt 0) {
        & $python $idfPy @defs $Action
    } else {
        & $python $idfPy $Action
    }
    exit $LASTEXITCODE
} finally {
    Pop-Location
}
