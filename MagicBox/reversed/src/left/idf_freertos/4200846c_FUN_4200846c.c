// strings: '9E  | '9, 

void FUN_4200846c(uint param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  uint *puVar9;
  
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_4200097c,0xffffffff);
  piVar2 = DAT_42000984;
  piVar1 = DAT_42000980;
  if (0 < *DAT_42000980) {
    iVar3 = 0;
    do {
      puVar4 = *(undefined4 **)(iVar3 * 4 + *piVar2);
      if (puVar4 != (undefined4 *)0x0) {
        if (param_2 == 1) {
          if ((param_1 < 0x40) &&
             (uVar6 = 1 << 0x20 - (0x20 - (param_1 & 0x1f)),
             (uVar6 & puVar4[(param_1 >> 5) + 7]) != 0)) {
            iVar8 = puVar4[3];
            goto LAB_420084ed;
          }
        }
        else if (param_2 == 2) {
          if ((param_1 < 0x40) &&
             (uVar6 = 1 << 0x20 - (0x20 - (param_1 & 0x1f)),
             (uVar6 & puVar4[(param_1 >> 5) + 9]) != 0)) {
            iVar8 = puVar4[4];
            goto LAB_420084ed;
          }
        }
        else if (((param_2 == 0) && (param_1 < 0x40)) &&
                (uVar6 = 1 << 0x20 - (0x20 - (param_1 & 0x1f)),
                (uVar6 & puVar4[(param_1 >> 5) + 5]) != 0)) {
          iVar8 = puVar4[2];
LAB_420084ed:
          puVar9 = (uint *)((param_1 >> 5 & 0xffff) * 4 + iVar8);
          uVar5 = *puVar4;
          uVar7 = puVar4[1];
          *puVar9 = *puVar9 | uVar6;
          FUN_4200c7a4(uVar5,uVar7,param_3);
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *piVar1);
  }
  (*(code *)PTR_FUN_420004e0)(PTR_DAT_4200097c);
  return;
}