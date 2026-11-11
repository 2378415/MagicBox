uint FUN_4200d1b4(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  
  local_40 = 0;
  uVar2 = param_4 + 3U & 0xfffffffc;
  if (param_3 == 0) {
    uVar2 = 0xfffffffd;
  }
  else {
    uVar3 = (uint)*(ushort *)(param_1 + 0x48);
    if (uVar3 == 0) {
      uVar2 = uVar2 + 0x20;
      *(short *)(param_1 + 0x50) = *(short *)(param_1 + 0x50) + 1;
    }
    else {
      if (uVar3 == 1) {
        uStack_3c = *(undefined4 *)(param_1 + 0x4c);
        uStack_28 = 6;
        local_40 = uVar3;
        uStack_38 = param_2;
        uStack_34 = param_2;
        uStack_30 = uVar2;
        uStack_2c = uVar2;
        iVar1 = FUN_4200ceb4(param_1 + 0x54,&local_40,0x20);
        if (iVar1 == 0) {
          *(uint *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + uVar2;
          return 0x20;
        }
      }
      else {
        iVar1 = FUN_4200ceb4(param_1 + 0x54,param_3,uVar2);
        if (iVar1 == 0) {
          *(uint *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + uVar2;
          return uVar2;
        }
      }
      uVar2 = 0xfffffffe;
    }
  }
  return uVar2;
}