// 4200453c  FUN_4200453c  FUN_4200453c  size=50

undefined4 FUN_4200453c(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 local_30 [12];
  
  if (DAT_42000540 < param_1 + DAT_4200058c) {
    uVar1 = 2;
  }
  else if ((param_1 & 0xff) == 0) {
    FUN_420044a0(param_1,local_30);
    memw();
    *param_2 = local_30[0];
    uVar1 = 0;
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}


