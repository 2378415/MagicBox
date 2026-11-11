void FUN_4200abfc(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 != (int *)0x0) {
    iVar2 = *(int *)(param_1 + 4);
    *param_2 = iVar2;
    param_2[1] = (*(int *)(param_1 + 8) - iVar2) + 3U & 0xfffffffc;
  }
  *(undefined4 *)(param_1 + 4) = *DAT_420009c0;
  uVar1 = FUN_4200bc14();
  *(undefined4 *)(param_1 + 8) = uVar1;
  return;
}