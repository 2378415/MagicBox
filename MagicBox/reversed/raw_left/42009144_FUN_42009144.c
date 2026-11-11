// 42009144  FUN_42009144  FUN_42009144  size=74
// strings: uart

void FUN_42009144(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 * 4 + DAT_42000a40);
  uVar2 = *(int *)(iVar3 + 0x2c) + 1U & -*(int *)(iVar3 + 0x34);
  if (*(uint *)(iVar3 + 0x30) == uVar2) {
    if (1 < *(uint *)PTR_DAT_42000028) {
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      (*DAT_42000060)(PTR_DAT_42000a60,uVar1,PTR_DAT_42000a54);
    }
  }
  else {
    *(undefined4 *)(*(int *)(iVar3 + 0x2c) * 4 + *(int *)(iVar3 + 0x38)) = param_2;
    *(uint *)(iVar3 + 0x2c) = uVar2;
  }
  return;
}


