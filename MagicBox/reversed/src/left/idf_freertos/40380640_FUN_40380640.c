void FUN_40380640(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *param_1;
  iVar3 = param_2 * 4 + iVar4;
  memw();
  memw();
  *(uint *)(iVar3 + 4) = *(uint *)(iVar3 + 4) | DAT_4037460c;
  do {
    memw();
  } while ((*(uint *)(iVar3 + 4) & 0x20000000) == 0);
  iVar4 = param_2 * 8 + iVar4;
  memw();
  iVar3 = *(int *)(iVar4 + 0x44);
  do {
    memw();
    memw();
    iVar2 = *(int *)(iVar4 + 0x44);
    bVar1 = iVar3 != iVar2;
    iVar3 = iVar2;
  } while (bVar1);
  return;
}