// 42004640  FUN_42004640  FUN_42004640  size=89

bool FUN_42004640(undefined4 param_1,undefined1 param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = DAT_42000564;
  piVar3 = (int *)*DAT_42000564;
  while( true ) {
    if (piVar3 == (int *)0x0) {
      iVar2 = (*DAT_4200030c)(param_1);
      piVar3 = (int *)(*(code *)PTR_FUN_4200056c)(iVar2 + 6);
      if (piVar3 != (int *)0x0) {
        *(undefined1 *)(piVar3 + 1) = param_2;
        (*DAT_42000064)((int)piVar3 + 5,param_1,iVar2 + 1);
        *piVar3 = *piVar1;
        *piVar1 = (int)piVar3;
      }
      return piVar3 != (int *)0x0;
    }
    iVar2 = (*DAT_42000568)((int)piVar3 + 5,param_1);
    if (iVar2 == 0) break;
    piVar3 = (int *)*piVar3;
  }
  *(undefined1 *)(piVar3 + 1) = param_2;
  return true;
}


