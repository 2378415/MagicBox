// 420258a0  FUN_420258a0  FUN_420258a0  size=74
// strings: calib_version == 1

void FUN_420258a0(int param_1)

{
  if (param_1 != 1) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_rtc_init_c_3c031798_0x2d_42001380,0xfc,PTR_s_set_ocode_by_efuse_4200137c,
               PTR_s_calib_version____1_42001378);
  }
  memw();
  (*(code *)PTR_FUN_420003c4)(0x61,1,6,7,0,*(uint *)(DAT_42001384 + 0x6c) >> 0xd & 0xff);
  (*(code *)PTR_FUN_420003c4)(0x61,1,5,6);
  return;
}


