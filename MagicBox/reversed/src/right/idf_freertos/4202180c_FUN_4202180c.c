int FUN_4202180c(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 < 0x10000) {
    param_1 = param_1 << 0x10;
    iVar1 = 0x10;
  }
  if (param_1 < 0x1000000) {
    iVar1 = iVar1 + 8;
    param_1 = param_1 << 8;
  }
  if (param_1 < 0x10000000) {
    iVar1 = iVar1 + 4;
    param_1 = param_1 << 4;
  }
  if (param_1 < 0x40000000) {
    iVar1 = iVar1 + 2;
    param_1 = param_1 << 2;
  }
  if ((-1 < (int)param_1) && (iVar1 = iVar1 + 1, (param_1 >> 0x1e & 1) == 0)) {
    iVar1 = 0x20;
  }
  return iVar1;
}