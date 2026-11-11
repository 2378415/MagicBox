undefined4 FUN_42007428(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 * 4 + DAT_42000844);
  iVar3 = *(int *)(iVar2 + 0x2c) + 1;
  if (*(int *)(iVar2 + 0x34) <= iVar3) {
    iVar3 = 0;
  }
  if (*(int *)(iVar2 + 0x30) == iVar3) {
    uVar1 = 0xffffffff;
  }
  else {
    *(undefined4 *)(*(int *)(iVar2 + 0x2c) * 4 + *(int *)(iVar2 + 0x38)) = param_2;
    *(int *)(iVar2 + 0x2c) = iVar3;
    uVar1 = 0;
  }
  return uVar1;
}