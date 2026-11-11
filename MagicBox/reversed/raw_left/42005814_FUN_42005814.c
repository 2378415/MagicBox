// 42005814  FUN_42005814  FUN_42005814  size=75

int FUN_42005814(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 in_PRID;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = 0x102;
  }
  else {
    iVar1 = (*(code *)PTR_FUN_420006c0)(0);
    uVar2 = *(uint *)*param_1 >> 0x10 & 1;
    if ((iVar1 == DAT_42000664) || (uVar3 = rsr(in_PRID), uVar2 != (uVar3 >> 0xd & 1))) {
      iVar1 = FUN_42003f3c(uVar2,PTR_FUN_420006bc,param_1);
      iVar1 = -(uint)(iVar1 != 0);
    }
    else {
      FUN_42005738(param_1);
      iVar1 = 0;
    }
  }
  return iVar1;
}


