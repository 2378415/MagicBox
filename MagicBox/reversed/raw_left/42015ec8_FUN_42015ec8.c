// 42015ec8  FUN_42015ec8  FUN_42015ec8  size=415

undefined4 FUN_42015ec8(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  iVar1 = DAT_420013f8;
  param_1 = param_1 & 0xff;
  param_2 = param_2 & 0x7f;
  if ((param_3 == 0) && (param_4 != 0)) {
    uVar2 = 0xffffffff;
  }
  else if ((param_2 == 0) ||
          (memw(), (*(uint *)(*(int *)(param_1 * 8 + DAT_420013e0 + 4) + 0x900 + param_2 * 0x20) &
                   0x7ff) != 0)) {
    if ((param_3 & 3) == 0) {
      iVar7 = *(int *)(param_1 * 8 + DAT_420013e0 + 4);
      puVar3 = (uint *)(param_2 * 0x20 + iVar7 + 0x900);
      iVar4 = DAT_420013f8 + (param_1 * 0x10 + param_2) * 0x10;
      memw();
      uVar5 = puVar3[4];
      *(undefined4 *)(iVar4 + 0x14) = 0;
      uVar6 = DAT_42001440;
      *(uint *)(iVar4 + 0xc) = param_3;
      *(uint *)(iVar4 + 0x10) = param_4;
      memw();
      puVar3[4] = uVar5 & uVar6;
      memw();
      memw();
      puVar3[4] = puVar3[4] & 0xfff80000;
      if (param_4 == 0) {
        memw();
        memw();
        puVar3[4] = puVar3[4] | DAT_42000a7c;
        memw();
        memw();
        *puVar3 = *puVar3 | DAT_42001444;
      }
      else {
        if (param_2 == 0) {
          iVar4 = iVar1 + param_1 * 0x100;
          uVar6 = (uint)*(ushort *)(iVar4 + 8);
          memw();
          uVar5 = puVar3[4];
          uVar6 = (uVar6 < param_4) * uVar6 + (uVar6 >= param_4) * param_4;
          *(uint *)(iVar4 + 0x10) = uVar6;
          memw();
          puVar3[4] = uVar5 | DAT_42000a7c;
          memw();
          memw();
          puVar3[4] = puVar3[4] | uVar6;
        }
        else {
          memw();
          memw();
          puVar3[4] = (((param_4 - 1) + (uint)*(ushort *)(iVar4 + 8)) / (uint)*(ushort *)(iVar4 + 8)
                      & 0x3ff) << 0x13 | puVar3[4];
          memw();
          memw();
          puVar3[4] = param_4 & 0x7ffff | puVar3[4];
        }
        uVar5 = DAT_4200143c;
        uVar6 = DAT_42000540;
        if (*(char *)(iVar1 + (param_1 * 0x10 + param_2) * 0x10 + 10) == '\x01') {
          memw();
          if ((*(uint *)(iVar7 + 0x808) & 0x100) == 0) {
            memw();
            memw();
            *puVar3 = *puVar3 & DAT_42000538;
            memw();
            memw();
            *puVar3 = *puVar3 | uVar6;
          }
          else {
            memw();
            memw();
            *puVar3 = *puVar3 & DAT_42000544;
            uVar6 = DAT_42000540;
            memw();
            memw();
            *puVar3 = *puVar3 | uVar5;
          }
          memw();
          memw();
          puVar3[4] = puVar3[4] & DAT_4200140c;
          memw();
          memw();
          puVar3[4] = puVar3[4] | uVar6;
        }
        memw();
        puVar3[5] = param_3;
        memw();
        memw();
        *puVar3 = *puVar3 | DAT_42001444;
      }
      uVar2 = 0;
    }
    else {
      uVar2 = 0xfffffffc;
    }
  }
  else {
    uVar2 = 0xfffffffd;
  }
  return uVar2;
}


