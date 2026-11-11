// 4200d0dc  FUN_4200d0dc  FUN_4200d0dc  size=78

undefined4 FUN_4200d0dc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  local_30 = (*DAT_42000ce4)(DAT_42000ce0,param_2,0x20);
  local_30 = local_30 + 1;
  uStack_2c = param_3;
  uStack_28 = param_4;
  iVar1 = FUN_4200ceb4(param_1 + 0x54,&local_30,0xc);
  if ((iVar1 != 0) ||
     (iVar1 = FUN_4200ceb4(param_1 + 0x54,DAT_42000ce0,local_30 + 3U & 0xfffffffc), uVar2 = 0,
     iVar1 != 0)) {
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}


