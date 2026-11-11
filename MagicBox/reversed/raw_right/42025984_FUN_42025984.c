// 42025984  FUN_42025984  FUN_42025984  size=191
// strings: pvt_scheme_ver == 1

void FUN_42025984(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  if (param_1 != 1) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_rtc_init_c_3c031798_0x2d_42001380,0x150,PTR_s_get_rtc_dbias_by_efuse_4200139c,
               PTR_s_pvt_scheme_ver____1_42001388);
  }
  memw();
  uVar3 = *(uint *)(DAT_42001384 + 0x54) >> 0xd;
  uVar7 = uVar3 & 0x7f;
  memw();
  uVar1 = *(uint *)(DAT_42001384 + 0x54) >> 0x14;
  uVar6 = uVar1 & 0x7f;
  memw();
  memw();
  uVar5 = (*(uint *)(DAT_42001384 + 0x58) & 7) * 0x20 + (*(uint *)(DAT_42001384 + 0x54) >> 0x1b);
  memw();
  uVar2 = *(uint *)(DAT_42001384 + 0x58) >> 3;
  uVar4 = uVar2 & 0xff;
  if (0x3f < uVar7) {
    uVar7 = -(uVar3 & 0x3f);
  }
  if (0x3f < uVar6) {
    uVar6 = -(uVar1 & 0x3f);
  }
  if ((uVar5 & 0x80) != 0) {
    uVar5 = -(uVar5 & 0x7f);
  }
  if ((uVar2 & 0x80) != 0) {
    uVar4 = -(uVar2 & 0x7f);
  }
  for (uVar3 = 0xf;
      (uVar3 < 0x1f &&
      ((uVar7 + 0xc6) * (uVar3 - 0x14) + uVar5 * 0x14 + DAT_420013a0 <
       ((uVar6 + 0xd3) * (param_2 + -0x14) + uVar4 * 0x14 + DAT_42001390) - 0xfa));
      uVar3 = uVar3 + 1) {
  }
  return;
}


