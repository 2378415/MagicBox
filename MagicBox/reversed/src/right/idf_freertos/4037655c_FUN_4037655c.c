void FUN_4037655c(int param_1)

{
  ushort *puVar1;
  
  puVar1 = *(ushort **)(param_1 + 4);
  FUN_4037bbe8(PTR_DAT_403746c8,0xffffffff);
  for (; puVar1 != (ushort *)0x0; puVar1 = *(ushort **)(puVar1 + 10)) {
    if (((*puVar1 & 1) == 0) &&
       ((*(uint **)(puVar1 + 2) == (uint *)0x0 ||
        (memw(), (**(uint **)(puVar1 + 2) & *(uint *)(puVar1 + 4)) != 0)))) {
      (**(code **)(puVar1 + 6))(*(undefined4 *)(puVar1 + 8));
    }
  }
  FUN_4037bd38(PTR_DAT_403746c8);
  return;
}