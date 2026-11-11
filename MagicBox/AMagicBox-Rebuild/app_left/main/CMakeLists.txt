if(MB_DEBUG_OPCODE)
    add_compile_definitions(MB_DEBUG_OPCODE=1)
endif()
if(MB_HID_DEVICE)
    add_compile_definitions(MB_HID_DEVICE=1)
endif()
if(MB_TUSB_DEBUG)
    add_compile_definitions(MB_TUSB_DEBUG=${MB_TUSB_DEBUG})
endif()
if(MB_CLONE_FIXTURE)
    add_compile_definitions(MB_CLONE_FIXTURE=${MB_CLONE_FIXTURE})
endif()
if(MB_DUAL_IF)
    add_compile_definitions(MB_DUAL_IF=1)
endif()
if(MB_FORCE_VIDPID)
    message(WARNING "MB_FORCE_VIDPID is deprecated: the identity alias policy maps "
                    "the receiver id families automatically; build without it.")
    string(SUBSTRING "${MB_FORCE_VIDPID}" 0 4 MB_FORCE_VID)
    string(SUBSTRING "${MB_FORCE_VIDPID}" 4 4 MB_FORCE_PID)
    add_compile_definitions(MB_FORCE_VID=0x${MB_FORCE_VID} MB_FORCE_PID=0x${MB_FORCE_PID})
    # add_compile_definitions() is directory-scoped, so the component that actually
    # patches the descriptor needs the values explicitly.
    idf_component_get_property(clone_lib makcu_clone COMPONENT_LIB)
    if(clone_lib)
        target_compile_definitions(${clone_lib} PRIVATE
            MB_FORCE_VID=0x${MB_FORCE_VID} MB_FORCE_PID=0x${MB_FORCE_PID})
    endif()
endif()

idf_component_register(SRCS "app_main.c" "control_bin.c" "btn_evt.c" "btn_trace.c"
                       INCLUDE_DIRS "."
                       REQUIRES makcu_proto makcu_dev makcu_mouse makcu_sumv makcu_keyboard makcu_hiddev makcu_clone makcu_link makcu_right makcu_board
                                esp_driver_uart esp_driver_usb_serial_jtag nvs_flash esp_timer)

# TinyUSB compiles its own sources and needs tusb_config.h on its include path;
# the component that owns that header is makcu_hiddev.
# MB_DEBUG_OPCODE is added with add_compile_definitions(), which is directory
# scoped: components do not see it.  makcu_link gates its report reassembly on it
# (bench-only work on the 1 kHz path), so forward it explicitly.
if(MB_DEBUG_OPCODE)
    idf_component_get_property(link_lib makcu_link COMPONENT_LIB)
    if(link_lib)
        target_compile_definitions(${link_lib} PRIVATE MB_DEBUG_OPCODE=1)
    endif()
endif()

idf_component_get_property(tusb_lib espressif__tinyusb COMPONENT_LIB)
if(tusb_lib)
    target_include_directories(${tusb_lib} PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/../../components/makcu_hiddev/include")
    # The debug level has to reach the TinyUSB sources themselves: add_compile_
    # definitions() above is directory-scoped to `main`, so without this the
    # library stayed at CFG_TUSB_DEBUG=0 and -DMB_TUSB_DEBUG did nothing.
    if(MB_TUSB_DEBUG)
        target_compile_definitions(${tusb_lib} PRIVATE MB_TUSB_DEBUG=${MB_TUSB_DEBUG})
    endif()
endif()

idf_component_get_property(hiddev_lib makcu_hiddev COMPONENT_LIB)
if(hiddev_lib AND MB_TUSB_DEBUG)
    target_compile_definitions(${hiddev_lib} PRIVATE MB_TUSB_DEBUG=${MB_TUSB_DEBUG})
endif()

# MB_DUAL_IF changes CFG_TUD_HID (tusb_config.h lives in makcu_hiddev) and the
# descriptor callbacks, so it has to reach the component *and* TinyUSB itself -
# add_compile_definitions() above only applies to the `main` directory.
if(MB_DUAL_IF)
    if(hiddev_lib)
        target_compile_definitions(${hiddev_lib} PRIVATE MB_DUAL_IF=1)
    endif()
    if(tusb_lib)
        target_compile_definitions(${tusb_lib} PRIVATE MB_DUAL_IF=1)
    endif()
endif()
