// 42009fa8  uart_pattern_queue_reset  FUN_42009fa8  size=166
// strings: uart_pattern_queue_reset

undefined4 FUN_42009fa8(uint param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined *puVar4;
  int iVar5;
  
  if (param_1 < 3) {
    piVar3 = (int *)(param_1 * 4 + DAT_42000a40);
    if (*piVar3 == 0) {
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (1,PTR_DAT_42000a54,PTR_DAT_42000af0,uVar1,PTR_DAT_42000a54,
                 PTR_s_uart_pattern_queue_reset_42000af8,0x24e);
      uVar1 = 0x103;
    }
    else {
      iVar2 = (*(code *)PTR_FUN_42000660)(param_2 << 2,DAT_42000988);
      if (iVar2 == 0) {
        uVar1 = 0x101;
      }
      else {
        puVar4 = PTR_DAT_42000af4 + param_1 * 0x18;
        (*(code *)PTR_FUN_420004dc)(puVar4,0xffffffff);
        iVar5 = *piVar3;
        uVar1 = *(undefined4 *)(iVar5 + 0x38);
        *(int *)(iVar5 + 0x34) = param_2;
        *(int *)(iVar5 + 0x38) = iVar2;
        *(undefined4 *)(iVar5 + 0x30) = 0;
        *(undefined4 *)(iVar5 + 0x2c) = 0;
        (*(code *)PTR_FUN_420004e0)(puVar4);
        (*(code *)PTR_FUN_42000570)(uVar1);
        uVar1 = 0;
      }
    }
  }
  else {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_DAT_42000a54,PTR_DAT_42000a58,uVar1,PTR_DAT_42000a54,
               PTR_s_uart_pattern_queue_reset_42000af8,0x24d);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


