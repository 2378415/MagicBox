idf_component_register(SRCS "app_main.c"
                       INCLUDE_DIRS "."
                       REQUIRES makcu_link makcu_right makcu_proto makcu_hidhost
                                esp_driver_uart usb nvs_flash)

