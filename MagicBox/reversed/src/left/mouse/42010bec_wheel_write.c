void wheel_write(int param_1,char param_2)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x210) != 0)) {
    wheel_submit(param_1,(int)param_2);
  }
  return;
}