// 40382148  memspi_host_program_page  FUN_40382148  size=68
// strings: address + length <= 0x1000000

void FUN_40382148(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined1 uStack_40;
  undefined1 uStack_3f;
  undefined1 uStack_3d;
  int iStack_3c;
  undefined4 uStack_38;
  undefined2 uStack_2c;
  
  if (DAT_40374890 < (uint)(param_3 + param_4)) {
    FUN_40381d9c(PTR_s_memspi_host_driver_c_3fc95f74_0x1b_40375220,0xae,
                 PTR_s_memspi_host_program_page_4037522c,
                 PTR_s_address___length_<__0x1000000_40375228);
  }
  (*DAT_4037448c)(&uStack_40,0,0x1c);
  uStack_3f = (undefined1)param_4;
  uStack_3d = 0x18;
  uStack_2c = 2;
  iStack_3c = param_3;
  uStack_38 = param_2;
  (**(code **)(*param_1 + 4))(param_1,&uStack_40);
  return;
}


