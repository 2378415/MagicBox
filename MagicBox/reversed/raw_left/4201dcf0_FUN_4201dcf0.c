// 4201dcf0  FUN_4201dcf0  FUN_4201dcf0  size=47

int FUN_4201dcf0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_30 [12];
  
  iVar1 = DAT_42001a94;
  if (*(int *)(param_1 + 0xc) == -2) {
    local_30[0] = 0xfffffffc;
    iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x14))
                      (*(int **)(param_1 + 0x50),*(undefined4 *)(param_1 + 8),local_30,4);
    uVar2 = 0xfffffffc;
    if (iVar1 != 0) {
      uVar2 = 0;
    }
    *(undefined4 *)(param_1 + 0xc) = uVar2;
  }
  return iVar1;
}


