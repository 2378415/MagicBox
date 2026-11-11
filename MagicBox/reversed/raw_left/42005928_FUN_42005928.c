// 42005928  FUN_42005928  FUN_42005928  size=216
// strings: sleep_gpio | $}7@4>

void FUN_42005928(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (2 < *(uint *)PTR_DAT_42000028) {
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*DAT_42000060)(PTR_DAT_420006ec,uVar3,PTR_s_sleep_gpio_420006e8);
  }
  uVar2 = DAT_420006f8;
  uVar1 = DAT_420006f4;
  iVar4 = DAT_420006f0;
  uVar5 = 0;
  do {
    uVar6 = iVar4 << 0x20 - (0x20 - ((uVar5 ^ 0xffffffff) & 0x1f)) | uVar1 >> (uVar5 & 0x1f);
    if ((uVar5 & 0x20) != 0) {
      uVar6 = uVar2 >> (uVar5 & 0x1f);
    }
    if ((uVar6 & 1) != 0) {
      FUN_420185f0(uVar5,0);
      FUN_42018790(uVar5,3);
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 != 0x31);
  uVar3 = FUN_42019948(0);
  FUN_42018790(uVar3,0);
  uVar3 = FUN_42019948(1);
  FUN_42018790(uVar3,0);
  uVar3 = FUN_42019948(2);
  FUN_42018790(uVar3,0);
  uVar3 = FUN_42019948(4);
  FUN_42018790(uVar3,0);
  uVar3 = FUN_42019948(5);
  FUN_42018790(uVar3,0);
  iVar4 = (*(code *)PTR_FUN_420006fc)();
  if (iVar4 != 0) {
    uVar3 = FUN_42019948(6);
    FUN_42018790(uVar3,0);
    uVar3 = FUN_42019948(7);
    FUN_42018790(uVar3,0);
    uVar3 = FUN_42019948(8);
    FUN_42018790(uVar3,0);
    uVar3 = FUN_42019948(9);
    FUN_42018790(uVar3,0);
    uVar3 = FUN_42019948(10);
    FUN_42018790(uVar3,0);
  }
  return;
}


