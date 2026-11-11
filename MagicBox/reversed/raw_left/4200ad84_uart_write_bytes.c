// 4200ad84  uart_write_bytes  FUN_4200ad84  size=122
// strings: uart_write_bytes | uart

undefined4 FUN_4200ad84(uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  if (param_1 < 3) {
    if (*(int *)(param_1 * 4 + DAT_42000a40) == 0) {
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      uVar2 = 0x5cd;
      puVar3 = PTR_DAT_42000af0;
    }
    else {
      if (param_2 != 0) {
        if (param_3 == 0) {
          return 0;
        }
        uVar1 = FUN_4200a0e8(param_1,param_2,param_3,0,0);
        return uVar1;
      }
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      uVar2 = 0x5ce;
      puVar3 = PTR_DAT_42000b78;
    }
  }
  else {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar2 = 0x5cc;
    puVar3 = PTR_DAT_42000a58;
  }
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_42000a54,puVar3,uVar1,PTR_DAT_42000a54,PTR_s_uart_write_bytes_42000b74,uVar2)
  ;
  return 0xffffffff;
}


