void FUN_4202451c(int *param_1,int param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  if ((int)*param_3 < 1) {
    memw();
    *param_3 = *(uint *)(*param_1 + 0x1c) & 0x3ff;
  }
  puVar3 = (undefined4 *)*param_1;
  uVar2 = *param_3;
  for (iVar1 = 0; iVar1 < (int)uVar2; iVar1 = iVar1 + 1) {
    memw();
    *(char *)(param_2 + iVar1) = (char)*puVar3;
  }
  return;
}