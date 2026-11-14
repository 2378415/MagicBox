idf_component_register(
    SRCS "src/mouse_vendor.c" "src/g3mpro.c" "src/vendor_chan.c"
    INCLUDE_DIRS "include"
    REQUIRES makcu_link esp_timer
)
