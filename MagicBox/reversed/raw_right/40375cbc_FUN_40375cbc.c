// 40375cbc  FUN_40375cbc  FUN_40375cbc  size=328
// strings:  |<-CORRUPTED |  |<-CONTINUES

undefined4 FUN_40375cbc(int param_1,undefined4 param_2,undefined1 param_3)

{
  bool bVar1;
  undefined4 uVar2;
  int extraout_a3;
  int extraout_a3_00;
  uint uVar3;
  int iVar4;
  uint local_30;
  uint uStack_2c;
  int iStack_28;
  int iStack_24;
  
  if (param_1 < 1) {
    return 0x102;
  }
  (*DAT_403744d4)(&local_30,param_2,0x10);
  FUN_40375c04(PTR_s_Backtrace__40374600,param_3);
  uVar3 = local_30;
  if ((int)local_30 < 0) {
    uVar3 = local_30 & 0x3fffffff | DAT_403745e0;
  }
  FUN_40375bc8(uVar3 - 3,uStack_2c,param_3);
  if (((DAT_403745d4 < uStack_2c + DAT_403745d0) || ((uStack_2c & 0xf) != 0)) &&
     (DAT_403745dc < uStack_2c + DAT_403745d8)) {
    bVar1 = true;
    iVar4 = extraout_a3;
  }
  else {
    uVar3 = local_30;
    if ((int)local_30 < 0) {
      uVar3 = local_30 & 0x3fffffff | DAT_403745e0;
    }
    iVar4 = uVar3 + DAT_403745ec;
    if ((-(DAT_403745e8 + -1) & 0xffU) == 0 && (-(DAT_403745f0 + -1) & 0xffU) == 0) {
      if (DAT_403745f8 < uVar3 + DAT_403745f4) {
        if (DAT_403745dc < uVar3 + DAT_403745fc) {
          if (iStack_24 == 0) {
            cust0();
          }
          else if (*(int *)(iStack_24 + 0x50) == 0x14) {
            bVar1 = false;
            goto LAB_40375dc5;
          }
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
  }
LAB_40375dc5:
  while (((param_1 != 0 && (iStack_28 != 0)) && (!bVar1))) {
    iVar4 = FUN_40375c1c(&local_30,iVar4);
    if (iVar4 == 0) {
      bVar1 = true;
    }
    uVar3 = local_30;
    if ((int)local_30 < 0) {
      uVar3 = local_30 & 0x3fffffff | DAT_403745e0;
    }
    FUN_40375bc8(uVar3 - 3,uStack_2c,param_3);
    param_1 = param_1 + -1;
    iVar4 = extraout_a3_00;
  }
  if (bVar1) {
    FUN_40375c04(PTR_s__<_CORRUPTED_40374604,param_3);
    uVar2 = 0xffffffff;
  }
  else if (iStack_28 == 0) {
    uVar2 = 0;
  }
  else {
    FUN_40375c04(PTR_s__<_CONTINUES_40374608,param_3);
    uVar2 = 0;
  }
  FUN_40375c04(PTR_DAT_4037460c,param_3);
  return uVar2;
}


