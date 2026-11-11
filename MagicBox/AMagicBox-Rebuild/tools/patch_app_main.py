path = "app_left/main/app_main.c"
t = open(path, encoding="utf-8").read()

# 1) add the reply writer + strip '.' before "km."
t = t.replace('#include "makcu_cmd.h"\n#include "makcu_reply.h"',
              '#include "makcu_cmd.h"\n#include "makcu_reply.h"')

t = t.replace("""static const char *TAG = "makcu-left";""",
"""static const char *TAG = "makcu-left";

/* uart0_reply equivalent: the reply helpers hand us the finished frame. */
static void control_write(const void *data, size_t len)
{
    uart_write_bytes(CONTROL_UART, data, len);
}""")

# 2) strip "." then "km." in handle_line's caller
t = t.replace("""                const char *p = line;
                int len = (int)used;
                if (len > 3 && memcmp(p, CONTROL_PREFIX, 3) == 0) {
                    p += 3;
                    len -= 3;
                }
                handle_line(p, len);""",
"""                const char *p = line;
                int len = (int)used;
                if (len > 0 && p[0] == CONTROL_TEXT_MARK) {   /* '.' frame marker */
                    p++;
                    len--;
                }
                if (len > 3 && memcmp(p, CONTROL_PREFIX, 3) == 0) {
                    p += 3;                                   /* "km." is re-added on reply */
                    len -= 3;
                }
                handle_line(p, len);""")

t = t.replace('#define CONTROL_PREFIX    "km."',
              '#define CONTROL_PREFIX    "km."\n#define CONTROL_TEXT_MARK \'.\'')

# 3) install the writer at boot
t = t.replace("    report_missing_handlers();",
              "    makcu_reply_set_writer(control_write);\n    report_missing_handlers();")
open(path, "w", encoding="utf-8").write(t)
print("app_main patched")
