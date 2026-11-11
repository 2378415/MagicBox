// 4037f4a4  FUN_4037f4a4  FUN_4037f4a4  size=390

undefined4 FUN_4037f4a4(int param_1,uint param_2,int param_3,int param_4,uint param_5)

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
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | DAT_4037450c;
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar1 + 0x18) = param_2 & 0xff | DAT_403747d4;
  }
  else {
    memw();
    memw();
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | DAT_4037450c;
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar1 + 0x18) = param_2 & 0xff | DAT_403750e0;
  }
  memw();
  memw();
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & 0x7ffffff | (param_3 + -1) * 0x8000000;
  memw();
  memw();
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & DAT_403747d8 | (uint)(param_3 != 0) << 0x1e;
  param_4 = (uint)*(byte *)(param_1 + 0xc) + param_4;
  memw();
  memw();
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & DAT_403747e0 | (uint)(param_4 != 0) << 0x1d;
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & 0xffffff00 | param_4 - 1U & 0xff;
  memw();
  memw();
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & DAT_403747e8;
  memw();
  memw();
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & DAT_403747e4;
  FUN_4037f1b0(iVar1,param_5 & 0xffff);
  return 0;
}


