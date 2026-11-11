// 4037ef84  FUN_4037ef84  FUN_4037ef84  size=62

undefined4 FUN_4037ef84(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_403750d8;
  if ((((uint)(param_1 + DAT_40374e08) <= DAT_40374614) ||
      (uVar2 = 0, iVar1 = DAT_403750e0, (uint)(param_1 + DAT_403750dc) <= DAT_40374614)) &&
     (uVar2 = 0, (uint)(param_1 + param_2 + iVar1) <= DAT_40374614)) {
    (*DAT_403750e4)(param_1,param_2);
    uVar2 = 1;
  }
  return uVar2;
}


