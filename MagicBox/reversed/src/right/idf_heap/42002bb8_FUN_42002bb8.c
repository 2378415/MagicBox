void FUN_42002bb8(undefined1 *param_1)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = DAT_4200004c;
  memw();
  memw();
  *(uint *)(DAT_4200004c + 0x148) = *(uint *)(DAT_4200004c + 0x148) & 0xfffffffd;
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) & DAT_420003c8;
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) & DAT_420003cc | 0x20;
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) & DAT_4200016c | ((byte)param_1[3] & 1) << 0xe;
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) & DAT_42000164 | ((byte)param_1[4] & 1) << 0xf;
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) | DAT_420003d0;
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) & DAT_420003d4;
  bVar1 = param_1[2];
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) | DAT_420003d8;
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) & DAT_420003dc | (bVar1 & 1) << 0x1a;
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) | DAT_420003e0;
  FUN_42002ba0(*param_1);
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) & DAT_420003e4 | ((byte)param_1[1] & 1) << 0x1e;
  return;
}