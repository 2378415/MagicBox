// 420060a4  FUN_420060a4  FUN_420060a4  size=62

undefined4 FUN_420060a4(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  
  if (param_1 != (uint *)0x0) {
    FUN_42006074();
    uVar3 = param_1[2];
    iVar2 = DAT_42000698 * param_1[1] + (int)((ulonglong)*param_1 * (ulonglong)DAT_42000698 >> 0x20)
            + ((int)uVar3 >> 0x1f);
    uVar1 = DAT_42000698 * *param_1 + uVar3;
    if (uVar1 < uVar3) {
      iVar2 = iVar2 + 1;
    }
    uVar4 = FUN_420060ec();
    iVar2 = iVar2 - (int)((ulonglong)uVar4 >> 0x20);
    if (uVar1 < (uint)uVar4) {
      iVar2 = iVar2 + -1;
    }
    FUN_42006108(uVar1 - (uint)uVar4,iVar2);
  }
  return 0;
}


