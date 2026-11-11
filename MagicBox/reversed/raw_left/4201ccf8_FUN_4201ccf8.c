// 4201ccf8  FUN_4201ccf8  FUN_4201ccf8  size=107

int FUN_4201ccf8(int param_1)

{
  int iVar1;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined1 uStack_38;
  undefined1 local_37;
  undefined4 uStack_24;
  
  if (*(int *)(param_1 + 0xc) == -1) {
    *(undefined4 *)(param_1 + 0xc) = 0xfffffffe;
    local_37 = 0xff;
    uStack_3c = *(undefined4 *)(param_1 + 0x10);
    uStack_38 = *(undefined1 *)(param_1 + 0x14);
    local_40 = 0xfffffffe;
    uStack_24 = (*DAT_42000cd4)(0xffffffff,&uStack_3c,0x18);
    iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x14))
                      (*(int **)(param_1 + 0x50),*(undefined4 *)(param_1 + 8),&local_40,0x20);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x38) = 0;
      *(undefined1 *)(param_1 + 0x18) = 0xff;
    }
    else {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


