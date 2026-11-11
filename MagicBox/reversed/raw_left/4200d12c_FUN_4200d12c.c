// 4200d12c  FUN_4200d12c  FUN_4200d12c  size=132

int FUN_4200d12c(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  undefined2 local_40;
  undefined1 uStack_3e;
  int iStack_30;
  
  iVar1 = (*DAT_4200030c)(param_2);
  if (0x20 < iVar1 + 1U) {
    return 0;
  }
  uVar2 = param_5 + 3U & 0xfffffffc;
  iStack_30 = (iVar1 + 4U & 0xfffffffc) + uVar2 + 0xc;
  if (*(short *)(param_1 + 0x48) != 2) {
    return iStack_30;
  }
  if (param_4 == 0) {
    return -3;
  }
  iVar1 = FUN_4200d0dc(param_1,param_2,param_5,param_3);
  if (iVar1 == 0) {
    iVar1 = FUN_4200ceb4(param_1 + 0x54,param_4,param_5);
    if (iVar1 == 0) {
      if (0 < (int)(uVar2 - param_5)) {
        local_40 = 0;
        uStack_3e = 0;
        iVar1 = FUN_4200ceb4(param_1 + 0x54,&local_40);
        if (iVar1 != 0) {
          return -2;
        }
      }
      return iStack_30;
    }
  }
  return -2;
}


