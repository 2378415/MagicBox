int FUN_4200b468(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_40 [16];
  undefined4 uStack_30;
  
  uStack_30 = param_3;
  iVar1 = (*DAT_420001e4)(param_2);
  if (0x20 < iVar1 + 1U) {
    return 0;
  }
  uVar3 = param_5 + 3U & 0xfffffffc;
  iVar1 = (iVar1 + 4U & 0xfffffffc) + uVar3 + 0xc;
  if (*(short *)(param_1 + 0x48) == 2) {
    if (param_4 == 0) {
      return -3;
    }
    iVar2 = FUN_4200b40c(param_1,param_2,param_5,uStack_30);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = FUN_4200aed4(param_1 + 0x54,param_4,param_5);
    if (iVar2 == 0) {
      param_5 = uVar3 - param_5;
      iVar2 = 0;
      if (0 < param_5) {
        (*DAT_42000240)(auStack_40,0,3);
        iVar2 = FUN_4200aed4(param_1 + 0x54,auStack_40,param_5);
      }
      if (iVar2 == 0) goto LAB_4200b4e0;
    }
    iVar1 = -2;
  }
LAB_4200b4e0:
  return iVar1;
}