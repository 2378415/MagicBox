uint FUN_4200b27c(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_40 [2];
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  
  (*DAT_42000240)(local_40,0,0x20);
  uVar3 = param_5 + 3U & 0xfffffffc;
  if (param_4 == 0) {
    uVar1 = 0xfffffffd;
  }
  else if (*(short *)(param_1 + 0x48) == 0) {
    *(short *)(param_1 + 0x50) = *(short *)(param_1 + 0x50) + 1;
    uVar1 = uVar3 + 0x20;
  }
  else if (*(short *)(param_1 + 0x48) == 1) {
    uStack_28 = 6;
    local_40[0] = param_2;
    uStack_38 = param_3;
    uStack_34 = param_3;
    uStack_30 = uVar3;
    uStack_2c = uVar3;
    uVar1 = FUN_4200b1f8(param_1,local_40);
    if (0 < (int)uVar1) {
      *(uint *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + uVar3;
    }
  }
  else {
    iVar2 = FUN_4200aed4(param_1 + 0x54,param_4,uVar3);
    if (iVar2 == 0) {
      *(uint *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + uVar3;
      uVar1 = uVar3;
    }
    else {
      uVar1 = 0xfffffffe;
    }
  }
  return uVar1;
}