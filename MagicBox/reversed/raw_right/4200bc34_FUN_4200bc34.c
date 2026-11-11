// 4200bc34  FUN_4200bc34  FUN_4200bc34  size=92

undefined4 FUN_4200bc34(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(param_1 + 4);
  if (((DAT_42000a84 < uVar2 + DAT_42000a80) || ((uVar2 & 0xf) != 0)) &&
     (DAT_42000234 < uVar2 + DAT_42000230)) {
    uVar1 = 0;
  }
  else {
    uVar3 = *(uint *)(param_1 + 8);
    if ((DAT_42000a88 < uVar3 + DAT_4200058c) && (DAT_42000234 < uVar3 + DAT_42000230)) {
      uVar1 = 0;
    }
    else if (uVar2 < uVar3) {
      if (DAT_42000a8c < uVar3 - uVar2) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


