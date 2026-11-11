// strings: Pk7@@

void FUN_420044a0(undefined1 *param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = DAT_42000294;
  iVar2 = DAT_42000170;
  memw();
  memw();
  *(uint *)(DAT_42000170 + 0x148) = *(uint *)(DAT_42000170 + 0x148) & 0xfffffffd;
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) & DAT_42000538;
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) & DAT_4200053c | 0x20;
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) & uVar3 | ((byte)param_1[3] & 1) << 0xe;
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) & DAT_4200028c | ((byte)param_1[4] & 1) << 0xf;
  uVar3 = DAT_42000548;
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) | DAT_42000540;
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) & DAT_42000544;
  memw();
  bVar1 = param_1[2];
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) | uVar3;
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) & DAT_4200054c | (bVar1 & 1) << 0x1a;
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) | DAT_42000550;
  (*(code *)PTR_FUN_42000554)(0x61,1,5,2,0,*param_1);
  memw();
  memw();
  *(uint *)(iVar2 + 0xe8) = *(uint *)(iVar2 + 0xe8) & DAT_420001bc | ((byte)param_1[1] & 1) << 0x1e;
  return;
}