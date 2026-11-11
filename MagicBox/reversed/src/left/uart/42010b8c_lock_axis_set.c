void lock_axis_set(int param_1,undefined4 param_2,undefined1 param_3)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x210) != 0)) {
    axis_slot_set(param_1,param_2,param_3);
  }
  return;
}