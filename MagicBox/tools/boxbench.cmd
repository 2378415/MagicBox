@echo off
rem boxbench 台架工具 - 带控制台的启动方式（排障用：能看到 Python 报错）
rem 桌面快捷方式走的是 pythonw（无控制台）。GUI 闪退时用这个看原因。
cd /d "%~dp0.."
python "%~dp0boxbench_gui.py" %*
if errorlevel 1 pause
