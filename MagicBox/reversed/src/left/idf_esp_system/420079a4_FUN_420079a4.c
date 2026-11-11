uint FUN_420079a4(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  puVar1 = DAT_42000878;
  memw();
  if ((*DAT_42000878 & 0x20000000) == 0) {
    iVar2 = FUN_4201a798();
    uVar3 = (uint)(iVar2 * DAT_4200087c) >> 1;
  }
  else {
    uVar3 = DAT_42000874;
    if (param_1 != 1) {
      iVar2 = FUN_42007848(param_1);
      uVar3 = iVar2 << 8;
    }
    memw();
    uVar3 = uVar3 / ((*puVar1 >> 0xc & 7) + 1);
  }
  return uVar3;
}