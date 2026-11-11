// 42024fb0  FUN_42024fb0  FUN_42024fb0  size=39

int FUN_42024fb0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_30 [12];
  
  local_30[0] = param_2;
  iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x14))
                    (*(int **)(param_1 + 0x50),*(undefined4 *)(param_1 + 8),local_30,4);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0xc) = param_2;
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return iVar1;
}


