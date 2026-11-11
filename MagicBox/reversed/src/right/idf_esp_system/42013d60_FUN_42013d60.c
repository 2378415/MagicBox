void FUN_42013d60(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_30 [48];
  
  FUN_420154e8(auStack_30);
  iVar1 = FUN_42013b84(*DAT_42001090,0,param_1);
  if (iVar1 == 0) {
    FUN_420154f8(auStack_30);
  }
  else {
    FUN_42024be8(DAT_42001090,iVar1);
    FUN_42024bd8(iVar1);
    (*(code *)PTR_FUN_420004c0)(iVar1);
    FUN_420154f8(auStack_30);
  }
  return;
}