uint FUN_42007090(undefined4 param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  iVar1 = (*DAT_420007e8)(param_1,PTR_DAT_420007dc);
  if (((iVar1 == 0) || (iVar1 = (*DAT_420007e8)(param_1,PTR_DAT_420007e0), iVar1 == 0)) ||
     (iVar1 = (*DAT_420007e8)(param_1,PTR_DAT_420007e4), iVar1 == 0)) {
    if (param_2 == 0) {
      uVar2 = 0;
    }
    else if (((param_2 >> 1 & 3) == 0) || (uVar2 = param_2 & 1, (param_2 & 1) != 0)) {
      puVar3 = (undefined4 *)FUN_420180e4();
      *puVar3 = 0xd;
      uVar2 = 0xffffffff;
    }
  }
  else {
    puVar3 = (undefined4 *)FUN_420180e4();
    *puVar3 = 2;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}