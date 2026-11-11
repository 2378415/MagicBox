p="app_left/main/app_main.c"
t=open(p,encoding="utf-8").read()
if "MB_DEBUG_OPCODE" not in t:
    t=t.replace("""static void handle_line(const char *line, int len)
{""","""#ifndef MB_DEBUG_OPCODE
#define MB_DEBUG_OPCODE 0      /* bench builds pass -DMB_DEBUG_OPCODE=1 */
#endif

#if MB_DEBUG_OPCODE
/* Test harness only: "mx.<hex opcode> <args>" calls a handler directly so the
 * opcodes that have no text command (0x0D..0x18) can be exercised.  A shipped
 * build must leave MB_DEBUG_OPCODE at 0. */
static int hexval(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
}

static int handle_debug_line(const char *line, int len)
{
    if (len < 4 || line[0] != 'm' || line[1] != 'x' || line[2] != '.') {
        return 0;
    }
    const int hi = hexval(line[3]);
    const int lo = (len > 4) ? hexval(line[4]) : 0;
    if (hi < 0 || lo < 0) {
        return 1;
    }
    const unsigned opcode = (unsigned)((hi << 4) | lo);
    if (opcode >= makcu_opcode_count || makcu_opcode_table[opcode] == NULL) {
        return 1;
    }
    int arg_at = 5;
    while (arg_at < len && (line[arg_at] == ' ' || line[arg_at] == ',')) {
        arg_at++;
    }
    const char *arg = line + arg_at;
    const int arglen = len - arg_at;
    static const makcu_cmd_t synthetic = { "mx", 2, 0, 1, 0 };
    makcu_opcode_table[opcode](arg, arglen, makcu_dev_instance(), &synthetic, arg, arglen);
    return 1;
}
#endif

static void handle_line(const char *line, int len)
{""")
    t=t.replace("""    int skip = 0;
    const makcu_cmd_t *entry = makcu_lookup(line, len, &skip);""","""#if MB_DEBUG_OPCODE
    if (handle_debug_line(line, len)) {
        return;
    }
#endif
    int skip = 0;
    const makcu_cmd_t *entry = makcu_lookup(line, len, &skip);""")
    open(p,"w",encoding="utf-8").write(t)

p="app_left/CMakeLists.txt"
t=open(p,encoding="utf-8").read()
if "MB_DEBUG_OPCODE" not in t:
    t=t.replace('set(EXTRA_COMPONENT_DIRS "${CMAKE_CURRENT_LIST_DIR}/../components")',
'''set(EXTRA_COMPONENT_DIRS "${CMAKE_CURRENT_LIST_DIR}/../components")

# Test-only harness: exposes "mx.<hex opcode> <args>" so the hidden opcodes can
# be exercised from the control port.  OFF for any shipped build.
option(MB_DEBUG_OPCODE "enable the mx.<opcode> test harness" OFF)''')
    open(p,"w",encoding="utf-8").write(t)

p="app_left/main/CMakeLists.txt"
t=open(p,encoding="utf-8").read()
if "MB_DEBUG_OPCODE" not in t:
    t=t.replace('idf_component_register(SRCS "app_main.c"',
'''if(MB_DEBUG_OPCODE)
    add_compile_definitions(MB_DEBUG_OPCODE=1)
endif()

idf_component_register(SRCS "app_main.c"''')
    open(p,"w",encoding="utf-8").write(t)
print("debug harness added")
