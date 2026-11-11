// 4201acb0  esp_clk_tree_src_get_freq_hz  FUN_4201acb0  size=281
// strings: esp_clk_tree_src_get_freq_hz | esp_clk_tree

undefined4 FUN_4201acb0(uint param_1,uint param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  if (0xb < param_1 - 1) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar3 = 0x15;
    puVar4 = PTR_DAT_420019e8;
LAB_4201ace4:
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_esp_clk_tree_420019e4,puVar4,uVar1,PTR_s_esp_clk_tree_420019e4,
               PTR_s_esp_clk_tree_src_get_freq_hz_420019e0,uVar3);
    return 0x102;
  }
  if (2 < param_2) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar3 = 0x16;
    puVar4 = PTR_DAT_420019ec;
    goto LAB_4201ace4;
  }
  if (param_3 == (int *)0x0) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar3 = 0x17;
    puVar4 = PTR_DAT_420019f0;
    goto LAB_4201ace4;
  }
  iVar2 = DAT_42001978;
  if (param_1 == 7) {
    memw();
    if ((*DAT_42001984 >> 2 & 1) != 0) {
      iVar2 = DAT_42001974;
    }
    goto LAB_4201adce;
  }
  if (param_1 < 8) {
    if (param_1 == 4) {
      iVar2 = FUN_4201a880();
    }
    else {
      if (4 < param_1) {
        if (param_1 == 5) {
          iVar2 = DAT_4200194c;
        }
        goto LAB_4201adce;
      }
      if (param_1 == 2) {
        iVar2 = FUN_420079a4(param_2);
      }
      else if (param_1 == 3) {
        iVar2 = FUN_420078e0(param_2);
      }
      else {
        iVar2 = FUN_4201a7d8();
      }
    }
  }
  else if (param_1 == 10) {
    iVar2 = FUN_42007848(param_2);
  }
  else if (param_1 < 0xb) {
    if (param_1 == 8) {
      iVar2 = FUN_42007894(param_2);
    }
    else {
LAB_4201ad90:
      iVar2 = FUN_42007950(param_2);
    }
  }
  else {
    if (param_1 != 0xb) goto LAB_4201ad90;
    iVar2 = FUN_4201a798();
    iVar2 = iVar2 * DAT_4200087c;
  }
  if (iVar2 == 0) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_esp_clk_tree_420019e4,PTR_DAT_420019f4,uVar1,PTR_s_esp_clk_tree_420019e4,
               PTR_s_esp_clk_tree_src_get_freq_hz_420019e0,0x41);
    return 0xffffffff;
  }
LAB_4201adce:
  *param_3 = iVar2;
  return 0;
}


