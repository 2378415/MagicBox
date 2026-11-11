void FUN_42011ae8(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    if ((*(int *)(PTR_DAT_42000518 + 0x4c) == param_1) ||
       (*(int *)(PTR_DAT_42000518 + 0x50) == param_1)) {
      memw();
      memw();
      *(uint *)(DAT_42000190 + 0x18) = *(uint *)(DAT_42000190 + 0x18) & DAT_4200016c;
    }
    puVar1 = *(uint **)(PTR_DAT_42000520 + param_1 * 0x38);
    memw();
    memw();
    *puVar1 = *puVar1 | *(uint *)((int)(PTR_DAT_42000520 + param_1 * 0x38) + 4);
    FUN_42011ab0(param_1,0);
  }
  else if (param_2 == 1) {
    puVar1 = *(uint **)(PTR_DAT_42000520 + param_1 * 0x38);
    memw();
    uVar2 = *puVar1;
    memw();
    *puVar1 = *(uint *)((int)(PTR_DAT_42000520 + param_1 * 0x38) + 4) & uVar2 ^ uVar2;
  }
  return;
}