// 42002d90  FUN_42002d90  FUN_42002d90  size=50
// strings: TZ7@|

void FUN_42002d90(void)

{
  int iVar1;
  uint uVar2;
  
  (*(code *)PTR_FUN_420001c0)();
  uVar2 = *(uint *)PTR_DAT_420001b8;
  iVar1 = (*DAT_420001c4)(0);
  FUN_4202dfd8(uVar2 & DAT_420001bc | (uint)(iVar1 == 1) << 0x1e);
  return;
}


