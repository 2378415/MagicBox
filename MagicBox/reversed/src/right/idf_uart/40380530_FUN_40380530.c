void FUN_40380530(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_2 * 4 + *param_1;
  memw();
  memw();
  *(uint *)(iVar2 + 4) = *(uint *)(iVar2 + 4) | DAT_403745e0;
  do {
    iVar2 = *param_1;
    memw();
  } while ((*(uint *)(param_2 * 4 + iVar2 + 4) & 0x20000000) == 0);
  memw();
  iVar3 = *(int *)((param_2 + 8) * 8 + iVar2 + 4);
  do {
    memw();
    memw();
    iVar4 = *(int *)((param_2 + 8) * 8 + iVar2 + 4);
    bVar1 = iVar3 != iVar4;
    iVar3 = iVar4;
  } while (bVar1);
  return;
}