int FUN_4201c358(int param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_420011bc;
  iVar3 = DAT_42001a70;
  if (*(int *)(param_1 + 100) == 1) {
    iVar2 = *(int *)(param_1 + 0x10);
    if (iVar2 == 0) {
LAB_4201c36e:
      iVar3 = 0;
    }
    else {
      do {
        while (iVar3 = FUN_4201d70c(iVar2,param_2,0xff,0,0xff), iVar3 == iVar1) {
          iVar2 = *(int *)(iVar2 + 4);
          if (iVar2 == 0) goto LAB_4201c36e;
        }
      } while (iVar3 == 0);
    }
  }
  return iVar3;
}