// 42002c98  FUN_42002c98  FUN_42002c98  size=73

void FUN_42002c98(void)

{
  int iVar1;
  undefined *puVar2;
  undefined4 local_30;
  undefined1 uStack_2c;
  
  local_30 = *(undefined4 *)PTR_DAT_42000194;
  uStack_2c = PTR_DAT_42000194[4];
  FUN_420044a0(&local_30);
  puVar2 = PTR_LAB_42000198;
  iVar1 = DAT_42000170;
  memw();
  memw();
  *(uint *)(DAT_42000170 + 0x4c) = *(uint *)(DAT_42000170 + 0x4c) | 0x200;
  FUN_42005864(puVar2,0,0x200,1);
  memw();
  memw();
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) | 0x200;
  return;
}


