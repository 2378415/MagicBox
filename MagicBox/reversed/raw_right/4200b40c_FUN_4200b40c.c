// 4200b40c  FUN_4200b40c  FUN_4200b40c  size=88

undefined4 FUN_4200b40c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  (*DAT_42000240)(&local_30,0,0xc);
  local_30 = (*DAT_42000a34)(DAT_42000a30,param_2,0x20);
  local_30 = local_30 + 1;
  uStack_2c = param_3;
  uStack_28 = param_4;
  iVar1 = FUN_4200aed4(param_1 + 0x54,&local_30,0xc);
  if (iVar1 == 0) {
    iVar1 = FUN_4200aed4(param_1 + 0x54,DAT_42000a30,local_30 + 3U & 0xfffffffc);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = 0xfffffffe;
    }
  }
  else {
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}


