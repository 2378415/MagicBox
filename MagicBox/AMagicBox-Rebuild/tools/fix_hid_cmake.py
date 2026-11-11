p="components/makcu_hiddev/CMakeLists.txt"
t=open(p,encoding="utf-8").read().replace("REQUIRES espressif__tinyusb makcu_mouse","REQUIRES espressif__tinyusb makcu_mouse usb")
open(p,"w",encoding="utf-8").write(t)
print(t)
