// 4201aad8  FUN_4201aad8  FUN_4201aad8  size=131

void FUN_4201aad8(undefined4 *param_1,char param_2)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = DAT_42000170;
  puVar2 = (uint *)*param_1;
  memw();
  if (param_2 == '\0') {
    memw();
    *puVar2 = *puVar2 & 0xfffffffb;
    memw();
    memw();
    *(uint *)(iVar1 + 0x120) = *(uint *)(iVar1 + 0x120) | DAT_42000b50;
    memw();
    memw();
    *(uint *)(iVar1 + 0x120) = *(uint *)(iVar1 + 0x120) | DAT_42000a7c;
    memw();
    memw();
    *puVar2 = *puVar2 | DAT_42000528;
  }
  else {
    memw();
    *puVar2 = *puVar2 | 4;
    memw();
    memw();
    *(uint *)(iVar1 + 0x120) = *(uint *)(iVar1 + 0x120) | DAT_42000b50;
    memw();
    memw();
    *(uint *)(iVar1 + 0x120) = *(uint *)(iVar1 + 0x120) & DAT_420019a4;
  }
  return;
}


