// strings: uart_pattern_pop_pos

undefined4 FUN_42009f34(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  
  piVar2 = (int *)(param_1 * 4 + DAT_42000a40);
  if (*piVar2 == 0) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_DAT_42000a54,PTR_DAT_42000af0,uVar1,PTR_DAT_42000a54,
               PTR_s_uart_pattern_pop_pos_42000aec,0x232);
    uVar1 = 0xffffffff;
  }
  else {
    puVar3 = PTR_DAT_42000af4 + param_1 * 0x18;
    (*(code *)PTR_FUN_420004dc)(puVar3,0xffffffff);
    iVar4 = *piVar2;
    uVar1 = 0xffffffff;
    iVar5 = *(int *)(iVar4 + 0x30);
    if (iVar5 != *(int *)(iVar4 + 0x2c)) {
      uVar1 = *(undefined4 *)(iVar5 * 4 + *(int *)(iVar4 + 0x38));
      if ((*(int *)(iVar4 + 0x38) != 0) &&
         (*(int *)(iVar4 + 0x30) = iVar5 + 1, *(int *)(iVar4 + 0x34) <= iVar5 + 1)) {
        *(undefined4 *)(iVar4 + 0x30) = 0;
      }
    }
    (*(code *)PTR_FUN_420004e0)(puVar3);
  }
  return uVar1;
}