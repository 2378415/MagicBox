undefined4 FUN_4038039c(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 4);
  memw();
  *(undefined4 *)(iVar2 + 0x18) = 0;
  memw();
  *(undefined4 *)(iVar2 + 8) = 0;
  iVar3 = *(int *)(param_1 + 8);
  memw();
  memw();
  *(uint *)(iVar2 + 0x34) = *(uint *)(iVar2 + 0x34) & 0xfffffffe | (uint)(iVar3 != 0);
  memw();
  memw();
  *(uint *)(iVar2 + 0x34) = *(uint *)(iVar2 + 0x34) & 0xfffffffd | (uint)(iVar3 != 1) * 2;
  memw();
  memw();
  *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(param_1 + 0x10);
  bVar1 = *(byte *)(param_1 + 0xe);
  memw();
  memw();
  *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) & 0xfffffc1f | (bVar1 - 1 & 0x1f) << 5;
  memw();
  memw();
  *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) & 0xffffffbf | (uint)(bVar1 != 0) << 6;
  bVar1 = *(byte *)(param_1 + 0xd);
  memw();
  memw();
  *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) & 0xffffff7f | (uint)(bVar1 != 0) << 7;
  memw();
  memw();
  *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) & 0xffffffe0 | bVar1 - 1 & 0x1f;
  if ((*(uint *)(param_1 + 0x18) & 1) == 0) {
    FUN_403802fc(param_1);
  }
  else {
    FUN_40380110(param_1);
  }
  if ((*(uint *)(param_1 + 0x18) & 2) == 0) {
    FUN_40380384(param_1);
  }
  else {
    FUN_403802e4(param_1);
  }
  memw();
  memw();
  *(uint *)(iVar2 + 0xa8) = *(uint *)(iVar2 + 0xa8) & 0xffffffe3;
  return 0;
}