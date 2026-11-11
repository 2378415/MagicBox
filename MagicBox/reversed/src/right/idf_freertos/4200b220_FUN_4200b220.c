int FUN_4200b220(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_40 [4];
  int iStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  
  (*DAT_42000240)(local_40,0,0x20);
  if (*(short *)(param_1 + 0x48) == 1) {
    local_40[0] = 4;
    uStack_28 = 6;
    iStack_30 = param_2;
    iStack_2c = param_2;
    iVar1 = FUN_4200b1f8(param_1,local_40);
    if (0 < iVar1) {
      *(int *)(param_1 + 0x4c) = param_2 + *(int *)(param_1 + 0x4c);
      iVar1 = 0x20;
    }
  }
  else if (*(short *)(param_1 + 0x48) == 0) {
    *(short *)(param_1 + 0x50) = *(short *)(param_1 + 0x50) + 1;
    iVar1 = param_2 + 0x20;
  }
  else {
    *(int *)(param_1 + 0x4c) = param_2 + *(int *)(param_1 + 0x4c);
    iVar1 = param_2;
  }
  return iVar1;
}