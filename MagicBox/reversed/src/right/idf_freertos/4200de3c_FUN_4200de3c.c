int FUN_4200de3c(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  
  if (*(byte *)(param_1 + 2) == param_2) {
    iVar5 = (param_3 + -1) * DAT_42000bcc;
    iVar1 = param_1 + iVar5 + 0x20;
    if (*(char *)(param_1 + iVar5 + 0x20) == '\0') {
      iVar1 = 0;
    }
  }
  else {
    for (uVar2 = 0; uVar2 < *(byte *)(param_1 + 5); uVar2 = uVar2 + 1 & 0xff) {
      iVar1 = param_1 + uVar2 * DAT_42000bcc + 0x20;
      if (*(char *)(param_1 + uVar2 * DAT_42000bcc + 0x20) != '\0') {
        for (uVar3 = 0; uVar3 < *(byte *)(iVar1 + 0x20); uVar3 = uVar3 + 1 & 0xff) {
          piVar4 = *(int **)(uVar3 * 0x144 + iVar1 + 0x38);
          if ((((piVar4 != (int *)0x0) && (iVar5 = *piVar4, iVar5 != 0)) &&
              (iVar5 = (*DAT_420007e8)(iVar5,PTR_DAT_42000bd0), iVar5 == 0)) &&
             (((pcVar6 = *(char **)(uVar3 * 0x144 + iVar1 + 0x3c), pcVar6 != (char *)0x0 &&
               (*pcVar6 != '\0')) && (iVar1 = FUN_4200de3c(pcVar6,param_2,param_3), iVar1 != 0)))) {
            return iVar1;
          }
        }
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}