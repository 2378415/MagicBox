p="app_left/main/CMakeLists.txt"
t=open(p,encoding="utf-8").read()
if "esp_driver_usb_serial_jtag" not in t:
    t=t.replace("esp_driver_uart","esp_driver_uart esp_driver_usb_serial_jtag")
open(p,"w",encoding="utf-8").write(t)
print(t)
