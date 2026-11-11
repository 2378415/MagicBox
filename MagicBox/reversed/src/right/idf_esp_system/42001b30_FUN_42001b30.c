void FUN_42001b30(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_42001b08();
  uVar2 = (*DAT_420000a8)(0);
  uVar2 = FUN_42024398(uVar2,iVar1);
  *DAT_42000124 = uVar2;
  if (iVar1 != 0) {
    FUN_42001af8();
  }
  return;
}