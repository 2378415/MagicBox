// 42012190  FUN_42012190  FUN_42012190  size=56

undefined4 FUN_42012190(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (DAT_42000e64 < param_1) {
    iVar1 = FUN_42016cd8();
    uVar3 = *(uint *)(iVar1 + 0xc);
    if ((param_1 < uVar3) || (uVar3 + *(int *)(iVar1 + 0x10) <= param_1)) {
      if (param_1 < uVar3) {
        if (uVar3 < param_1 + param_2) {
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
        }
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


