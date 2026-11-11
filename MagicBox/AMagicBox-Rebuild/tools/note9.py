import io,sys
sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8",errors="replace")
p="docs/40-status.md"
t=open(p,encoding="utf-8").read()
add = """
## 待上机：分步提交引擎（第九批）

- 已实现：按 int8 上限（127）拆分、最大余数法分配（保证步进之和等于请求值）、
  步间 `vTaskDelay(1)`、16 条报告环形 trace（`mx.rq` 读回）；
- 已离线验证：`verification/model/test_step_engine.py`（5 例，含 127/128/255/5000 边界）；
- **阻塞**：板子当前跑的是原厂固件，原生 USB 的 JTAG-CDC 端口（COM9）枚举但不可用
  （`PermissionError` —— 典型“端口在、数据通路死”），必须手动进下载模式：
  按住 BOOT(IO0) 再插 USB（或按住 BOOT 点一下 RESET）→ 出现可用的 COM 口后即可烧录。
"""
if "第九批" not in t:
    open(p,"a",encoding="utf-8").write(add)
print("status note appended")
