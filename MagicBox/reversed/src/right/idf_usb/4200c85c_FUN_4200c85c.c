void FUN_4200c85c(int param_1,int param_2)

{
  memw();
  memw();
  *(uint *)(*(int *)(param_1 + 8) + 0xc) = *(uint *)(*(int *)(param_1 + 8) + 0xc) & DAT_42000b0c;
  if (param_2 == 1) {
    memw();
    memw();
    *(uint *)(*(int *)(param_1 + 8) + 0xc) = *(uint *)(*(int *)(param_1 + 8) + 0xc) | DAT_420003d0;
  }
  else if (param_2 == 0) {
    memw();
    memw();
    *(uint *)(*(int *)(param_1 + 8) + 0xc) = *(uint *)(*(int *)(param_1 + 8) + 0xc) | DAT_420000a0;
  }
  FUN_4200da94(0x32);
  return;
}