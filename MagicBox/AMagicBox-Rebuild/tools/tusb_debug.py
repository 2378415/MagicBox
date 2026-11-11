p="components/makcu_hiddev/include/tusb_config.h"
t=open(p,encoding="utf-8").read()
if "CFG_TUSB_DEBUG" not in t:
    t=t.replace("#define CFG_TUD_ENDPOINT0_SIZE      64","""#ifdef MB_TUSB_DEBUG
#define CFG_TUSB_DEBUG              MB_TUSB_DEBUG
#endif

#define CFG_TUD_ENDPOINT0_SIZE      64""")
    open(p,"w",encoding="utf-8").write(t)
p="app_left/main/CMakeLists.txt"
t=open(p,encoding="utf-8").read()
if "MB_TUSB_DEBUG" not in t:
    t=t.replace('''if(MB_CLONE_FIXTURE)''','''if(MB_TUSB_DEBUG)
    add_compile_definitions(MB_TUSB_DEBUG=${MB_TUSB_DEBUG})
endif()
if(MB_CLONE_FIXTURE)''')
    open(p,"w",encoding="utf-8").write(t)
p="app_left/CMakeLists.txt"
t=open(p,encoding="utf-8").read()
if "MB_TUSB_DEBUG" not in t:
    t=t.replace('set(MB_CLONE_FIXTURE "" CACHE STRING "clone fixture loaded at boot (1 or 2)")',
'''set(MB_CLONE_FIXTURE "" CACHE STRING "clone fixture loaded at boot (1 or 2)")

# Bench only: TinyUSB debug level (1 = warnings, 2 = everything).
set(MB_TUSB_DEBUG "" CACHE STRING "CFG_TUSB_DEBUG level")''')
    open(p,"w",encoding="utf-8").write(t)
print("tusb debug flag wired")
