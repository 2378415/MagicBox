void FUN_4202d624(int param_1,int param_2)

{
  *(uint *)(param_1 + 0xc) = (uint)(param_2 + *(int *)(param_1 + 0xc)) % *(uint *)(param_1 + 4);
  return;
}