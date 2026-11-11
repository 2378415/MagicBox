// 4201ed60  FUN_4201ed60  FUN_4201ed60  size=361
// strings: IUUUUU

undefined8
FUN_4201ed60(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  uVar7 = CONCAT44(param_2,param_1);
  if ((DAT_42001b44 < (param_2 & 0x7fffffff)) ||
     (iVar1 = (*DAT_42001b40)(param_1,param_2), iVar1 != 0)) {
    uVar7 = (*DAT_42000e30)(param_1,param_2,param_1,param_2);
    uVar4 = (undefined4)((ulonglong)uVar7 >> 0x20);
    uVar2 = (undefined4)uVar7;
    uVar7 = (*DAT_42000e30)(param_1,param_2,uVar2,uVar4);
    uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
    uVar3 = (undefined4)uVar7;
    uVar7 = (*DAT_42000e30)(uVar2,uVar4,DAT_42001b8c,DAT_42001b90);
    uVar7 = (*DAT_42000e2c)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_42001b94,DAT_42001b98);
    uVar7 = (*DAT_42000e30)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar4);
    uVar7 = (*DAT_42000e38)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_42001b9c,DAT_42001ba0);
    uVar7 = (*DAT_42000e30)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar4);
    uVar7 = (*DAT_42000e2c)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_42001ba4,DAT_42001ba8);
    uVar7 = (*DAT_42000e30)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar4);
    uVar7 = (*DAT_42000e38)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_42001bac,DAT_42001bb0);
    uVar6 = (undefined4)((ulonglong)uVar7 >> 0x20);
    if (param_5 == 0) {
      uVar7 = (*DAT_42000e30)(uVar2,uVar4,(int)uVar7,uVar6);
      uVar7 = (*DAT_42000e2c)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_42001b84,DAT_42001b88);
      uVar7 = (*DAT_42000e30)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar3,uVar5);
      uVar7 = (*DAT_42000e38)(param_1,param_2,(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
    }
    else {
      uVar8 = (*DAT_42000e30)(param_3,param_4,0,0x3fe00000);
      uVar7 = (*DAT_42000e30)(uVar3,uVar5,(int)uVar7,uVar6);
      uVar7 = (*DAT_42000e2c)((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar7,
                              (int)((ulonglong)uVar7 >> 0x20));
      uVar7 = (*DAT_42000e30)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar4);
      uVar7 = (*DAT_42000e2c)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),param_3,param_4);
      uVar8 = (*DAT_42000e30)(uVar3,uVar5,DAT_42001b84,DAT_42001b88);
      uVar7 = (*DAT_42000e38)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar8,
                              (int)((ulonglong)uVar8 >> 0x20));
      uVar7 = (*DAT_42000e2c)(param_1,param_2,(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
    }
  }
  return uVar7;
}


