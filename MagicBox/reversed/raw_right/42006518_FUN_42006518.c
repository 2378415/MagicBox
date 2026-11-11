// 42006518  FUN_42006518  FUN_42006518  size=34

int FUN_42006518(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(PTR_PTR_42000770 + param_1 * 4);
  iVar1 = *(int *)(iVar2 + 4);
  if (iVar1 == -1) {
    iVar1 = (**(code **)(iVar2 + 0x20))(param_1);
  }
  else {
    *(undefined4 *)(iVar2 + 4) = 0xffffffff;
  }
  return iVar1;
}


