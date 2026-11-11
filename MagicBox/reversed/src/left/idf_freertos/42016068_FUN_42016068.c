undefined4 FUN_42016068(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  uVar2 = DAT_42001440;
  iVar3 = DAT_420013f8;
  param_1 = param_1 & 0xff;
  param_2 = param_2 & 0x7f;
  if ((param_3 == 0) && (param_4 != 0)) {
    uVar4 = 0xffffffff;
  }
  else if ((param_2 == 0) ||
          (memw(), (*(uint *)(*(int *)(param_1 * 8 + DAT_420013e0 + 4) + 0xb00 + param_2 * 0x20) &
                   0x7ff) != 0)) {
    if ((param_3 & 3) == 0) {
      iVar8 = *(int *)(param_1 * 8 + DAT_420013e0 + 4);
      puVar5 = (uint *)(param_2 * 0x20 + iVar8 + 0xb00);
      memw();
      uVar9 = puVar5[4];
      iVar6 = DAT_420013f8 + (param_1 * 0x10 + param_2 + 7) * 0x10;
      *(uint *)(iVar6 + 0xc) = param_3;
      *(uint *)(iVar6 + 0x10) = param_4;
      *(undefined4 *)(iVar6 + 0x14) = 0;
      memw();
      puVar5[4] = uVar9 & uVar2;
      memw();
      memw();
      puVar5[4] = puVar5[4] & 0xfff80000;
      uVar2 = DAT_42000a7c;
      if (param_4 == 0) {
        memw();
        uVar1 = *(ushort *)(iVar6 + 8);
        memw();
        puVar5[4] = puVar5[4] | DAT_42000a7c;
        memw();
        memw();
        puVar5[4] = (uint)uVar1 | puVar5[4];
        memw();
        memw();
        *puVar5 = *puVar5 | DAT_42001444;
      }
      else {
        if (param_2 == 0) {
          iVar6 = iVar3 + param_1 * 0x100;
          uVar9 = (uint)*(ushort *)(iVar6 + 0x78);
          memw();
          uVar7 = puVar5[4];
          uVar9 = (uVar9 < param_4) * uVar9 + (uVar9 >= param_4) * param_4;
          *(uint *)(iVar6 + 0x80) = uVar9;
          memw();
          puVar5[4] = uVar7 | uVar2;
          memw();
          memw();
          puVar5[4] = puVar5[4] | uVar9;
        }
        else {
          memw();
          memw();
          puVar5[4] = (((param_4 - 1) + (uint)*(ushort *)(iVar6 + 8)) / (uint)*(ushort *)(iVar6 + 8)
                      & 0x3ff) << 0x13 | puVar5[4];
          memw();
          memw();
          puVar5[4] = param_4 & 0x7ffff | puVar5[4];
        }
        memw();
        puVar5[5] = param_3;
        if (*(char *)(iVar3 + (param_1 * 0x10 + param_2 + 7) * 0x10 + 10) == '\x01') {
          memw();
          if ((*(uint *)(iVar8 + 0x808) & 0x100) == 0) {
            memw();
            memw();
            *puVar5 = *puVar5 & DAT_42000538;
            memw();
            memw();
            *puVar5 = *puVar5 | DAT_42000540;
          }
          else {
            memw();
            memw();
            *puVar5 = *puVar5 & DAT_42000544;
            memw();
            memw();
            *puVar5 = *puVar5 | DAT_4200143c;
          }
        }
        memw();
        memw();
        *puVar5 = *puVar5 | DAT_42001444;
      }
      uVar4 = 0;
    }
    else {
      uVar4 = 0xfffffffc;
    }
  }
  else {
    uVar4 = 0xfffffffd;
  }
  return uVar4;
}