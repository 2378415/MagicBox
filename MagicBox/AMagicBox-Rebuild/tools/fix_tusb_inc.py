p="app_left/main/CMakeLists.txt"
t=open(p,encoding="utf-8").read()
if "tusb_lib" not in t:
    t += '''
# TinyUSB compiles its own sources and needs tusb_config.h on its include path;
# the component that owns that header is makcu_hiddev.
idf_component_get_property(tusb_lib espressif__tinyusb COMPONENT_LIB)
if(tusb_lib)
    target_include_directories(${tusb_lib} PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/../../components/makcu_hiddev/include")
endif()
'''
    open(p,"w",encoding="utf-8").write(t)
print(open(p).read())
