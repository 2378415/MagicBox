idf_component_register(
    SRCS "src/makcu_hidhost.c"
    INCLUDE_DIRS "include"
    REQUIRES makcu_proto makcu_link esp_timer freertos usb
)
