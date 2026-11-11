void mouse_move(int param_1,short param_2,short param_3,ushort param_4)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x210) != 0)) {
    if (param_4 < 2) {
      mouse_submit_default();
    }
    else {
      mouse_move_mode(param_1,(int)param_2,(int)param_3);
    }
  }
  return;
}