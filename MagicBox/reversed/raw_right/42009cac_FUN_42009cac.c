// 42009cac  FUN_42009cac  FUN_42009cac  size=27

int FUN_42009cac(void)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (7 < iVar1) {
      return -1;
    }
    if (*(int *)(iVar1 * 4 + DAT_4200097c) == 0) break;
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}


