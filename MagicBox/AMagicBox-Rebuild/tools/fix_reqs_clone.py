p="components/makcu_hiddev/CMakeLists.txt"
t=open(p,encoding="utf-8").read().replace("REQUIRES espressif__tinyusb makcu_mouse usb","REQUIRES espressif__tinyusb makcu_mouse makcu_clone usb")
open(p,"w",encoding="utf-8").write(t)
p="app_left/main/CMakeLists.txt"
t=open(p,encoding="utf-8").read().replace("REQUIRES makcu_proto makcu_dev makcu_mouse makcu_keyboard makcu_hiddev makcu_link makcu_board",
    "REQUIRES makcu_proto makcu_dev makcu_mouse makcu_keyboard makcu_hiddev makcu_clone makcu_link makcu_board")
open(p,"w",encoding="utf-8").write(t)
print("REQUIRES updated for clone")
