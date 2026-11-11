void FUN_42002cc0(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int local_40;
  int iStack_3c;
  uint uStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  
  (*DAT_42000240)(param_1,0,0x1c);
  for (iVar2 = *DAT_420003e8; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x20)) {
    iVar1 = FUN_4202454c(iVar2,param_2);
    if (iVar1 != 0) {
      FUN_4202658c(*(undefined4 *)(iVar2 + 0x1c),&local_40);
      *param_1 = *param_1 + local_40;
      param_1[1] = param_1[1] + iStack_3c;
      uVar3 = param_1[2];
      param_1[2] = (uStack_38 < uVar3) * uVar3 + (uStack_38 >= uVar3) * uStack_38;
      param_1[3] = param_1[3] + iStack_34;
      param_1[4] = param_1[4] + iStack_30;
      param_1[5] = param_1[5] + iStack_2c;
      param_1[6] = param_1[6] + iStack_28;
    }
  }
  return;
}