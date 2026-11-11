// 40383850  FUN_40383850  FUN_40383850  size=168

void FUN_40383850(undefined4 param_1,ushort param_2)

{
  ushort uStack_30;
  byte bStack_2e;
  byte abStack_2d [45];
  
  uStack_30 = 0;
  bStack_2e = 0;
  abStack_2d[0] = 0;
  (*DAT_403752c0)(param_1,4,5,8,0,0,0,0,0,&bStack_2e,8,1,0);
  (*DAT_403752c0)(param_1,4,0x15,8,0,0,0,0,0,abStack_2d,8,1,0);
  uStack_30 = (ushort)bStack_2e | (param_2 | abStack_2d[0] & 0xfff8) << 8;
  (*DAT_403752c4)(*DAT_403747dc);
  (*DAT_403752c0)(param_1,4,1,8,0,0,0,&uStack_30,0x10,0,0,1,0);
  return;
}


