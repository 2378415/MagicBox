bool FUN_40381b64(void)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  
  piVar1 = DAT_4037527c;
  if (*DAT_4037527c == 0) {
    iVar3 = FUN_4037b894(1);
    *piVar1 = iVar3;
  }
  iVar3 = FUN_4037e0e0();
  if (iVar3 == 1) {
    bVar2 = true;
  }
  else {
    iVar3 = FUN_4037bbf4(*piVar1,10);
    bVar2 = iVar3 == 1;
  }
  return bVar2;
}