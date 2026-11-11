// strings: esp_cache_get_alignment

undefined4 FUN_4037a1d4(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = FUN_40381bb0();
    FUN_40381c18(1,PTR_s_cache_40374b48,PTR_DAT_40374b4c,uVar1,PTR_s_cache_40374b48,
                 PTR_s_esp_cache_get_alignment_40374b44,0x10f);
    uVar1 = 0x102;
  }
  else {
    uVar1 = FUN_4037f028(param_1 >> 10 & 1,0);
    *param_2 = uVar1;
    uVar1 = 0;
  }
  return uVar1;
}