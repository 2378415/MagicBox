// 42011378  FUN_42011378  FUN_42011378  size=145

undefined4 FUN_42011378(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if ((int)param_1 < 0) {
    uVar1 = 0x102;
  }
  else {
    uVar2 = DAT_42000504 << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
            DAT_42000508 >> (param_1 & 0x1f);
    if ((param_1 & 0x20) != 0) {
      uVar2 = DAT_4200050c >> (param_1 & 0x1f);
    }
    if ((uVar2 & 1) == 0) {
      uVar1 = 0x102;
    }
    else {
      iVar3 = **(int **)PTR_PTR_42000e00;
      if (param_1 < 0x20) {
        memw();
        *(int *)(iVar3 + 0x28) = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
      }
      else {
        memw();
        memw();
        *(uint *)(iVar3 + 0x34) =
             *(uint *)(iVar3 + 0x34) & 0xffc00000 |
             1 << 0x20 - (0x20 - (param_1 & 0x1f)) & 0x3fffffU;
      }
      memw();
      *(undefined4 *)((param_1 + DAT_42000e04) * 4) = 0x100;
      uVar1 = 0;
    }
  }
  return uVar1;
}


