// 4200d8d4  FUN_4200d8d4  FUN_4200d8d4  size=52

int FUN_4200d8d4(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_4200cd4c(*param_1);
  if ((iVar1 != 0) && (iVar2 = FUN_4200d784(param_1), iVar2 == 0)) {
    iVar2 = *DAT_42000d1c * 0x70 + DAT_42000540;
    *DAT_42000d1c = *DAT_42000d1c + 1;
    param_1[1] = iVar2;
    param_1[2] = iVar2 + 0x70;
  }
  return iVar1;
}


