// strings: s_sleep_sub_mode_ref_cnt[mode] >= 0 | sleep_modes.c | esp_sleep_sub_mode_config

undefined4 FUN_42005b3c(uint param_1,char param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 < 7) {
    iVar1 = (*(code *)PTR_FUN_42000394)();
    if (iVar1 == 0) {
      (*(code *)PTR_FUN_420003a8)(PTR_DAT_4200065c,0xffffffff);
    }
    else {
      (*(code *)PTR_FUN_420003a8)(PTR_DAT_4200065c,0xffffffff);
    }
    if (param_2 == '\0') {
      *(int *)(PTR_DAT_42000660 + param_1 * 4) = *(int *)(PTR_DAT_42000660 + param_1 * 4) + -1;
    }
    else {
      *(int *)(PTR_DAT_42000660 + param_1 * 4) = *(int *)(PTR_DAT_42000660 + param_1 * 4) + 1;
    }
    if (*(int *)(PTR_DAT_42000660 + param_1 * 4) < 0) {
      (*(code *)PTR_FUN_42000044)
                (PTR_s_sleep_modes_c_3c0320e8_0x20_42000670,DAT_4200066c,
                 PTR_s_esp_sleep_sub_mode_config_42000668,
                 PTR_s_s_sleep_sub_mode_ref_cnt_mode__>_42000664);
    }
    iVar1 = (*(code *)PTR_FUN_42000394)();
    if (iVar1 == 0) {
      (*(code *)PTR_FUN_420003ac)(PTR_DAT_4200065c);
      uVar2 = 0;
    }
    else {
      (*(code *)PTR_FUN_420003ac)(PTR_DAT_4200065c);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0x102;
  }
  return uVar2;
}