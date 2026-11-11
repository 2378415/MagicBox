p="tools/build_app.ps1"
t=open(p,encoding="utf-8").read()
# -Define used to receive a single comma-joined string when the wrapper is called
# through `powershell -File`, which silently produced a broken CMake cache entry
# ("MB_DEBUG_OPCODE:BOOL=ON,-DMB_HID_DEVICE=OFF").  Split it back into arguments.
t=t.replace("    [string[]]$Define = @()","    [string]$Define = ''")
t=t.replace("""    if ($Define.Count -gt 0) {
        & $python $idfPy @Define $Action
    } else {
        & $python $idfPy $Action
    }""","""    $defs = @()
    if ($Define) {
        $defs = @($Define -split ',' | Where-Object { $_ -ne '' })
    }
    if ($defs.Count -gt 0) {
        & $python $idfPy @defs $Action
    } else {
        & $python $idfPy $Action
    }""")
open(p,"w",encoding="utf-8").write(t)
print("build_app.ps1 define handling fixed")
