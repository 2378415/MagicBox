// 42005a00  Enable  FUN_42005a00  size=141
// strings: Enable | sleep_gpio | Disable

void FUN_42005a00(char param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined *puVar7;
  
  if (2 < *(uint *)PTR_DAT_42000028) {
    uVar4 = (*(code *)PTR_FUN_4200005c)();
    puVar7 = PTR_s_Disable_42000704;
    if (param_1 != '\0') {
      puVar7 = PTR_s_Enable_42000700;
    }
    (*DAT_42000060)(PTR_DAT_42000708,uVar4,PTR_s_sleep_gpio_420006e8,puVar7);
  }
  uVar3 = DAT_420006f8;
  uVar2 = DAT_420006f4;
  iVar1 = DAT_420006f0;
  uVar5 = 0;
  do {
    uVar6 = iVar1 << 0x20 - (0x20 - ((uVar5 ^ 0xffffffff) & 0x1f)) | uVar2 >> (uVar5 & 0x1f);
    if ((uVar5 & 0x20) != 0) {
      uVar6 = uVar3 >> (uVar5 & 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      uVar6 = FUN_42019948(3);
      if ((uVar6 == uVar5) || (param_1 == '\0')) {
        FUN_420188e8();
      }
      else {
        FUN_42018854(uVar5);
      }
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 != 0x31);
  return;
}


