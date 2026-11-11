void FUN_420156b8(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0xffffffff;
  *(undefined1 *)(param_1 + 5) = 0xfe;
  param_1[0xe] = 0xffffffff;
  param_1[0xf] = 0xffffffff;
  *(undefined2 *)(param_1 + 0x10) = 0;
  *(undefined2 *)((int)param_1 + 0x42) = 0;
  FUN_42024e64(param_1 + 0x11);
  param_1[0x14] = 0;
  return;
}