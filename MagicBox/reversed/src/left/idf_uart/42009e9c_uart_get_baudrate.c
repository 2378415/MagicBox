// strings: uart_get_baudrate

int FUN_42009e9c(uint param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 local_30;
  undefined4 auStack_2c [11];
  
  puVar1 = PTR_DAT_42000a3c;
  if (param_1 < 3) {
    puVar4 = PTR_DAT_42000a3c + param_1 * 0x18 + 8;
    FUN_4202d63c(puVar4,auStack_2c);
    iVar3 = FUN_4201acb0(auStack_2c[0],0,&local_30);
    if (iVar3 == 0) {
      (*(code *)PTR_FUN_420004dc)(puVar1 + param_1 * 0x18 + 0xc,0xffffffff);
      FUN_4202d660(puVar4,param_2,local_30);
      (*(code *)PTR_FUN_420004e0)(puVar1 + param_1 * 0x18 + 0xc);
    }
    else {
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (1,PTR_DAT_42000a54,PTR_DAT_42000ad8,uVar2,PTR_DAT_42000a54,
                 PTR_s_uart_get_baudrate_42000ae8,0x17a);
    }
  }
  else {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_DAT_42000a54,PTR_DAT_42000a58,uVar2,PTR_DAT_42000a54,
               PTR_s_uart_get_baudrate_42000ae8,0x174);
    iVar3 = -1;
  }
  return iVar3;
}