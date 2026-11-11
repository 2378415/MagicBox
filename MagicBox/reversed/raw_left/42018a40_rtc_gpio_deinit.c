// 42018a40  rtc_gpio_deinit  FUN_42018a40  size=115
// strings: rtc_gpio_deinit

undefined4 FUN_42018a40(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  if ((param_1 < 0x31) && (iVar2 = *(int *)(PTR_DAT_42000710 + param_1 * 4), -1 < iVar2)) {
    (*(code *)PTR_FUN_420004dc)(PTR_DAT_4200167c,0xffffffff);
    puVar3 = *(uint **)(PTR_DAT_42000718 + iVar2 * 0x38);
    memw();
    uVar4 = *puVar3;
    memw();
    *puVar3 = *(uint *)((int)(PTR_DAT_42000718 + iVar2 * 0x38) + 4) & uVar4 ^ uVar4;
    FUN_4201ac44(param_1);
    (*(code *)PTR_FUN_420004e0)(PTR_DAT_4200167c);
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_RTCIO_42001684,PTR_DAT_42001688,uVar1,PTR_s_RTCIO_42001684,
               PTR_s_rtc_gpio_deinit_42001680,0x3d);
    uVar1 = 0x102;
  }
  return uVar1;
}


