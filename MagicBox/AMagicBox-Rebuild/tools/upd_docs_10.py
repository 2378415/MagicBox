import io,sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
p="tools/finish_cycle.ps1"
t=open(p,encoding="utf-8").read()
if "$pySys" not in t:
    t=t.replace("$py = 'D:\\esp-tools\\python_env\\idf5.4_py3.11_env\\Scripts\\python.exe'",
"$py = 'D:\\esp-tools\\python_env\\idf5.4_py3.11_env\\Scripts\\python.exe'   # esptool\n$pySys = 'D:\\Apply\\Python311\\python.exe'                                # pytest")
    t=t.replace("    & $py -m pytest verification\\regress verification\\model -q 2>&1 |",
"    & $pySys -m pytest verification\\regress verification\\model -q 2>&1 |")
    open(p,"w",encoding="utf-8").write(t)

# status
p="tools/status.py"
t=open(p,encoding="utf-8").read()
t=t.replace("'| 烧录 + 回归（T2） | 已上机 9 次；最新一轮 **61 例全绿**（60 passed + 1 xpassed：协议 52 + 分步轨迹 4 + 离线模型 5）；回滚新鲜回读 sha256 一致 | `verification/report/` |',",
"'| 烧录 + 回归（T2） | 已上机 10 次；最新一轮 **68 例全绿**（67 passed + 1 xpassed：协议/报告 54 + 曲线 2 + 离线模型 12）；回滚新鲜回读 sha256 一致 | `verification/report/` |',")
t=t.replace("'| 副作用层（P4 运动） | **队列 + 分步引擎完成**：按 int8 上限分步、最大余数法守恒、步间 `vTaskDelay(1)`、`mx.rq` 可读回整串轨迹；Bezier 的旋转/缓动数学仍未移植 | `components/makcu_mouse/` |',",
"'| 副作用层（P4 运动） | **队列 + 分步 + 曲线完成**：int8 分步、贝塞尔弯曲（±span/8 随机偏移）、残差摊分守恒、`mx.rq` 可读回整串轨迹；与原函数的差别是数值而非形状 | `components/makcu_mouse/` |',")
open(p,"w",encoding="utf-8").write(t)
print("docs updated")
