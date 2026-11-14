idf_component_register(
    SRCS "src/makcu_hiddev.c" "src/usb_descriptors.c"
    INCLUDE_DIRS "include"
    REQUIRES espressif__tinyusb makcu_mouse makcu_clone usb esp_timer
    WHOLE_ARCHIVE
)
