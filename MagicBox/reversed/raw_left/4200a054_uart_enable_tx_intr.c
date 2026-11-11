// 4200a054  uart_enable_tx_intr  FUN_4200a054  size=144
// strings: uart_enable_tx_intr | uart

undefined4 FUN_4200a054(uint param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  
  puVar5 = PTR_DAT_42000a3c;
  if (param_1 < 3) {
    if (param_3 < 0x80) {
      puVar2 = PTR_DAT_42000a3c + param_1 * 0x18 + 0xc;
      memw();
      *(undefined4 *)(*(int *)(PTR_DAT_42000a3c + param_1 * 0x18 + 8) + 0x10) = 2;
      (*(code *)PTR_FUN_420004dc)(puVar2,0xffffffff);
      FUN_4201a934(puVar5 + param_1 * 0x18 + 8,param_3);
      iVar4 = *(int *)(puVar5 + param_1 * 0x18 + 8);
      memw();
      memw();
      *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) | 2;
      (*(code *)PTR_FUN_420004e0)(puVar2);
      return 0;
    }
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar3 = 0x298;
    puVar5 = PTR_DAT_42000b00;
  }
  else {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar3 = 0x297;
    puVar5 = PTR_DAT_42000a58;
  }
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_42000a54,puVar5,uVar1,PTR_DAT_42000a54,PTR_s_uart_enable_tx_intr_42000afc,
             uVar3);
  return 0xffffffff;
}


