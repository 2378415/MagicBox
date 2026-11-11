int FUN_42015874(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_30 [12];
  
  if (param_2 < 0x7e) {
    iVar1 = FUN_42025004(param_1 + 0x18,param_2,param_3);
    if (iVar1 == 0) {
      local_30[0] = *(undefined4 *)((param_2 >> 4) * 4 + param_1 + 0x18);
      iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x14))
                        (*(int **)(param_1 + 0x50),(param_2 >> 4) * 4 + *(int *)(param_1 + 8) + 0x20
                         ,local_30,4);
      if (iVar1 != 0) {
        *(undefined4 *)(param_1 + 0xc) = 0;
      }
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}