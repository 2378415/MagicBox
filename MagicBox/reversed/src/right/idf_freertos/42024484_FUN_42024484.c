void FUN_42024484(int *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (param_2 == 0) {
    memw();
    memw();
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xfffffeff;
  }
  else {
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar1 + 0x44) = *(uint *)(iVar1 + 0x44) & 0xffffff00 | param_2 & 0xff;
    memw();
    memw();
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | 0x100;
  }
  return;
}