undefined4 FUN_42003a40(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 in_PRID;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar2 = 0x102;
  }
  else {
    iVar1 = (*(code *)PTR_FUN_420004dc)(0);
    if ((iVar1 == DAT_4200049c) ||
       (uVar3 = rsr(in_PRID), (*(uint *)*param_1 >> 0x10 & 1) != (uVar3 >> 0xd & 1))) {
      iVar1 = FUN_42002948(*(uint *)*param_1 >> 0x10 & 1,PTR_FUN_420004d8,param_1);
      uVar2 = 0;
      if (iVar1 != 0) {
        uVar2 = 0xffffffff;
      }
    }
    else {
      uVar2 = FUN_42003950(param_1);
    }
  }
  return uVar2;
}