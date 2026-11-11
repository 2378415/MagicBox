p="app_left/main/CMakeLists.txt"
t=open(p,encoding="utf-8").read()
t=t.replace("REQUIRES makcu_proto makcu_dev makcu_mouse makcu_keyboard makcu_hiddev makcu_board",
            "REQUIRES makcu_proto makcu_dev makcu_mouse makcu_keyboard makcu_hiddev makcu_link makcu_board")
open(p,"w",encoding="utf-8").write(t)
print("REQUIRES updated")
