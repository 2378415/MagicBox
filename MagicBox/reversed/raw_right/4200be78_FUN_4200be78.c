// 4200be78  FUN_4200be78  FUN_4200be78  size=50

void FUN_4200be78(int param_1)

{
  if (*(byte *)(param_1 + 0x90) < 0x20) {
    *DAT_42000ad0 =
         1 << 0x20 - (0x20 - (*(byte *)(param_1 + 0x90) & 0x1f)) & *DAT_42000ad0 ^ *DAT_42000ad0;
  }
  (*DAT_42000240)(param_1,0,0x98);
  return;
}


