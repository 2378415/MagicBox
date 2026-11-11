// 4202ea38  FUN_4202ea38  FUN_4202ea38  size=161
// strings: kStartScheduler | rtScheduler

uint FUN_4202ea38(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  if (param_1 != (uint *)0x0) {
    uVar1 = *param_1;
    uVar3 = param_1[1];
    if (uVar1 < 0x1f) {
      piVar6 = (int *)(uVar1 * -0x14 + 0x1e0 + DAT_42001f48);
      piVar5 = (int *)(PTR_DAT_42001f4c + uVar1 * 4 + -100);
      do {
        piVar4 = piVar6;
        if ((((uVar1 < 0x19) || (piVar4 = (int *)*piVar5, piVar4 != (int *)0x0)) &&
            (iVar2 = (*(code *)PTR_FUN_42001f50)(piVar4), iVar2 != 0)) && (memw(), *piVar4 != 0)) {
          if (uVar3 == 0) {
            memw();
            uVar3 = piVar4[3];
          }
          iVar2 = (*(code *)PTR_FUN_42001f50)(uVar3);
          if (iVar2 != 0) {
            uVar7 = *(uint *)(uVar3 + 0xc);
            iVar2 = (*(code *)PTR_FUN_42001f54)(uVar7);
            uVar8 = 0;
            if (iVar2 == 0) {
              uVar7 = 0;
            }
            memw();
            uVar9 = piVar4[4];
            param_1[2] = uVar7;
            *param_1 = uVar1;
            if (uVar9 == uVar3) {
              *param_1 = uVar1 + 1;
            }
            else {
              memw();
              uVar8 = *(uint *)(uVar3 + 4);
            }
            param_1[1] = uVar8;
            return uVar1;
          }
          uVar3 = 0;
        }
        uVar1 = uVar1 + 1;
        piVar6 = piVar6 + -5;
        piVar5 = piVar5 + 1;
      } while (uVar1 != 0x1f);
    }
  }
  return 0xffffffff;
}


