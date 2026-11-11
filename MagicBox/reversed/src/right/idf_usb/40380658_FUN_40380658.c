void FUN_40380658(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    iVar1 = (param_2 + 0xc) * 4 + *param_1;
    memw();
    memw();
    *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & DAT_403747d8;
  }
  else if (param_3 == 1) {
    iVar1 = (param_2 + 0xc) * 4 + *param_1;
    memw();
    memw();
    *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) | DAT_403745e0;
  }
  return;
}