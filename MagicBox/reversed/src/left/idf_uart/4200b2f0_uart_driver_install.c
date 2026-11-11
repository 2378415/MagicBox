// strings: uart_driver_install

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_4200b2f0(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 3) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar1 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_42000a54,PTR_DAT_42000a58,uVar1,PTR_DAT_42000a54,
             PTR_s_uart_driver_install_42000ba4,0x6ba);
  return 0xffffffff;
}