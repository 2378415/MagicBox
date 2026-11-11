undefined4 FUN_42003e7c(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 local_30 [12];
  
  if (DAT_42000540 < param_1 + DAT_4200053c) {
    uVar1 = 2;
  }
  else if ((param_1 & 0xff) == 0) {
    FUN_42003de8(param_1,local_30);
    memw();
    *param_2 = local_30[0];
    uVar1 = 0;
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}