idf_component_register(
    SRCS "src/makcu_mouse.c" "src/makcu_mouse_stub.c"
    INCLUDE_DIRS "include"
    REQUIRES makcu_proto makcu_dev esp_timer
)
