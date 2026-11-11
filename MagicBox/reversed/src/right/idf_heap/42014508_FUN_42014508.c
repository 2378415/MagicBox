int FUN_42014508(int param_1,undefined1 param_2,undefined4 param_3,undefined1 *param_4)

{
  int iVar1;
  undefined1 uStack_50;
  undefined1 uStack_4f;
  undefined4 auStack_30 [12];
  
  if (*(int *)(param_1 + 100) == 1) {
    auStack_30[0] = 0;
    iVar1 = FUN_4201408c(param_1,param_2,0xff,param_3,auStack_30,&uStack_50,0xff,0xff);
    if ((iVar1 == 0) && (param_4 != (undefined1 *)0x0)) {
      *param_4 = uStack_4f;
    }
  }
  else {
    iVar1 = DAT_420010a0;
  }
  return iVar1;
}