idf_component_register(
    SRCS "src/makcu_link.c" "src/makcu_link_bridge.c"
    INCLUDE_DIRS "include"
    REQUIRES esp_driver_uart
)
