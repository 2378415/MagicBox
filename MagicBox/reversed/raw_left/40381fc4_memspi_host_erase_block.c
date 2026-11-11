// 40381fc4  memspi_host_erase_block  FUN_40381fc4  size=68
// strings: start_address < 0x1000000 | memspi_host_erase_block

void FUN_40381fc4(int *param_1,uint param_2)

{
  undefined4 extraout_a3;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *in_t0;
  undefined4 local_40;
  uint uStack_3c;
  undefined2 uStack_2c;
  
  uVar3 = 0;
  puVar1 = (undefined4 *)0x7;
  puVar2 = &local_40;
  if (DAT_403752d4 < param_2) {
    puVar1 = in_t0;
    FUN_40381ce4(PTR_s_memspi_host_driver_c_3fc962c8_0x1b_403752e8,0xa2,
                 PTR_s_memspi_host_erase_block_403752ec,PTR_s_start_address_<_0x1000000_403752e0);
    puVar2 = puVar1;
    uVar3 = extraout_a3;
  }
  do {
    *puVar2 = uVar3;
    puVar2 = puVar2 + 1;
    puVar1 = (undefined4 *)((int)puVar1 + -1);
  } while (puVar1 != (undefined4 *)0x0);
  local_40._3_1_ = 0x18;
  uStack_2c = 0xd8;
  uStack_3c = param_2;
  (**(code **)(*param_1 + 4))(param_1,&local_40);
  return;
}


