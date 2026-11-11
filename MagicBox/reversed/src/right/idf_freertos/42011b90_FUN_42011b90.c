undefined4 FUN_42011b90(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_42011b5c(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x102;
  }
  else {
    (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000e08,0xffffffff);
    uVar2 = FUN_42011b80(param_1);
    FUN_42011ae8(uVar2,1);
    FUN_420139c4(param_1);
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000e08);
    uVar2 = 0;
  }
  return uVar2;
}