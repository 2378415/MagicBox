// 42018028  FUN_42018028  FUN_42018028  size=451
// strings: gpio

undefined4 FUN_42018028(uint *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  uVar4 = *param_1;
  uVar3 = param_1[1];
  if ((uVar4 == 0 && uVar3 == 0) || ((uVar4 >> 0x16 & 0xf) != 0 || (uVar3 & 0xfffe0000) != 0)) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(1,PTR_DAT_4200159c,PTR_DAT_4200160c,uVar1,PTR_DAT_4200159c);
    uVar1 = 0x102;
  }
  else {
    uVar5 = 0;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
LAB_42018076:
    do {
      uVar6 = uVar3 * 2 << 0x20 - (0x20 - ((uVar5 ^ 0xffffffff) & 0x1f)) | uVar4 >> (uVar5 & 0x1f);
      if ((uVar5 & 0x20) != 0) {
        uVar6 = uVar3 >> (uVar5 & 0x1f);
      }
      if ((uVar6 & 1) != 0) {
        iVar2 = FUN_42018a24(uVar5);
        if (iVar2 != 0) {
          FUN_42018a40(uVar5);
        }
        if ((param_1[2] & 1) == 0) {
          FUN_4201779c(uVar5);
        }
        else {
          FUN_42017c90();
          uStack_30 = 1;
        }
        if ((param_1[2] & 4) == 0) {
          FUN_42017e6c(uVar5);
        }
        else {
          FUN_42017ef0();
          uStack_3c = 1;
        }
        if ((param_1[2] & 2) == 0) {
          FUN_42017d0c(uVar5);
        }
        else {
          FUN_42017dbc();
          uStack_2c = 1;
        }
        if (param_1[3] == 0) {
          FUN_420178a4(uVar5);
        }
        else {
          FUN_4201780c();
          uStack_38 = 1;
        }
        if (param_1[4] == 0) {
          FUN_420179fc(uVar5);
        }
        else {
          FUN_42017964();
          uStack_34 = 1;
        }
        uVar1 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (3,PTR_DAT_4200159c,PTR_DAT_42001610,uVar1,PTR_DAT_4200159c,uVar5,uStack_30,
                   uStack_2c,uStack_3c,uStack_38,uStack_34,param_1[5]);
        FUN_42017a94(uVar5,param_1[5]);
        if (param_1[5] == 0) {
          FUN_42017c20(uVar5);
        }
        else {
          FUN_42017b88();
        }
        if ((uVar5 - 0x13 & 0xff) < 2) {
          memw();
          memw();
          *DAT_420015cc = *DAT_420015cc & DAT_42000294;
          puVar7 = (uint *)((uVar5 & 0xffff) * 4 + DAT_420015c0);
          memw();
          uVar5 = uVar5 + 1;
          memw();
          *puVar7 = *puVar7 & DAT_42000784 | DAT_42000988;
          goto LAB_42018076;
        }
        puVar7 = (uint *)((uVar5 & 0xffff) * 4 + DAT_420015c0);
        memw();
        memw();
        *puVar7 = *puVar7 & DAT_42000784 | DAT_42000988;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 != 0x31);
    uVar1 = 0;
  }
  return uVar1;
}


