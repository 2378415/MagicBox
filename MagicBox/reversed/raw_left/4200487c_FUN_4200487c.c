// 4200487c  FUN_4200487c  FUN_4200487c  size=120

void FUN_4200487c(undefined4 param_1,uint param_2)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  
  puVar3 = DAT_42000590;
  puVar2 = DAT_42000578;
  uVar5 = *DAT_42000590;
  uVar6 = *DAT_42000578;
  uVar4 = uVar5 + 1;
  *DAT_42000590 = uVar4;
  puVar1 = DAT_42000574;
  uVar5 = uVar5 << 3;
  if (uVar6 < 0x1f) {
    puVar8 = DAT_42000574 + uVar6 * 2;
    *puVar8 = param_1;
    puVar8[1] = param_2 & 7 | uVar5;
    *puVar2 = uVar6 + 1;
  }
  else {
    *DAT_42000574 = param_1;
    puVar1[1] = param_2 & 7 | uVar5;
    FUN_420046e8(0);
  }
  if (uVar4 == DAT_42000594) {
    uVar5 = *puVar2;
    iVar7 = 0;
    uVar4 = uVar5;
    do {
      puVar1[iVar7 * 2 + 1] = puVar1[iVar7 * 2 + 1] & 7 | iVar7 << 3;
      iVar7 = iVar7 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
    *puVar3 = uVar5;
  }
  return;
}


