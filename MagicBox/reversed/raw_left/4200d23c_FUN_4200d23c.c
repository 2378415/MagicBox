// 4200d23c  FUN_4200d23c  FUN_4200d23c  size=102

int FUN_4200d23c(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_40;
  undefined4 uStack_3c;
  int iStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  
  if (*(short *)(param_1 + 0x48) == 1) {
    uStack_3c = *(undefined4 *)(param_1 + 0x4c);
    local_40 = 4;
    uStack_28 = 6;
    iStack_30 = param_2;
    iStack_2c = param_2;
    iVar1 = FUN_4200ceb4(param_1 + 0x54,&local_40,0x20);
    if (iVar1 == 0) {
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + param_2;
      param_2 = 0x20;
    }
    else {
      param_2 = -2;
    }
  }
  else if (*(short *)(param_1 + 0x48) == 0) {
    param_2 = param_2 + 0x20;
    *(short *)(param_1 + 0x50) = *(short *)(param_1 + 0x50) + 1;
  }
  else {
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + param_2;
  }
  return param_2;
}


