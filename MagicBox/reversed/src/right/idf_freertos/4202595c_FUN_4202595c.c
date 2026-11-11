// strings: pvt_scheme_ver == 1

uint FUN_4202595c(int param_1)

{
  if (param_1 != 1) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_rtc_init_c_3c031798_0x2d_42001380,0x14a,PTR_s_get_dig_dbias_by_efuse_42001398,
               PTR_s_pvt_scheme_ver____1_42001388);
  }
  memw();
  return *(uint *)(DAT_42001384 + 0x58) >> 0xb & 0x1f;
}