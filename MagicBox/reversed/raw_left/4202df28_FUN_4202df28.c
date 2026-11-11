// 4202df28  FUN_4202df28  FUN_4202df28  size=174

undefined4 FUN_4202df28(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  memw();
  memw();
  memw();
  memw();
  memw();
  uVar1 = *(uint *)(DAT_420004f0 + 0x58) >> 3;
  uVar6 = *(uint *)(DAT_420004f0 + 0x54) >> 0xd;
  uVar7 = uVar6 & 0x7f;
  uVar2 = *(uint *)(DAT_420004f0 + 0x54) >> 0x14;
  uVar5 = uVar2 & 0x7f;
  uVar4 = (uint)((CONCAT44(*(undefined4 *)(DAT_420004f0 + 0x58),*(undefined4 *)(DAT_420004f0 + 0x54)
                          ) & 0x7ffffffff) >> 0x1b);
  if (0x3f < uVar7) {
    uVar7 = -(uVar6 & 0x3f);
  }
  if (0x3f < uVar5) {
    uVar5 = -(uVar2 & 0x3f);
  }
  uVar6 = uVar1 & 0xff;
  if ((char)uVar1 < '\0') {
    uVar6 = -(uVar1 & 0x7f);
  }
  if (uVar4 >> 7 != 0) {
    uVar4 = -(uVar4 & 0x7f);
  }
  uVar3 = 0xf;
  if (uVar4 * 0x14 + (uVar7 + 0xc6) * -5 + DAT_42001e24 <
      (param_1 + -0x14) * (uVar5 + 0xd3) + -0xfa + uVar6 * 0x14 + DAT_42001e20) {
    uVar3 = 0x10;
  }
  return uVar3;
}


