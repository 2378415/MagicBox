undefined1  [16] FUN_40383c20(void)

{
  undefined1 auVar1 [16];
  undefined1 in_LBEG;
  undefined1 in_LEND;
  undefined1 in_LCOUNT;
  undefined1 in_SAR;
  undefined4 in_stack_00000014;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000020;
  undefined4 in_stack_0000004c;
  undefined4 in_stack_00000058;
  undefined4 in_stack_0000005c;
  undefined4 in_stack_00000060;
  undefined1 uStack00000070;
  
  FUN_40383b1c(&uStack00000070);
  wsr(in_LBEG,in_stack_00000058);
  wsr(in_LEND,in_stack_0000005c);
  wsr(in_LCOUNT,in_stack_00000060);
  wsr(in_SAR,in_stack_0000004c);
  auVar1._4_4_ = in_stack_00000018;
  auVar1._0_4_ = in_stack_00000014;
  auVar1._8_4_ = in_stack_0000001c;
  auVar1._12_4_ = in_stack_00000020;
  return auVar1;
}