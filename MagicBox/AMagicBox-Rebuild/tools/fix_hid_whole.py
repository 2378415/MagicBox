p="components/makcu_hiddev/CMakeLists.txt"
t='''idf_component_register(
    SRCS "src/makcu_hiddev.c" "src/usb_descriptors.c"
    INCLUDE_DIRS "include"
    REQUIRES espressif__tinyusb makcu_mouse usb
    WHOLE_ARCHIVE
)
'''
open(p,"w",encoding="utf-8").write(t)
print(t)
