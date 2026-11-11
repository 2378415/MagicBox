// 4037fc84  FUN_4037fc84  FUN_4037fc84  size=421

undefined4 FUN_4037fc84(int *param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint local_40 [4];
  uint uStack_30;
  int *piStack_2c;
  
  puVar2 = (uint *)param_1[1];
  iVar8 = param_1[5];
  uVar6 = (uint)*(byte *)(param_2 + 0x16);
  if ((*(uint *)(param_2 + 0x10) & 2) != 0) {
    iVar8 = *(int *)(param_2 + 0x18);
  }
  piStack_2c = param_1;
  (**(code **)(*param_1 + 0x3c))
            (param_1,*(undefined2 *)(param_2 + 0x14),*(undefined1 *)(param_2 + 3),uVar6,iVar8);
  memw();
  puVar2[1] = *(uint *)(param_2 + 4);
  if (*(char *)(param_2 + 2) == '\0') {
    memw();
    memw();
    puVar2[6] = puVar2[6] & DAT_403747e0 | (uint)(uVar6 != 0) << 0x1d;
    memw();
    memw();
    puVar2[7] = puVar2[7] & 0xffffffc0 | uVar6 - 1 & 0x3f;
  }
  uVar6 = (uint)*(byte *)(param_2 + 1);
  memw();
  memw();
  puVar2[6] = puVar2[6] & DAT_403747e4 | (uint)(uVar6 != 0) << 0x1b;
  if (uVar6 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = uVar6 * 8 - 1 & 0x3ff;
  }
  memw();
  memw();
  puVar2[9] = uVar6 | puVar2[9] & 0xfffffc00;
  iVar8 = *(int *)(param_2 + 8);
  uVar6 = (uint)*(byte *)(param_2 + 1);
  uStack_30 = uVar6 + 3 >> 2;
  for (iVar4 = 0; iVar4 < (int)uStack_30; iVar4 = iVar4 + 1) {
    local_40[0] = 0;
    iVar7 = (uVar6 < 4) * uVar6 + (uint)(uVar6 >= 4) * 4;
    (*DAT_403744d4)(local_40,iVar8,iVar7);
    memw();
    puVar2[iVar4 + 0x16] = local_40[0];
    uVar6 = uVar6 - iVar7;
    iVar8 = iVar7 + iVar8;
  }
  uVar6 = (uint)*(byte *)(param_2 + 2);
  memw();
  memw();
  puVar2[6] = puVar2[6] & DAT_403747e8 | (uint)(uVar6 != 0) << 0x1c;
  if (uVar6 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = uVar6 * 8 - 1 & 0x3ff;
  }
  memw();
  memw();
  puVar2[10] = uVar6 | puVar2[10] & 0xfffffc00;
  if ((*(uint *)(param_2 + 0x10) & 8) == 0) {
    uVar6 = DAT_403747ec;
  }
  else {
    uVar6 = DAT_40374984;
  }
  memw();
  memw();
  *puVar2 = *puVar2 | uVar6;
  (**(code **)(*piStack_2c + 0x40))();
  uVar6 = (uint)*(byte *)(param_2 + 2);
  if (uVar6 != 0) {
    uVar3 = *(uint *)(param_2 + 0xc);
    if (((uVar3 & 3) == 0) && ((*(byte *)(param_2 + 2) & 3) == 0)) {
      (*DAT_403744d4)(uVar3,puVar2 + 0x16,uVar6);
    }
    else {
      uVar1 = uVar6;
      for (uVar5 = 0; uVar5 < uVar6 + 3 >> 2; uVar5 = uVar5 + 1) {
        iVar8 = (uVar1 < 4) * uVar1 + (uint)(uVar1 >= 4) * 4;
        memw();
        local_40[0] = puVar2[uVar5 + 0x16];
        (*DAT_403744d4)(uVar3,local_40,iVar8);
        uVar3 = iVar8 + uVar3;
        uVar1 = uVar1 - iVar8;
      }
    }
  }
  return 0;
}


