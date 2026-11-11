void FUN_4037c4a4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  memw();
  iVar1 = *(int *)(*(int *)(*DAT_40374dc0 + 0xc) + 0xc);
  FUN_4037c980(iVar1 + 4);
  if ((*(byte *)(iVar1 + 0x24) & 4) == 0) {
    *(byte *)(iVar1 + 0x24) = *(byte *)(iVar1 + 0x24) & 0xfe;
  }
  else {
    FUN_4037c47c(iVar1,param_1,param_2);
  }
  (**(code **)(iVar1 + 0x20))(iVar1);
  return;
}