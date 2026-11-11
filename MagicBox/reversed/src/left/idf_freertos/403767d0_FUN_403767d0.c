void FUN_403767d0(int param_1)

{
  ushort *puVar1;
  
  puVar1 = *(ushort **)(param_1 + 4);
  FUN_4037bf44(PTR_DAT_40374708,0xffffffff);
  for (; puVar1 != (ushort *)0x0; puVar1 = *(ushort **)(puVar1 + 10)) {
    if (((*puVar1 & 1) == 0) &&
       ((*(uint **)(puVar1 + 2) == (uint *)0x0 ||
        (memw(), (**(uint **)(puVar1 + 2) & *(uint *)(puVar1 + 4)) != 0)))) {
      (**(code **)(puVar1 + 6))(*(undefined4 *)(puVar1 + 8));
    }
  }
  FUN_4037c094(PTR_DAT_40374708);
  return;
}