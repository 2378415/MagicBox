// strings: LUUUUU

longlong __kernel_cos(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  longlong lVar9;
  
  uVar5 = param_2 & 0x7fffffff;
  if (uVar5 <= DAT_42001b44) {
    iVar1 = (*DAT_42001b40)(param_1,param_2);
    if (iVar1 == 0) {
      return (ulonglong)DAT_42000e14 << 0x20;
    }
  }
  uVar6 = (*DAT_42000e30)(param_1,param_2,param_1,param_2);
  uVar3 = (undefined4)((ulonglong)uVar6 >> 0x20);
  uVar2 = (undefined4)uVar6;
  uVar6 = (*DAT_42000e30)(uVar2,uVar3,0,0x3fe00000);
  uVar4 = (undefined4)((ulonglong)uVar6 >> 0x20);
  uVar7 = (*DAT_42000e30)(uVar2,uVar3,DAT_42001b54,DAT_42001b58);
  uVar7 = (*DAT_42000e38)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_42001b5c,DAT_42001b60);
  uVar7 = (*DAT_42000e30)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar3);
  uVar7 = (*DAT_42000e2c)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_42001b64,DAT_42001b68);
  uVar7 = (*DAT_42000e30)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar3);
  uVar7 = (*DAT_42000e38)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_42001b6c,DAT_42001b70);
  uVar7 = (*DAT_42000e30)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar3);
  uVar7 = (*DAT_42000e2c)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_42001b74,DAT_42001b78);
  uVar7 = (*DAT_42000e30)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar3);
  uVar7 = (*DAT_42000e38)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_42001b7c,DAT_42001b80);
  uVar7 = (*DAT_42000e30)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar3);
  uVar7 = (*DAT_42000e30)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),uVar2,uVar3);
  uVar8 = (*DAT_42000e30)(param_1,param_2,param_3,param_4);
  uVar7 = (*DAT_42000e2c)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar8,
                          (int)((ulonglong)uVar8 >> 0x20));
  uVar2 = (undefined4)((ulonglong)uVar7 >> 0x20);
  if (DAT_42001b48 < uVar5) {
    iVar1 = DAT_42001b50;
    if (uVar5 <= DAT_42001b4c) {
      iVar1 = uVar5 - 0x200000;
    }
    lVar9 = (*DAT_42000e2c)(0,DAT_42000e14,0,iVar1);
    uVar6 = (*DAT_42000e2c)((int)uVar6,uVar4,0,iVar1);
    uVar6 = (*DAT_42000e2c)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar7,uVar2);
  }
  else {
    uVar6 = (*DAT_42000e2c)((int)uVar6,uVar4,(int)uVar7,uVar2);
    lVar9 = (ulonglong)DAT_42000e14 << 0x20;
  }
  lVar9 = (*DAT_42000e2c)((int)lVar9,(int)((ulonglong)lVar9 >> 0x20),(int)uVar6,
                          (int)((ulonglong)uVar6 >> 0x20));
  return lVar9;
}