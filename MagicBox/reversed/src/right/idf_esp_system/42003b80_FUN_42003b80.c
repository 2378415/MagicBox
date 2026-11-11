// strings: Pw7@

void FUN_42003b80(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  for (uVar3 = 0; (int)uVar3 < 0x31; uVar3 = uVar3 + 1) {
    if (-1 < (int)uVar3) {
      uVar4 = DAT_42000504 << 0x20 - (0x20 - ((uVar3 ^ 0xffffffff) & 0x1f)) |
              DAT_42000508 >> (uVar3 & 0x1f);
      if ((uVar3 & 0x20) != 0) {
        uVar4 = DAT_4200050c >> (uVar3 & 0x1f);
      }
      if ((uVar4 & 1) != 0) {
        FUN_42011818(uVar3,0);
        FUN_42011888(uVar3,3);
      }
    }
  }
  uVar1 = FUN_42012938(0);
  FUN_42011888(uVar1,0);
  uVar1 = FUN_42012938(1);
  FUN_42011888(uVar1,0);
  uVar1 = FUN_42012938(2);
  FUN_42011888(uVar1,0);
  uVar1 = FUN_42012938(4);
  FUN_42011888(uVar1,0);
  uVar1 = FUN_42012938(5);
  FUN_42011888(uVar1,0);
  iVar2 = (*(code *)PTR_FUN_42000510)();
  if (iVar2 != 0) {
    uVar1 = FUN_42012938(6);
    FUN_42011888(uVar1,0);
    uVar1 = FUN_42012938(7);
    FUN_42011888(uVar1,0);
    uVar1 = FUN_42012938(8);
    FUN_42011888(uVar1,0);
    uVar1 = FUN_42012938(9);
    FUN_42011888(uVar1,0);
    uVar1 = FUN_42012938(10);
    FUN_42011888(uVar1,0);
  }
  return;
}