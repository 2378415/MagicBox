// 4201408c  FUN_4201408c  FUN_4201408c  size=78

undefined4
FUN_4201408c(int param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,int *param_5,
            undefined4 param_6,undefined1 param_7,undefined1 param_8)

{
  int iVar1;
  int iVar2;
  undefined4 auStack_40 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int *piStack_28;
  
  iVar2 = *(int *)(param_1 + 0x10);
  uStack_30 = param_4;
  uStack_2c = param_6;
  piStack_28 = param_5;
  while( true ) {
    if (iVar2 == 0) {
      return DAT_42000cd4;
    }
    auStack_40[0] = 0;
    iVar1 = FUN_42015dbc(iVar2,param_2,param_3,uStack_30,auStack_40,uStack_2c,param_7,param_8);
    if (iVar1 == 0) break;
    iVar2 = *(int *)(iVar2 + 4);
  }
  *piStack_28 = iVar2;
  return 0;
}


