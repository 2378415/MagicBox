undefined4 FUN_42013b60(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_42013b50(*DAT_42001090,0,param_1);
  if (iVar1 == 0) {
    uVar2 = DAT_4200108c;
  }
  else {
    *param_2 = *(undefined4 *)(iVar1 + 8);
    uVar2 = 0;
  }
  return uVar2;
}