import os
p = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), '官方固件逆向分析报告.md')
t = open(p, encoding='utf-8').read()

t = t.replace('### 12.9 语义命名（题 73 个函数）', '### 12.9 语义命名（落地 56 个函数）')

old2 = '''| 类别 | 数量 | 示例 |
|---|---:|---|
| 协议 | 33 | `cmd_lookup`、`cmd_dispatch`、`cmd_move`、`cmd_wheel`、`cmd_buttons`、`cmd_key_down`… |
| 键盘 | 14 | `hid_key_down`、`hid_key_up`、`hid_key_tap`、`hid_type_string`、`hid_keys_combo`… |
| 鼠标 | 10 | `mouse_commit_init`、`mouse_commit_task`、`bezier_timer_cb`、`mouse_submit`、`wheel_submit`… |
| 串口 | 5 | `uart0_setup`、`uart0_frame_consumer`、`uart0_send_task`、`uart0_reply`、`serial_setup` |
| 其它 | 11 | `led_init`、`efuse_burn`、`crash_dump`、`parse_list6`、`map_entry_write`… |'''
new2 = '''| 类别 | 数量 | 示例 |
|---|---:|---|
| 协议 | 33 | `cmd_lookup`、`cmd_dispatch`、`cmd_move`、`cmd_wheel`、`cmd_buttons`、`cmd_key_down`… |
| 键盘 | 9 | `hid_key_down`、`hid_key_up`、`hid_key_tap`、`hid_type_string`、`hid_keys_combo`… |
| 鼠标 | 9 | `mouse_commit_init`、`mouse_submit`、`wheel_submit`、`mouse_move`… |
| 串口 | 5 | `uart0_setup`、`uart0_frame_consumer`、`uart0_reply`、`serial_setup`… |'''
t = t.replace(old2, new2)

old3 = '命名同时写入 Ghidra 工程：LEFT `RENAMED=66`、RIGHT `RENAMED=4`（少数地址不在函数入口，明细见 `reversed/docs/renames.md`）。'
new3 = ('命名同时写入 Ghidra 工程：LEFT `RENAMED=56`（过程中先回滚了 17 个误改的“包含字符串地址的函数”，'
        '再按最终表重命名）。这 17 个候选地址是字符串/数据引用点而非函数入口，已在 `reversed/docs/renames.md` 单列。')
t = t.replace(old3, new3)

open(p, 'w', encoding='utf-8').write(t)
print('updated')
