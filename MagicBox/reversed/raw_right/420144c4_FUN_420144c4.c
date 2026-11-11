// 420144c4  FUN_420144c4  FUN_420144c4  size=65

int FUN_420144c4(int param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 100) == 1) {
    for (iVar2 = *(int *)(param_1 + 0x10); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      while (iVar1 = FUN_42016228(iVar2,param_2,0xff,0,0xff), iVar1 != DAT_42000cd4) {
        if (iVar1 != 0) {
          return iVar1;
        }
      }
    }
    iVar2 = 0;
  }
  else {
    iVar2 = DAT_420010a0;
  }
  return iVar2;
}


