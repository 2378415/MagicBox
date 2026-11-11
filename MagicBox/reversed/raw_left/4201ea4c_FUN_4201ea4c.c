// 4201ea4c  FUN_4201ea4c  FUN_4201ea4c  size=122

undefined8 FUN_4201ea4c(undefined4 param_1,uint param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if (DAT_42001b38 < (param_2 & 0x7fffffff)) {
    if (DAT_42001b3c < (param_2 & 0x7fffffff)) {
      uVar2 = (*DAT_42000e2c)(param_1,param_2,param_1,param_2);
      return uVar2;
    }
    uVar1 = FUN_4201eecc(param_1,param_2,&local_30);
    uVar1 = uVar1 & 3;
    if (uVar1 == 1) {
      uVar2 = FUN_4201ed60(local_30,uStack_2c,uStack_28,uStack_24,1);
    }
    else {
      if (uVar1 != 2) {
        param_1 = local_30;
        param_2 = uStack_2c;
        if (uVar1 != 0) {
          uVar2 = FUN_4201ed60(local_30,uStack_2c,uStack_28,uStack_24,1);
          return uVar2;
        }
        goto LAB_4201ea93;
      }
      uVar2 = FUN_4201ebe8();
    }
    uVar2 = CONCAT44((uint)((ulonglong)uVar2 >> 0x20) ^ DAT_420014c0,(int)uVar2);
  }
  else {
    uStack_28 = 0;
    uStack_24 = 0;
LAB_4201ea93:
    uVar2 = FUN_4201ebe8(param_1,param_2,uStack_28,uStack_24);
  }
  return uVar2;
}


