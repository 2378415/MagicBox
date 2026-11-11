// 4037a2cc  FUN_4037a2cc  FUN_4037a2cc  size=191
// strings: lock

void FUN_4037a2cc(uint param_1,int param_2,uint *param_3,uint param_4)

{
  *param_3 = param_1;
  param_3[0xc] = param_4;
  param_3[0xd] = param_4 + param_1;
  param_3[0xb] = param_4;
  param_3[10] = param_4;
  param_3[9] = param_4;
  param_3[8] = param_4;
  param_3[0xe] = 0;
  param_3[2] = 0;
  if (param_2 == 0) {
    param_3[3] = (uint)PTR_FUN_40374b08;
    param_3[4] = (uint)PTR_FUN_40374b0c;
    param_3[5] = (uint)PTR_FUN_40374b10;
    param_3[6] = (uint)PTR_FUN_40374b14;
    param_3[1] = ((param_1 >> 1) + 3 & 0xfffffffc) - 8;
    param_3[7] = (uint)PTR_FUN_40374b18;
  }
  else if (param_2 == 1) {
    param_3[2] = 1;
    param_3[3] = (uint)PTR_FUN_40374b08;
    param_3[4] = (uint)PTR_FUN_40374b1c;
    param_3[5] = (uint)PTR_FUN_40374b10;
    param_3[6] = (uint)PTR_FUN_40374b14;
    param_3[1] = param_1 - 0x10;
    param_3[7] = (uint)PTR_FUN_40374b20;
  }
  else {
    param_3[2] = 2;
    param_3[3] = (uint)PTR_FUN_40374b24;
    param_3[4] = (uint)PTR_FUN_40374b28;
    param_3[5] = (uint)PTR_FUN_40374b2c;
    param_3[6] = (uint)PTR_FUN_40374b30;
    param_3[1] = param_1;
    param_3[7] = (uint)PTR_FUN_40374b34;
  }
  FUN_4037c8b8(param_3 + 0xf);
  FUN_4037c8b8(param_3 + 0x14);
  param_3[0x19] = 0;
  if (param_3 == (uint *)0xffffff98) {
    FUN_40381d9c(PTR_s_spinlock_h_3c030b80_0x28_40374b40,0x35,PTR_s_spinlock_initialize_40374b3c,
                 PTR_DAT_40374b38);
  }
  param_3[0x1a] = DAT_40374b44;
  param_3[0x1b] = 0;
  return;
}


