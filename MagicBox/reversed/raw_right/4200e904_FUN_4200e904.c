// 4200e904  FUN_4200e904  FUN_4200e904  size=54

void FUN_4200e904(int param_1)

{
  uint uVar1;
  
  uVar1 = *(byte *)(param_1 + 2) - 2;
  if ((uVar1 & 0xff) < 0x20) {
    *DAT_42000c58 = 1 << 0x20 - (0x20 - (uVar1 & 0x1f)) & *DAT_42000c58 ^ *DAT_42000c58;
  }
  (*DAT_42000240)(param_1,0,DAT_42000c5c);
  return;
}


