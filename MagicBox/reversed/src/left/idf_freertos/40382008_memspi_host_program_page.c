// strings: address + length <= 0x1000000 | memspi_host_program_page

void FUN_40382008(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *in_t0;
  undefined4 local_40;
  int iStack_3c;
  undefined4 uStack_38;
  undefined2 uStack_2c;
  
  uVar3 = 0;
  puVar1 = (undefined4 *)0x7;
  puVar2 = &local_40;
  if (DAT_40374920 < (uint)(param_3 + param_4)) {
    puVar1 = in_t0;
    uVar3 = FUN_40381ce4(PTR_s_memspi_host_driver_c_3fc962c8_0x1b_403752e8,0xae,
                         PTR_s_memspi_host_program_page_403752f4,
                         PTR_s_address___length_<__0x1000000_403752f0);
    puVar2 = puVar1;
  }
  do {
    *puVar2 = uVar3;
    puVar2 = puVar2 + 1;
    puVar1 = (undefined4 *)((int)puVar1 + -1);
  } while (puVar1 != (undefined4 *)0x0);
  local_40._3_1_ = 0x18;
  local_40._1_1_ = (undefined1)param_4;
  uStack_2c = 2;
  iStack_3c = param_3;
  uStack_38 = param_2;
  (**(code **)(*param_1 + 4))(param_1,&local_40);
  return;
}