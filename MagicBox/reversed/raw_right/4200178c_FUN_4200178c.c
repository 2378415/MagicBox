// 4200178c  FUN_4200178c  FUN_4200178c  size=73

void FUN_4200178c(void)

{
  int iVar1;
  undefined4 local_30;
  undefined1 uStack_2c;
  
  local_30 = *(undefined4 *)PTR_DAT_42000080;
  uStack_2c = PTR_DAT_42000080[4];
  FUN_42002bb8(&local_30);
  iVar1 = DAT_4200004c;
  memw();
  memw();
  *(uint *)(DAT_4200004c + 0x4c) = *(uint *)(DAT_4200004c + 0x4c) | 0x200;
  FUN_42003b20(PTR_FUN_42000084,0,0x200,1);
  memw();
  memw();
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) | 0x200;
  return;
}


