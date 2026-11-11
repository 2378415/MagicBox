byte FUN_4038267c(undefined4 *param_1)

{
  bool bVar1;
  undefined1 auStack_40 [2];
  undefined1 uStack_3e;
  undefined1 uStack_3d;
  undefined4 uStack_3c;
  byte *pbStack_34;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  byte abStack_24 [36];
  
  bVar1 = *(short *)((int)param_1 + 0x1a) == 0x46;
  if (*(short *)((int)param_1 + 0x1a) == 0x20) {
    abStack_24[0] = 0;
    (*DAT_4037448c)(auStack_40,0,0x1c);
    uStack_3e = 1;
    uStack_3d = 0x18;
    uStack_3c = 0x32;
    pbStack_34 = abStack_24;
    uStack_2c = 0x5a;
    uStack_2a = 8;
    (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,auStack_40);
    if ((abStack_24[0] & 8) != 0) {
      bVar1 = true;
    }
  }
  if (*(short *)((int)param_1 + 0x1a) == 0xa1) {
    bVar1 = true;
  }
  return bVar1 | 4;
}