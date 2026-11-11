// 4037f73c  FUN_4037f73c  FUN_4037f73c  size=550
// strings: ;602A

undefined4 FUN_4037f73c(int *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  code *pcVar8;
  uint uVar9;
  int iVar10;
  uint local_40;
  uint uStack_3c;
  uint uStack_30;
  int *piStack_2c;
  
  puVar6 = (uint *)param_1[1];
  cVar1 = *(char *)(param_2 + 0x16);
  if ((*(uint *)(param_2 + 0x10) & 2) == 0) {
    iVar10 = param_1[5];
  }
  else {
    iVar10 = *(int *)(param_2 + 0x18);
  }
  piStack_2c = param_1;
  (**(code **)(*param_1 + 0x3c))
            (param_1,*(undefined2 *)(param_2 + 0x14),*(undefined1 *)(param_2 + 3),cVar1,iVar10);
  iVar10 = *(byte *)(param_2 + 3) - 0x20;
  uVar7 = 0;
  if (iVar10 != 0) {
    uVar7 = 0xffffffff >> (*(byte *)(param_2 + 3) & 0x1f);
  }
  memw();
  puVar6[1] = *(int *)(param_2 + 4) << 0x20 - (0x20 - (-iVar10 & 0x1fU)) | uVar7;
  uVar7 = (uint)*(byte *)(param_2 + 2);
  if (uVar7 == 0) {
    memw();
    memw();
    puVar6[4] = puVar6[4] & DAT_40374864 | (uint)(cVar1 != '\0') << 0x1d;
    memw();
    memw();
    memw();
    uStack_3c = puVar6[5] & 0xffffff00 | (uint)(byte)(cVar1 - 1);
    memw();
    memw();
    memw();
    puVar6[5] = uStack_3c;
    uVar9 = (uint)*(byte *)(param_2 + 1);
    memw();
    memw();
    puVar6[4] = puVar6[4] & DAT_40374868 | (uint)(uVar9 != 0) << 0x1b;
    if (uVar9 == 0) {
      memw();
      memw();
      puVar6[4] = puVar6[4] & DAT_4037486c;
      goto LAB_4037f8c4;
    }
LAB_4037f834:
    memw();
    memw();
    puVar6[7] = (uint)(CONCAT44(puVar6[7] >> 0x12,(uVar9 * 8 + -1) * 0x4000) >> 0xe);
    uStack_30 = uVar9 + 3 >> 2;
    iVar3 = *(int *)(param_2 + 8);
    iVar10 = 0;
    do {
      iVar5 = (uVar9 < 4) * uVar9 + (uint)(uVar9 >= 4) * 4;
      local_40 = 0;
      (*DAT_4037450c)(&local_40,iVar3,iVar5);
      memw();
      puVar6[iVar10 + 0x26] = local_40;
      iVar10 = iVar10 + 1;
      uVar9 = uVar9 - iVar5;
      iVar3 = iVar3 + iVar5;
    } while (iVar10 < (int)uStack_30);
    uVar7 = (uint)*(byte *)(param_2 + 2);
    memw();
    memw();
    puVar6[4] = puVar6[4] & DAT_4037486c | (uint)(uVar7 != 0) << 0x1c;
    if (uVar7 == 0) goto LAB_4037f8c4;
  }
  else {
    uVar9 = (uint)*(byte *)(param_2 + 1);
    memw();
    memw();
    puVar6[4] = puVar6[4] & DAT_40374868 | (uint)(uVar9 != 0) << 0x1b;
    if (uVar9 != 0) goto LAB_4037f834;
    memw();
    memw();
    puVar6[4] = puVar6[4] | DAT_403745e0;
  }
  memw();
  memw();
  puVar6[7] = (uint)(CONCAT44(puVar6[7] >> 0x12,(uVar7 * 8 + -1) * 0x4000) >> 0xe);
LAB_4037f8c4:
  memw();
  memw();
  *puVar6 = *puVar6 | DAT_403751a0;
  do {
    memw();
  } while ((*puVar6 & 0x800000) != 0);
  memw();
  pcVar8 = *(code **)(*piStack_2c + 0x40);
  memw();
  *puVar6 = *puVar6 | DAT_40374920;
  (*pcVar8)(piStack_2c);
  uVar7 = (uint)*(byte *)(param_2 + 2);
  if (uVar7 != 0) {
    uVar9 = *(uint *)(param_2 + 0xc);
    if (((uVar9 & 3) == 0) && ((*(byte *)(param_2 + 2) & 3) == 0)) {
      (*DAT_4037450c)(uVar9,puVar6 + 0x26,uVar7);
    }
    else {
      uVar2 = uVar7 + 3;
      uVar4 = 0;
      do {
        memw();
        local_40 = puVar6[uVar4 + 0x26];
        iVar10 = (uVar7 < 4) * uVar7 + (uint)(uVar7 >= 4) * 4;
        uVar4 = uVar4 + 1;
        (*DAT_4037450c)(uVar9,&local_40,iVar10);
        uVar9 = uVar9 + iVar10;
        uVar7 = uVar7 - iVar10;
      } while (uVar4 != uVar2 >> 2);
    }
  }
  return 0;
}


