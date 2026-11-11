// 4037f39c  FUN_4037f39c  FUN_4037f39c  size=314

void FUN_4037f39c(int param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_1 + 4);
  memw();
  *(undefined4 *)(iVar4 + 0x10) = 0;
  memw();
  *(undefined4 *)(iVar4 + 8) = 0;
  memw();
  memw();
  *(uint *)(iVar4 + 0xe8) = *(uint *)(iVar4 + 0xe8) | 1;
  memw();
  memw();
  *(uint *)(iVar4 + 0xe8) = *(uint *)(iVar4 + 0xe8) | 2;
  memw();
  memw();
  *(uint *)(iVar4 + 0xe8) = *(uint *)(iVar4 + 0xe8) | 4;
  memw();
  *(undefined4 *)(iVar4 + 0x30) = 0;
  uVar3 = DAT_40375184;
  uVar2 = DAT_40374a20;
  memw();
  memw();
  *(uint *)(iVar4 + 0x30) = *(uint *)(iVar4 + 0x30) | DAT_40375184;
  memw();
  memw();
  *(uint *)(iVar4 + 0x30) = *(uint *)(iVar4 + 0x30) | uVar2;
  uVar2 = DAT_4037518c;
  memw();
  memw();
  *(uint *)(iVar4 + 0x30) = *(uint *)(iVar4 + 0x30) & DAT_40375188;
  memw();
  iVar5 = *(int *)(param_1 + 8);
  memw();
  *(uint *)(iVar4 + 0x20) = *(uint *)(iVar4 + 0x20) & 0xfffffffe | (uint)(iVar5 != 0);
  memw();
  memw();
  *(uint *)(iVar4 + 0x20) = *(uint *)(iVar4 + 0x20) & 0xfffffffd | (uint)(iVar5 != 1) * 2;
  memw();
  memw();
  *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(param_1 + 0x10);
  bVar1 = *(byte *)(param_1 + 0xe);
  memw();
  memw();
  *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) & uVar2 | (bVar1 - 1 & 0x1f) << 0x16;
  memw();
  memw();
  *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) & 0xffffffbf | (uint)(bVar1 != 0) << 6;
  bVar1 = *(byte *)(param_1 + 0xd);
  memw();
  memw();
  *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) & 0xffffff7f | (uint)(bVar1 != 0) << 7;
  memw();
  memw();
  *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) & DAT_40375190 | (bVar1 - 1 & 0x1f) << 0x11;
  memw();
  memw();
  *(uint *)(iVar4 + 8) = *(uint *)(iVar4 + 8) | uVar3;
  return;
}


