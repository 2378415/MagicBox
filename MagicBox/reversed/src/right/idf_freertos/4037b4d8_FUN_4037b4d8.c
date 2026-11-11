// strings: lock

void FUN_4037b4d8(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    param_1[2] = 0;
    *param_1 = 0;
    param_1[3] = 0;
    puVar1 = param_1;
    if (param_1 == (undefined4 *)0xffffffb4) {
      puVar1 = (undefined4 *)
               FUN_40381d9c(PTR_s_spinlock_h_3c030b80_0x28_40374c90,0x35,
                            PTR_s_spinlock_initialize_40374c8c,PTR_DAT_40374c88);
    }
    param_1[0x13] = DAT_40374b44;
    param_1[0x14] = 0;
    FUN_4037b39c(puVar1,0,0,0);
  }
  return;
}