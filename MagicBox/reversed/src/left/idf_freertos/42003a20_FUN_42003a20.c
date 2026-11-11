void FUN_42003a20(int param_1)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar2 = DAT_42000344;
  pcVar1 = DAT_420002d8;
  iVar4 = *DAT_42000344;
  if (*DAT_420002d8 == '\0') {
    FUN_42003c5c(param_1);
    FUN_4200330c(PTR_s__3c039338_0x14_42000388);
  }
  FUN_42003dec(param_1,iVar4 != param_1);
  FUN_4200330c(PTR_s__3c039338_0x14_42000388);
  if (iVar4 == param_1) goto LAB_42003a84;
  iVar5 = 0;
  while( true ) {
    iVar3 = piVar2[iVar5];
    if (iVar3 != 0) {
      if (*pcVar1 == '\0') {
        FUN_42003c5c(iVar3,iVar5);
        FUN_4200330c(PTR_s__3c039338_0x14_42000388);
      }
      FUN_42003dec(iVar3,iVar5);
      FUN_4200330c(PTR_s__3c039338_0x14_42000388);
    }
    if (iVar5 == 1) break;
LAB_42003a84:
    iVar5 = 1;
    if (iVar4 != param_1) {
      return;
    }
  }
  return;
}