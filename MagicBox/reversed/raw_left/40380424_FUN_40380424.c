// 40380424  FUN_40380424  FUN_40380424  size=387

undefined4 FUN_40380424(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 4);
  memw();
  *(undefined4 *)(iVar3 + 0x18) = 0;
  memw();
  *(undefined4 *)(iVar3 + 8) = 0;
  memw();
  iVar4 = *(int *)(param_1 + 8);
  memw();
  *(uint *)(iVar3 + 0x34) = *(uint *)(iVar3 + 0x34) & 0xfffffffe | (uint)(iVar4 != 0);
  memw();
  memw();
  *(uint *)(iVar3 + 0x34) = *(uint *)(iVar3 + 0x34) & 0xfffffffd | (uint)(iVar4 != 1) * 2;
  memw();
  memw();
  *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(param_1 + 0x10);
  bVar1 = *(byte *)(param_1 + 0xe);
  memw();
  memw();
  *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) & 0xfffffc1f | (bVar1 - 1 & 0x1f) << 5;
  memw();
  memw();
  *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) & 0xffffffbf | (uint)(bVar1 != 0) << 6;
  bVar1 = *(byte *)(param_1 + 0xd);
  memw();
  memw();
  *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) & 0xffffff7f | (uint)(bVar1 != 0) << 7;
  memw();
  memw();
  *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) & 0xffffffe0 | bVar1 - 1 & 0x1f;
  iVar4 = DAT_40374850;
  uVar2 = *(uint *)(param_1 + 0x18);
  if ((uVar2 & 1) == 0) {
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(DAT_40374850 + 0x98) = *(uint *)(DAT_40374850 + 0x98) & 0xfffffc03 | 0x14;
    memw();
    memw();
    *(uint *)(iVar4 + 0x98) = *(uint *)(iVar4 + 0x98) & 0xfffffffe;
    memw();
    memw();
    *(uint *)(iVar4 + 0x9c) = *(uint *)(iVar4 + 0x9c) & 0xfffffffb;
    memw();
    memw();
    *(uint *)(iVar4 + 0x9c) = *(uint *)(iVar4 + 0x9c) & 0xfffffff7;
    memw();
    memw();
    *(uint *)(iVar4 + 0xa0) = *(uint *)(iVar4 + 0xa0) & 0xfffffffe;
    memw();
    memw();
    *(uint *)(iVar4 + 0x9c) = *(uint *)(iVar4 + 0x9c) & 0xffffffef;
  }
  else {
    FUN_40380290(param_1);
    iVar4 = DAT_40374850;
  }
  memw();
  if ((uVar2 & 2) == 0) {
    memw();
    *(uint *)(iVar4 + 0x34) = *(uint *)(iVar4 + 0x34) & DAT_40374acc;
  }
  else {
    memw();
    *(uint *)(iVar4 + 0x34) = *(uint *)(iVar4 + 0x34) | DAT_40374e3c;
  }
  memw();
  memw();
  *(uint *)(iVar3 + 0xa8) = *(uint *)(iVar3 + 0xa8) & 0xffffffe3;
  return 0;
}


