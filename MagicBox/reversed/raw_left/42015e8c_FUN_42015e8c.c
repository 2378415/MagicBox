// 42015e8c  FUN_42015e8c  FUN_42015e8c  size=59

undefined4 FUN_42015e8c(uint param_1,uint param_2,byte *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)((param_1 & 0xff) * 8 + DAT_420013e0 + 4);
  iVar3 = (param_2 & 0x7f) * 0x20;
  if ((param_2 & 0x80) == 0) {
    memw();
    bVar1 = (byte)(*(uint *)(iVar2 + 0xb00 + iVar3) >> 0x15);
  }
  else {
    memw();
    bVar1 = (byte)(*(uint *)(iVar2 + 0x900 + iVar3) >> 0x15);
  }
  *param_3 = bVar1 & 1;
  return 0;
}


