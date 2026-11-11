void FUN_420137ac(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = FUN_42024b5c(param_1);
  iVar2 = *param_1;
  uVar3 = iVar1 * (param_2 & 0xff);
  if ((uVar3 & 0xffff) == 0) {
    memw();
    memw();
    *(uint *)(iVar2 + 0x24) = *(uint *)(iVar2 + 0x24) & DAT_42000854;
  }
  else {
    memw();
    memw();
    *(uint *)(iVar2 + 0x60) = *(uint *)(iVar2 + 0x60) & DAT_42001044 | (uVar3 & 0x3ff) << 0x11;
    memw();
    memw();
    *(uint *)(iVar2 + 0x24) = *(uint *)(iVar2 + 0x24) | DAT_42000850;
  }
  return;
}