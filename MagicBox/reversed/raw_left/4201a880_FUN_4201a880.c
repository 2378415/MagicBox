// 4201a880  FUN_4201a880  FUN_4201a880  size=30

undefined4 FUN_4201a880(void)

{
  undefined4 uVar1;
  
  memw();
  uVar1 = DAT_4200194c;
  if ((*DAT_42001980 >> 10 & 3) != 1) {
    uVar1 = FUN_4201a7d8();
  }
  return uVar1;
}


