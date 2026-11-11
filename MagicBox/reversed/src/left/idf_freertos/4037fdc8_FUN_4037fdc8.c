// strings: ;502A

undefined4 FUN_4037fdc8(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  code *pcVar8;
  int iVar9;
  uint local_40 [4];
  uint uStack_30;
  int *piStack_2c;
  
  puVar6 = (uint *)param_1[1];
  uVar3 = (uint)*(byte *)(param_2 + 0x16);
  if ((*(uint *)(param_2 + 0x10) & 2) == 0) {
    iVar9 = param_1[5];
  }
  else {
    iVar9 = *(int *)(param_2 + 0x18);
  }
  piStack_2c = param_1;
  (**(code **)(*param_1 + 0x3c))
            (param_1,*(undefined2 *)(param_2 + 0x14),*(undefined1 *)(param_2 + 3),uVar3,iVar9);
  memw();
  puVar6[1] = *(uint *)(param_2 + 4);
  uVar7 = (uint)*(byte *)(param_2 + 2);
  if (uVar7 == 0) {
    memw();
    memw();
    puVar6[6] = puVar6[6] & DAT_40374864 | (uint)(uVar3 != 0) << 0x1d;
    memw();
    memw();
    puVar6[7] = puVar6[7] & 0xffffffc0 | uVar3 - 1 & 0x3f;
  }
  uVar3 = (uint)*(byte *)(param_2 + 1);
  memw();
  memw();
  puVar6[6] = puVar6[6] & DAT_40374868 | (uint)(uVar3 != 0) << 0x1b;
  if (uVar3 == 0) {
    memw();
    memw();
    puVar6[9] = puVar6[9] & 0xfffffc00;
  }
  else {
    memw();
    memw();
    puVar6[9] = puVar6[9] & 0xfffffc00 | uVar3 * 8 - 1 & 0x3ff;
    uStack_30 = uVar3 + 3 >> 2;
    iVar2 = *(int *)(param_2 + 8);
    iVar9 = 0;
    do {
      iVar4 = (uVar3 < 4) * uVar3 + (uint)(uVar3 >= 4) * 4;
      local_40[0] = 0;
      (*DAT_4037450c)(local_40,iVar2,iVar4);
      memw();
      puVar6[iVar9 + 0x16] = local_40[0];
      iVar9 = iVar9 + 1;
      uVar3 = uVar3 - iVar4;
      iVar2 = iVar2 + iVar4;
    } while (iVar9 < (int)uStack_30);
    uVar7 = (uint)*(byte *)(param_2 + 2);
  }
  memw();
  memw();
  puVar6[6] = puVar6[6] & DAT_4037486c | (uint)(uVar7 != 0) << 0x1c;
  memw();
  uVar3 = 0;
  if (uVar7 != 0) {
    uVar3 = uVar7 * 8 - 1 & 0x3ff;
  }
  memw();
  puVar6[10] = puVar6[10] & 0xfffffc00 | uVar3;
  memw();
  uVar3 = DAT_40374870;
  if ((*(uint *)(param_2 + 0x10) >> 3 & 1) != 0) {
    uVar3 = DAT_40374a34;
  }
  pcVar8 = *(code **)(*piStack_2c + 0x40);
  memw();
  *puVar6 = *puVar6 | uVar3;
  (*pcVar8)(piStack_2c);
  uVar3 = (uint)*(byte *)(param_2 + 2);
  if (uVar3 != 0) {
    uVar7 = *(uint *)(param_2 + 0xc);
    if (((uVar7 & 3) == 0) && ((*(byte *)(param_2 + 2) & 3) == 0)) {
      (*DAT_4037450c)(uVar7,puVar6 + 0x16,uVar3);
    }
    else {
      uVar1 = uVar3 + 3;
      uVar5 = 0;
      do {
        memw();
        local_40[0] = puVar6[uVar5 + 0x16];
        iVar9 = (uVar3 < 4) * uVar3 + (uint)(uVar3 >= 4) * 4;
        uVar5 = uVar5 + 1;
        (*DAT_4037450c)(uVar7,local_40,iVar9);
        uVar7 = uVar7 + iVar9;
        uVar3 = uVar3 - iVar9;
      } while (uVar5 != uVar1 >> 2);
    }
  }
  return 0;
}