void FUN_4200b818(int param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint *puVar7;
  
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_42000bf4,0xffffffff);
  piVar2 = DAT_42000bfc;
  piVar1 = DAT_42000bf8;
  if (0 < *DAT_42000bf8) {
    iVar3 = 0;
    do {
      puVar4 = *(undefined4 **)(iVar3 * 4 + *piVar2);
      if (puVar4 != (undefined4 *)0x0) {
        if (param_1 == 1) {
          if ((puVar4[7] & 1) != 0) {
            uVar5 = *puVar4;
            uVar6 = puVar4[1];
            *(uint *)puVar4[3] = *(uint *)puVar4[3] | 1;
            FUN_4200c7a4(uVar5,uVar6,param_2);
          }
        }
        else if (param_1 == 2) {
          if ((puVar4[9] & 1) != 0) {
            puVar7 = (uint *)puVar4[4];
            goto LAB_4200b877;
          }
        }
        else if ((param_1 == 0) && ((puVar4[5] & 1) != 0)) {
          puVar7 = (uint *)puVar4[2];
LAB_4200b877:
          uVar5 = *puVar4;
          uVar6 = puVar4[1];
          *puVar7 = *puVar7 | 1;
          FUN_4200c7a4(uVar5,uVar6,param_2);
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *piVar1);
  }
  (*(code *)PTR_FUN_420004e0)(PTR_DAT_42000bf4);
  return;
}