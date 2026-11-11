// 420258ec  FUN_420258ec  FUN_420258ec  size=111
// strings: pvt_scheme_ver == 1

void FUN_420258ec(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 != 1) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_rtc_init_c_3c031798_0x2d_42001380,0x16c,
               PTR_s_get_dig1v3_dbias_by_efuse_4200138c,PTR_s_pvt_scheme_ver____1_42001388);
  }
  memw();
  uVar2 = *(uint *)(DAT_42001384 + 0x54) >> 0x14;
  uVar4 = uVar2 & 0x7f;
  memw();
  uVar1 = *(uint *)(DAT_42001384 + 0x58) >> 3;
  uVar3 = uVar1 & 0xff;
  if (0x3f < uVar4) {
    uVar4 = -(uVar2 & 0x3f);
  }
  if ((uVar1 & 0x80) != 0) {
    uVar3 = -(uVar1 & 0x7f);
  }
  for (uVar2 = 0xf;
      (uVar2 < 0x1f &&
      ((uVar4 + 0xd3) * (uVar2 - 0x14) + uVar3 * 0x14 + DAT_42001390 <= DAT_42001394));
      uVar2 = uVar2 + 1) {
  }
  return;
}


