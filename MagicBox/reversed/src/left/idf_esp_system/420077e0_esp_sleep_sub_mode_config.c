// strings: s_sleep_sub_mode_ref_cnt[mode] >= 0 | sleep_modes.c | esp_sleep_sub_mode_config

undefined4 FUN_420077e0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  (*(code *)PTR_FUN_420004c8)();
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_42000848,0xffffffff);
  iVar1 = *(int *)(PTR_DAT_4200084c + param_1 * 4);
  iVar2 = iVar1 + -1;
  if (param_2 != 0) {
    iVar2 = iVar1 + 1;
  }
  *(int *)(PTR_DAT_4200084c + param_1 * 4) = iVar2;
  if (iVar2 < 0) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_sleep_modes_c_3c034850_0x20_4200085c,DAT_42000858,
               PTR_s_esp_sleep_sub_mode_config_42000854,
               PTR_s_s_sleep_sub_mode_ref_cnt_mode__>_42000850);
  }
  (*(code *)PTR_FUN_420004c8)();
  (*(code *)PTR_FUN_420004e0)(PTR_DAT_42000848);
  return 0;
}