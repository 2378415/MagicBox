int FUN_4201c90c(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *local_30 [12];
  
  uVar1 = (*DAT_4200030c)(param_2);
  if (0x10 < uVar1) {
    return 0x102;
  }
  uVar1 = FUN_42019070();
  local_30[0] = (int *)FUN_4201c81c(param_1,param_2);
  if (local_30[0] == (int *)0x0) {
    if (uVar1 == 0) {
      return -1;
    }
    iVar2 = FUN_4201e228(param_2,local_30);
    if (iVar2 == 0) {
      uVar3 = (**(code **)(*local_30[0] + 0x24))();
      iVar2 = FUN_4201c840(param_1,local_30[0],0,uVar3 / uVar1);
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_1 + 0x20);
        if (iVar2 != 0) {
          *(int **)(iVar2 + 8) = local_30[0];
        }
        local_30[0][1] = iVar2;
        local_30[0][2] = 0;
        *(int **)(param_1 + 0x20) = local_30[0];
        if (*(int *)(param_1 + 0x1c) == 0) {
          *(int **)(param_1 + 0x1c) = local_30[0];
        }
        *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
        goto LAB_4201c978;
      }
    }
    if (local_30[0] != (int *)0x0) {
      (**(code **)(*local_30[0] + 4))();
    }
  }
  else {
LAB_4201c978:
    iVar2 = 0;
  }
  return iVar2;
}