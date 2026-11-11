undefined4 FUN_4200469c(undefined4 param_1,uint *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*DAT_42000564;
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    iVar1 = (*DAT_42000568)(param_1,(int)piVar2 + 5);
    if (iVar1 == 0) break;
    piVar2 = (int *)*piVar2;
  }
  *param_2 = (uint)*(byte *)(piVar2 + 1);
  return 1;
}