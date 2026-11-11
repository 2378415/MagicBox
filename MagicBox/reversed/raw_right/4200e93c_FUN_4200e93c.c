// 4200e93c  FUN_4200e93c  FUN_4200e93c  size=73

int FUN_4200e93c(void)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  while( true ) {
    if (bVar1) {
      return 0;
    }
    if ((*DAT_42000c58 & 1) == 0) break;
    bVar1 = true;
  }
  *DAT_42000c58 = *DAT_42000c58 | 1;
  iVar2 = DAT_42000c60;
  (*DAT_42000240)(DAT_42000c60,0);
  *(undefined1 *)(iVar2 + 2) = 2;
  return iVar2;
}


