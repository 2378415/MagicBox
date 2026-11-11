// strings: uart_param_config | uart

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_4200a808(uint param_1,int param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  if (param_1 < 3) {
    if (param_2 == 0) {
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      puVar2 = PTR_DAT_42000b3c;
    }
    else if ((*(byte *)(param_2 + 0x14) & 0x80) == 0) {
      if (*(uint *)(param_2 + 0x10) < 4) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      puVar2 = PTR_DAT_42000b44;
    }
    else {
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      puVar2 = PTR_DAT_42000b40;
    }
  }
  else {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    puVar2 = PTR_DAT_42000a58;
  }
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_42000a54,puVar2,uVar1,PTR_DAT_42000a54,PTR_s_uart_param_config_42000b38);
  return 0xffffffff;
}