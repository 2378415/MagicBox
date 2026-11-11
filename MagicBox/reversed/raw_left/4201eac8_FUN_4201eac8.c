// 4201eac8  FUN_4201eac8  FUN_4201eac8  size=124

undefined8 FUN_4201eac8(undefined4 param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if (DAT_42001b38 < (param_2 & 0x7fffffff)) {
    if (DAT_42001b3c < (param_2 & 0x7fffffff)) {
      uVar3 = (*DAT_42000e2c)(param_1,param_2,param_1,param_2);
      return uVar3;
    }
    uVar1 = FUN_4201eecc(param_1,param_2,&local_30);
    uVar1 = uVar1 & 3;
    if (uVar1 == 1) {
      uVar3 = FUN_4201ebe8(local_30,uStack_2c,uStack_28,uStack_24);
      return uVar3;
    }
    if (uVar1 == 2) {
      uVar3 = FUN_4201ed60();
    }
    else {
      if (uVar1 == 0) {
        uVar2 = 1;
        param_1 = local_30;
        param_2 = uStack_2c;
        goto LAB_4201eb16;
      }
      uVar3 = FUN_4201ebe8(local_30,uStack_2c,uStack_28,uStack_24);
    }
    uVar3 = CONCAT44((uint)((ulonglong)uVar3 >> 0x20) ^ DAT_420014c0,(int)uVar3);
  }
  else {
    uVar2 = 0;
    uStack_28 = 0;
    uStack_24 = 0;
LAB_4201eb16:
    uVar3 = FUN_4201ed60(param_1,param_2,uStack_28,uStack_24,uVar2);
  }
  return uVar3;
}


