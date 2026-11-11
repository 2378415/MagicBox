// 420046e8  FUN_420046e8  FUN_420046e8  size=82

void FUN_420046e8(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  iVar1 = DAT_42000574;
  if (param_1 < 0xf) {
    do {
      iVar6 = param_1 * 2 + 2;
      iVar4 = param_1 * 2 + 1;
      puVar2 = (undefined4 *)(param_1 * 8 + iVar1);
      param_1 = iVar6;
      if (*(uint *)(iVar4 * 8 + iVar1 + 4) >> 3 < *(uint *)(iVar6 * 8 + iVar1 + 4) >> 3) {
        param_1 = iVar4;
      }
      puVar3 = (undefined4 *)(iVar1 + param_1 * 8);
      uVar8 = puVar3[1];
      uVar7 = *puVar2;
      uVar5 = puVar2[1];
      *puVar2 = *puVar3;
      puVar2[1] = uVar8;
      *puVar3 = uVar7;
      puVar3[1] = uVar5;
    } while (param_1 < 0xf);
  }
  return;
}


