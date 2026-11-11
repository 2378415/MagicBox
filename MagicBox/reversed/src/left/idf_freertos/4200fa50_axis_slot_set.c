void axis_slot_set(int param_1,int param_2,uint param_3)

{
  undefined *puVar1;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x210) != 0)) && (param_2 - 1U < 0x10)) {
    (*(code *)PTR_FUN_420004dc)(PTR_DAT_42000e50,0xffffffff);
    puVar1 = PTR_DAT_42000e50;
    *(uint *)(param_2 * 4 + *(int *)(param_1 + 0x210) + 0x9c) = param_3 & 0xff;
    (*(code *)PTR_FUN_420004e0)(puVar1);
    FUN_4202d150(param_1,param_2);
    memw();
    memw();
    *DAT_42000e04 = 1;
    memw();
    if (*DAT_42000e08 != 0) {
      (*(code *)PTR_FUN_42000484)(*DAT_42000e08,0,0,2);
    }
  }
  return;
}