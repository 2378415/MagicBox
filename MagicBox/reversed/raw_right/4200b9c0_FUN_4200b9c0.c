// 4200b9c0  FUN_4200b9c0  FUN_4200b9c0  size=30

int FUN_4200b9c0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = 0x70;
  iVar1 = *DAT_42000a68;
  *DAT_42000a68 = iVar1 + 1;
  return iVar1 * 0x70 + DAT_420003d0;
}


