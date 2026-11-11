// strings: task != ((void *)0) && reg_dump != ((void *)0) | core_dump_port.c | esp_core_dump_get_task_regs_dump

undefined4 FUN_4200bdb0(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_30;
  undefined4 auStack_2c [11];
  
  local_30 = 0;
  auStack_2c[0] = 0;
  if (param_1 == (undefined4 *)0x0 || param_2 == (int *)0x0) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_core_dump_port_c_3c0333b0_0x2d_42000ab0,0x1b3,
               PTR_s_esp_core_dump_get_task_regs_dump_42000ac4,
               PTR_s_task______void___0_____reg_dump___42000ac0);
  }
  uVar2 = FUN_4200bd34(param_1,&local_30,auStack_2c);
  iVar1 = DAT_42000ac8;
  *(undefined2 *)(DAT_42000ac8 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x18) = *param_1;
  FUN_4200b9e0(auStack_2c[0],uVar2,DAT_42000acc);
  *param_2 = iVar1;
  return 0x24c;
}