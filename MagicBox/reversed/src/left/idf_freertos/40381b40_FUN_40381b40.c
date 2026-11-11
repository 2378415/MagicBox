void FUN_40381b40(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_4037527c;
  if (*DAT_4037527c == 0) {
    iVar2 = FUN_4037b894(1);
    *piVar1 = iVar2;
  }
  iVar2 = FUN_4037e0e0();
  if (iVar2 != 1) {
    FUN_4037bbf4(*piVar1,0xffffffff);
  }
  return;
}