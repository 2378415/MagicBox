p="components/makcu_proto/include/makcu_mouse_hooks.h"
t=open(p,encoding="utf-8").read()
if "makcu_mouse_pulse_fn" not in t:
    t=t.replace("typedef int (*makcu_mouse_move_ext_fn)(void *dev, int16_t v0, int16_t v1,\n                                       int16_t v2, int16_t v3, int16_t v4);",
"""typedef int (*makcu_mouse_move_ext_fn)(void *dev, int16_t v0, int16_t v1,
                                       int16_t v2, int16_t v3, int16_t v4);

/* 0x42010D3C pulse_move: move, wait for the commit semaphore, move back. */
typedef int (*makcu_mouse_pulse_fn)(void *dev, int16_t dx, int16_t dy);""")
    t=t.replace("extern makcu_mouse_move_ext_fn makcu_mouse_move_ext_hook;",
"""extern makcu_mouse_move_ext_fn makcu_mouse_move_ext_hook;
extern makcu_mouse_pulse_fn    makcu_mouse_pulse_hook;""")
    open(p,"w",encoding="utf-8").write(t)
p="components/makcu_proto/src/makcu_mouse_hooks.c"
t=open(p,encoding="utf-8").read()
if "makcu_mouse_pulse_hook" not in t:
    t=t.replace("makcu_mouse_move_ext_fn makcu_mouse_move_ext_hook;",
"makcu_mouse_move_ext_fn makcu_mouse_move_ext_hook;\nmakcu_mouse_pulse_fn    makcu_mouse_pulse_hook;")
    open(p,"w",encoding="utf-8").write(t)
print("pulse hook added")
