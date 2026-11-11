int FUN_4037ee34(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  while( true ) {
    if (0x1ff < iVar1) {
      return -1;
    }
    iVar2 = FUN_4037edcc(param_1,iVar1);
    if (((iVar2 != 0) && (iVar2 = FUN_4037ee00(param_1,iVar1), iVar2 == param_3)) &&
       ((*(uint *)((iVar1 + DAT_40375054) * 4) & 0x3fff) == param_2)) break;
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}