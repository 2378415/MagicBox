// 40378128  FUN_40378128  FUN_40378128  size=81
// strings: JwW7

int FUN_40378128(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int local_30 [12];
  
  iVar2 = DAT_403748ec;
  piVar1 = DAT_40374860;
  uVar6 = (param_1 >> 0x10) * 0x10000;
  uVar5 = (param_2 + DAT_403748e8 + param_1 + (param_1 >> 0x10) * -0x10000 & 0xffff0000) + uVar6;
  if (uVar6 < uVar5) {
    iVar3 = 0;
    do {
      if (*(uint *)(*piVar1 + 4) <= uVar6) goto LAB_40378159;
      iVar4 = FUN_403780e0(uVar6,local_30);
      if ((iVar4 != 0) && (local_30[0] != 0)) {
        FUN_4037ef84(local_30[0],iVar2);
        iVar3 = iVar4;
      }
      uVar6 = uVar6 + iVar2;
    } while (uVar6 < uVar5);
  }
  else {
LAB_40378159:
    iVar3 = 0;
  }
  return iVar3;
}


