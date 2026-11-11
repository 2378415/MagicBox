void FUN_420136f0(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  memw();
  memw();
  *(uint *)(iVar1 + 0x4c) = *(uint *)(iVar1 + 0x4c) & 0xfffffffe;
  memw();
  memw();
  *(uint *)(iVar1 + 0x4c) = *(uint *)(iVar1 + 0x4c) & 0xfffffff7;
  memw();
  memw();
  *(uint *)(iVar1 + 0x4c) = *(uint *)(iVar1 + 0x4c) & 0xffffffef;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & DAT_42000480;
  memw();
  memw();
  *(uint *)(*param_1 + 0x20) = *(uint *)(*param_1 + 0x20) & 0xfffffffd;
  memw();
  memw();
  *(uint *)(*param_1 + 0x20) = *(uint *)(*param_1 + 0x20) | 0xc;
  memw();
  memw();
  *(uint *)(*param_1 + 0x20) = *(uint *)(*param_1 + 0x20) & 0xffffffcf | 0x10;
  memw();
  memw();
  *(uint *)(*param_1 + 0x48) = *(uint *)(*param_1 + 0x48) & DAT_42001040;
  iVar1 = *param_1;
  memw();
  memw();
  *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) & DAT_4200103c;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & DAT_42000164;
  return;
}