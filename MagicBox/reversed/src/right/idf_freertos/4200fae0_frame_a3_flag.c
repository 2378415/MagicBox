void frame_a3_flag(int param_1)

{
  memw();
  memw();
  *DAT_42000d48 = 1;
  *(undefined2 *)(param_1 + 2) = 1;
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}