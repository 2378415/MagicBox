p="tools/build_app.ps1"
t=open(p,encoding="utf-8").read()
if "[string[]]$Define" not in t:
    t=t.replace("    [switch]$Clean,\n    [string]$Action = 'build'","    [switch]$Clean,\n    [string]$Action = 'build',\n    [string[]]$Define = @()")
    t=t.replace("    & $python $idfPy $Action","    if ($Define.Count -gt 0) {\n        & $python $idfPy @Define $Action\n    } else {\n        & $python $idfPy $Action\n    }")
    open(p,"w",encoding="utf-8").write(t)

p="tools/run_bench_cycle.ps1"
t=open(p,encoding="utf-8").read()
t=t.replace("""        & powershell -NoProfile -ExecutionPolicy Bypass -File (Join-Path $proj 'tools\\build_app.ps1') `
            -App app_left -Clean -Action "-DMB_DEBUG_OPCODE=ON -DMB_HID_DEVICE=$hid build\"""","""        & powershell -NoProfile -ExecutionPolicy Bypass -File (Join-Path $proj 'tools\\build_app.ps1') `
            -App app_left -Clean -Define "-DMB_DEBUG_OPCODE=ON","-DMB_HID_DEVICE=$hid\"""")
open(p,"w",encoding="utf-8").write(t)
print("patched build wrapper")
