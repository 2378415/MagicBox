void catch_set(int param_1,int param_2,uint param_3)

{
  if (((param_1 != 0) && (*(int *)(param_1 + 0x210) != 0)) && (param_2 - 1U < 5)) {
    *(uint *)(param_2 * 4 + *(int *)(param_1 + 0x210) + 0x168) = param_3 & 0xff;
  }
  return;
}