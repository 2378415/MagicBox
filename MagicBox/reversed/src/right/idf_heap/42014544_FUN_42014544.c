int FUN_42014544(int param_1,undefined1 param_2,char param_3,undefined4 param_4,uint *param_5)

{
  int iVar1;
  undefined1 auStack_50 [24];
  uint uStack_38;
  undefined4 auStack_30 [12];
  
  if (*(int *)(param_1 + 100) == 1) {
    auStack_30[0] = 0;
    iVar1 = FUN_4201408c(param_1,param_2,param_3,param_4,auStack_30,auStack_50,0xff,0xff);
    if (iVar1 == 0) {
      *param_5 = uStack_38 & 0xffff;
    }
    else if (param_3 == 'A') {
      iVar1 = FUN_4201408c(param_1,param_2,0x48,param_4,auStack_30,auStack_50,0xff,0xff);
      if (iVar1 == 0) {
        *param_5 = uStack_38;
      }
    }
  }
  else {
    iVar1 = DAT_420010a0;
  }
  return iVar1;
}