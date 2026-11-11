void channel_slot_set(int param_1,int param_2,uint param_3)

{
  undefined *puVar1;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x210) != 0)) && (param_2 - 1U < 5)) {
    (*(code *)PTR_FUN_420004dc)(PTR_DAT_42000e50,0xffffffff);
    puVar1 = PTR_DAT_42000e50;
    *(uint *)(param_2 * 4 + *(int *)(param_1 + 0x210) + 0x54) = param_3 & 0xff;
    (*(code *)PTR_FUN_420004e0)(puVar1);
  }
  return;
}