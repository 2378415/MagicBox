p="components/makcu_clone/src/makcu_clone.c"
t=open(p,encoding="utf-8").read()
# wTotalLength must count the HID descriptor class block too: 9+9+9+7 = 34.
t=t.replace("    const uint16_t total = 9 + 9 + 7;","    const uint16_t total = 9 + 9 + 9 + 7;   /* config + interface + HID + EP */")
open(p,"w",encoding="utf-8").write(t)
print("wTotalLength fixed to 34")
