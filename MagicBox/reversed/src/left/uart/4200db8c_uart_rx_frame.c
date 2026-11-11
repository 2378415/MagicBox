void uart_rx_frame(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    frame_router(param_1,param_2);
  }
  return;
}