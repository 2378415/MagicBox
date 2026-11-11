void frame_router(byte *param_1,int param_2)

{
  byte bVar1;
  undefined4 local_30 [12];
  
  bVar1 = *param_1;
  param_1 = param_1 + 1;
  if (bVar1 == 0xa2) {
    return;
  }
  if (bVar1 < 0xa3) {
    if (bVar1 == 0x2e) {
      cmd_dispatch(param_1);
      return;
    }
    if (bVar1 == 0xa1) {
      local_30[0] = CONCAT31(local_30[0]._1_3_,0xa1);
      uart0_reply(local_30,1);
      return;
    }
  }
  else {
    if (bVar1 == 0xa4) {
      local_30[0] = 0;
      config_load(local_30);
      return;
    }
    if (bVar1 == 0xa5) {
      if (param_2 - 1U < 4) {
        return;
      }
      local_30[0] = 0;
      (*DAT_42000064)(local_30,param_1,4);
      serial_setup(local_30[0]);
      return;
    }
  }
  frame_echo_hex(bVar1,param_1,param_2 - 1U);
  return;
}