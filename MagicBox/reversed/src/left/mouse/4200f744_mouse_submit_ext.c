void mouse_submit_ext(int param_1,undefined4 param_2,undefined4 param_3,short param_4,undefined4 param_5
                 ,undefined4 param_6)

{
  if (((param_1 != 0) && (*(int *)(param_1 + 0x210) != 0)) && ((ushort)(param_4 - 1U) < 0x400)) {
    mouse_submit(param_2,param_3,param_4,1,param_5,param_6);
  }
  return;
}