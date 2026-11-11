// 40382108  memspi_host_erase_block  FUN_40382108  size=62
// strings: start_address < 0x1000000

void FUN_40382108(int *param_1,uint param_2)

{
  undefined1 auStack_40 [3];
  undefined1 uStack_3d;
  uint uStack_3c;
  undefined2 uStack_2c;
  
  if (DAT_40375214 < param_2) {
    FUN_40381d9c(PTR_s_memspi_host_driver_c_3fc95f74_0x1b_40375220,0xa2,
                 PTR_s_memspi_host_erase_block_40375224,PTR_s_start_address_<_0x1000000_40375218);
  }
  (*DAT_4037448c)(auStack_40,0,0x1c);
  uStack_3d = 0x18;
  uStack_2c = 0xd8;
  uStack_3c = param_2;
  (**(code **)(*param_1 + 4))(param_1,auStack_40);
  return;
}


