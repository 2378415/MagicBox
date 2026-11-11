// 40382438  FUN_40382438  FUN_40382438  size=97

uint FUN_40382438(undefined4 *param_1)

{
  short sVar1;
  uint uVar2;
  int local_40 [3];
  uint *puStack_34;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  uint auStack_24 [9];
  
  sVar1 = *(short *)((int)param_1 + 0x1a);
  uVar2 = 1;
  if ((sVar1 != 0x46) && (uVar2 = 0, sVar1 == 0x20)) {
    auStack_24[0] = auStack_24[0] & 0xffffff00;
    uStack_2a = 8;
    local_40[0] = DAT_40375324 << 0x10;
    local_40[1] = 0x32;
    puStack_34 = auStack_24;
    uStack_2c = 0x5a;
    (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,local_40);
    sVar1 = *(short *)((int)param_1 + 0x1a);
    uVar2 = auStack_24[0] >> 3 & 1;
  }
  return sVar1 == 0xa1 | uVar2 | 4;
}


