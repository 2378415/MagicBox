p="app_left/main/app_main.c"
t=open(p,encoding="utf-8").read()
if "makcu_dev.h" not in t:
    t=t.replace('#include "makcu_cmd.h"','#include "makcu_cmd.h"\n#include "makcu_dev.h"')
t=t.replace("    fn(line, len, NULL, entry, line + skip, len - skip);",
            "    fn(line, len, makcu_dev_instance(), entry, line + skip, len - skip);")
if "makcu_dev_reset();" not in t:
    t=t.replace("    makcu_reply_set_writer(control_write);",
                "    makcu_dev_reset();\n    makcu_reply_set_writer(control_write);")
open(p,"w",encoding="utf-8").write(t)
p="app_left/main/CMakeLists.txt"
t=open(p,encoding="utf-8").read()
if "makcu_dev" not in t:
    t=t.replace("REQUIRES makcu_proto","REQUIRES makcu_proto makcu_dev")
open(p,"w",encoding="utf-8").write(t)
print("patched app")
