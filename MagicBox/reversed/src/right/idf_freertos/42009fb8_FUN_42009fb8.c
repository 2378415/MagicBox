void FUN_42009fb8(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint local_30;
  
  uVar1 = (*DAT_420001e4)(param_1);
  local_30 = 0xffffffff;
  iVar2 = 0;
  for (uVar6 = 0; uVar6 < *DAT_42000980; uVar6 = uVar6 + 1) {
    iVar4 = *(int *)(uVar6 * 4 + DAT_4200097c);
    if ((((iVar4 != 0) && (uVar5 = *(uint *)(iVar4 + 0x18), uVar5 != 0xffffffff)) &&
        (uVar5 <= uVar1)) && (iVar3 = (*DAT_420009a4)(param_1,iVar4 + 8,uVar5), iVar3 == 0)) {
      if ((uVar5 == 0) && (iVar2 == 0)) {
        iVar2 = iVar4;
      }
      else if (((uVar1 <= uVar5) || (*(char *)(param_1 + uVar5) == '/')) &&
              ((int)local_30 < (int)uVar5)) {
        iVar2 = iVar4;
        local_30 = uVar5;
      }
    }
  }
  return;
}