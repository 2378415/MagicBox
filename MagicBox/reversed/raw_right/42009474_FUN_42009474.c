// 42009474  FUN_42009474  FUN_42009474  size=32

int FUN_42009474(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = *(int *)PTR_DAT_42000920;
  if (iVar1 == -1) {
    iVar1 = (**(code **)(PTR_DAT_42000920 + 0x1c))(param_1);
  }
  else {
    *(undefined4 *)PTR_DAT_42000920 = 0xffffffff;
  }
  return iVar1;
}


