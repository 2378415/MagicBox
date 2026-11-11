// 42008220  FUN_42008220  FUN_42008220  size=188

void FUN_42008220(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  
  uVar2 = FUN_4200b638();
  (*(code *)PTR_FUN_420004dc)(uVar2,0xffffffff);
  if (param_1 != 0) {
    (*(code *)PTR_FUN_420004dc)(PTR_DAT_4200097c,0xffffffff);
    uVar2 = DAT_42000988;
    puVar1 = DAT_42000984;
    piVar5 = DAT_42000980;
    if ((0 < *DAT_42000980) && (piVar6 = (int *)*DAT_42000984, param_1 == *piVar6)) {
      iVar3 = *DAT_42000980 + -1;
      *piVar6 = piVar6[iVar3];
      uVar2 = (*(code *)PTR_FUN_42000990)(piVar6,iVar3 * 4,uVar2);
      *puVar1 = uVar2;
      *piVar5 = iVar3;
    }
    (*(code *)PTR_FUN_420004e0)(PTR_DAT_4200097c);
  }
  uVar7 = 0;
  while (((uVar4 = 1 << 0x20 - (0x20 - (uVar7 & 0x1f)), (*(uint *)(param_1 + 0x14) & uVar4) == 0 &&
          ((uVar4 & *(uint *)(param_1 + 0x1c)) == 0)) && ((uVar4 & *(uint *)(param_1 + 0x24)) == 0))
        ) {
    uVar7 = uVar7 + 1;
    if (uVar7 == 3) {
LAB_420082ca:
      FUN_4200b638();
      (*(code *)PTR_FUN_420004e0)();
LAB_420082d3:
      (*(code *)PTR_FUN_42000570)(param_1);
      return;
    }
  }
  piVar5 = (int *)(uVar7 * 4 + DAT_4200098c);
  iVar3 = *piVar5 + -1;
  *piVar5 = iVar3;
  if (iVar3 == 0) {
    FUN_4200b620();
    FUN_4200b638();
    (*(code *)PTR_FUN_420004e0)();
    goto LAB_420082d3;
  }
  goto LAB_420082ca;
}


