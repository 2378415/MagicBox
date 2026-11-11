int FUN_4201531c(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *local_30 [12];
  
  uVar1 = (*DAT_420001e4)(param_2);
  if (uVar1 < 0x11) {
    uVar1 = FUN_420121cc();
    iVar2 = FUN_42015278(param_1,param_2);
    if (iVar2 == 0) {
      if (uVar1 == 0) {
        iVar2 = -1;
      }
      else {
        local_30[0] = (int *)0x0;
        iVar2 = FUN_42016b24(param_2,local_30);
        if (iVar2 == 0) {
          uVar3 = (**(code **)(*local_30[0] + 0x24))();
          iVar2 = FUN_42015288(param_1,local_30[0],0,uVar3 / uVar1);
          if (iVar2 == 0) {
            FUN_42024d84(param_1 + 0x1c,local_30[0]);
            return 0;
          }
        }
        if (local_30[0] != (int *)0x0) {
          (**(code **)(*local_30[0] + 4))();
        }
      }
    }
    else {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = 0x102;
  }
  return iVar2;
}