// 4201156c  FUN_4201156c  FUN_4201156c  size=154

undefined4 FUN_4201156c(uint param_1,int param_2)

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
      if (param_2 == 0) {
        if (param_1 < 0x20) {
          memw();
          *(int *)(iVar3 + 0xc) = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
          uVar1 = 0;
        }
        else {
          memw();
          *(int *)(iVar3 + 0x18) = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
          uVar1 = 0;
        }
      }
      else if (param_1 < 0x20) {
        memw();
        *(int *)(iVar3 + 8) = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
        uVar1 = 0;
      }
      else {
        memw();
        *(int *)(iVar3 + 0x14) = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}


