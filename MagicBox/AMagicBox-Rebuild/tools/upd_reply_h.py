p="components/makcu_proto/include/makcu_reply.h"
t=open(p,encoding="utf-8").read()
if "makcu_reply_status" not in t:
    t=t.replace("size_t makcu_reply_echo(const char *buf, int len);",
"""size_t makcu_reply_echo(const char *buf, int len);

/* Reply "<name>\\n<digit>" - cmd_reply_status (0x4200DC18).  The buttons family
 * is normalised to "buttons()" exactly like the original. */
size_t makcu_reply_status(const char *name, int name_len, uint8_t status);""")
    t=t.replace("#include <stddef.h>","#include <stddef.h>\n#include <stdint.h>")
    open(p,"w",encoding="utf-8").write(t)
print(open(p).read()[-500:])
