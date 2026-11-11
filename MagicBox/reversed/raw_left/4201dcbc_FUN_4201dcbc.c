// 4201dcbc  FUN_4201dcbc  FUN_4201dcbc  size=51

int FUN_4201dcbc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_30 [12];
  
  iVar1 = DAT_42001a94;
  if ((*(uint *)(param_1 + 0xc) & 0xfffffffd) == 0xfffffffc) {
    local_30[0] = 0xfffffff8;
    iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x14))
                      (*(int **)(param_1 + 0x50),*(undefined4 *)(param_1 + 8),local_30,4);
    uVar2 = 0xfffffff8;
    if (iVar1 != 0) {
      uVar2 = 0;
    }
    *(undefined4 *)(param_1 + 0xc) = uVar2;
  }
  return iVar1;
}


