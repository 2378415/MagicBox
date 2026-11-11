void FUN_42009770(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000928,0xffffffff);
  for (iVar1 = 0; iVar1 < *DAT_42000930; iVar1 = iVar1 + 1) {
    puVar2 = *(undefined4 **)(iVar1 * 4 + *DAT_4200092c);
    if (puVar2 != (undefined4 *)0x0) {
      if (param_1 == 1) {
        if ((puVar2[7] & 1) != 0) {
          *(uint *)puVar2[3] = *(uint *)puVar2[3] | 1;
          FUN_4200a6e0(*puVar2,puVar2[1],param_2);
        }
      }
      else if (param_1 == 2) {
        if ((puVar2[9] & 1) != 0) {
          *(uint *)puVar2[4] = *(uint *)puVar2[4] | 1;
          FUN_4200a6e0(*puVar2,puVar2[1],param_2);
        }
      }
      else if ((param_1 == 0) && ((puVar2[5] & 1) != 0)) {
        *(uint *)puVar2[2] = *(uint *)puVar2[2] | 1;
        FUN_4200a6e0(*puVar2,puVar2[1],param_2);
      }
    }
  }
  (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000928);
  return;
}