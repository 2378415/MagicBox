undefined4 FUN_4037faa8(int param_1,uint param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  memw();
  memw();
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & 0xfffffff7 | (param_5 >> 0x1f) << 3;
  memw();
  memw();
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | DAT_403747ec;
  memw();
  memw();
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | DAT_40374970;
  if (param_2 < 0x100) {
    memw();
    memw();
    *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | DAT_4037450c;
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xffff0000 | param_2 & 0xffff;
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xfffffff | DAT_403747d4;
  }
  else {
    memw();
    memw();
    *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | DAT_4037450c;
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xffff0000 | param_2 & 0xffff;
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | DAT_403750e0;
  }
  memw();
  memw();
  *(uint *)(iVar1 + 0x3c) = *(uint *)(iVar1 + 0x3c) & 0xfffffffd | (uint)(param_3 == 0x20) * 2;
  memw();
  memw();
  *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0x3ffffff | (param_3 + -1) * 0x4000000;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & DAT_403747d8 | (uint)(param_3 != 0) << 0x1e;
  param_4 = (uint)*(byte *)(param_1 + 0xc) + param_4;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & DAT_403747e0 | (uint)(param_4 != 0) << 0x1d;
  memw();
  memw();
  *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xffffffc0 | param_4 - 1U & 0x3f;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & DAT_403747e8;
  memw();
  memw();
  *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) & 0xfffffc00;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & DAT_403747e4;
  memw();
  memw();
  *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) & 0xfffffc00;
  FUN_4037f890(iVar1,param_5 & 0xffff);
  return 0;
}