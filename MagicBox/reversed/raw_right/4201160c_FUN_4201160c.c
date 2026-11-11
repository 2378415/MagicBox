// 4201160c  FUN_4201160c  FUN_4201160c  size=304

undefined4 FUN_4201160c(uint *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  
  uVar3 = *param_1;
  uVar4 = param_1[1];
  if (uVar3 == 0 && uVar4 == 0) {
    uVar2 = 0x102;
  }
  else if ((uVar3 >> 0x16 & 0xf) == 0 && uVar4 >> 0x11 == 0) {
    uVar5 = 0;
    do {
      uVar6 = uVar4 * 2 << 0x20 - (0x20 - ((uVar5 ^ 0xffffffff) & 0x1f)) | uVar3 >> (uVar5 & 0x1f);
      if ((uVar5 & 0x20) != 0) {
        uVar6 = uVar4 >> (uVar5 & 0x1f);
      }
      if ((uVar6 & 1) != 0) {
        iVar1 = FUN_42011b5c(uVar5);
        if (iVar1 != 0) {
          FUN_42011b90(uVar5);
        }
        if ((param_1[2] & 1) == 0) {
          FUN_42010b8c(uVar5);
        }
        else {
          FUN_4201131c(uVar5);
        }
        if ((param_1[2] & 4) == 0) {
          FUN_420114a8(uVar5);
        }
        else {
          FUN_42011508(uVar5);
        }
        if ((param_1[2] & 2) == 0) {
          FUN_42011378(uVar5);
        }
        else {
          FUN_42011410(uVar5);
        }
        if (param_1[3] == 0) {
          FUN_42010fb4(uVar5);
        }
        else {
          FUN_42010f38(uVar5);
        }
        if (param_1[4] == 0) {
          FUN_420110d4(uVar5);
        }
        else {
          FUN_42011058(uVar5);
        }
        FUN_42011150(uVar5,param_1[5]);
        if (param_1[5] == 0) {
          FUN_420112c4(uVar5);
        }
        else {
          FUN_42011244(uVar5);
        }
        if (((uVar5 & 0xff) - 0x13 & 0xff) < 2) {
          memw();
          memw();
          *DAT_42000df4 = *DAT_42000df4 & DAT_4200016c;
        }
        puVar7 = (uint *)(((uVar5 & 0xff) + DAT_42000de8) * 4);
        memw();
        memw();
        *puVar7 = *puVar7 & DAT_4200052c | DAT_4200077c;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0x31);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x102;
  }
  return uVar2;
}


