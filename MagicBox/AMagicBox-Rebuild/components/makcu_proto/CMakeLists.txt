idf_component_register(
    SRCS "src/cmd_button_click.c" "src/cmd_button_press.c" "src/cmd_buttons.c" "src/cmd_catch_query.c" "src/cmd_catch_set.c" "src/cmd_channel.c" "src/cmd_keyboard.c" "src/cmd_lock.c" "src/cmd_map.c" "src/cmd_move.c" "src/cmd_nop.c" "src/cmd_serial.c" "src/cmd_silent.c" "src/cmd_sumv.c" "src/cmd_evt.c" "src/cmd_version.c" "src/cmd_wheel.c" "src/makcu_cmd_table.c" "src/makcu_kbd_hooks.c" "src/makcu_lookup.c" "src/makcu_mouse_hooks.c" "src/makcu_opcode_table.c" "src/makcu_parse.c" "src/makcu_parse_kbd.c" "src/makcu_reply.c" "src/makcu_serial_hooks.c" "src/makcu_sumv_hooks.c" "src/makcu_evt_hooks.c" "src/makcu_status.c" "src/makcu_usage.c"
    INCLUDE_DIRS "include"
    REQUIRES makcu_dev
)
