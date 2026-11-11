void hid_report_set_bits(int param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte bVar3;
  
  if (((param_3 & 0xff) + param_2 + 7 >> 3 <= param_5 >> 3) && ((param_3 & 0xff) != 0)) {
    pbVar2 = (byte *)(param_1 + (param_2 >> 3 & 0xff));
    bVar1 = *pbVar2;
    bVar3 = (byte)(1 << 0x20 - (0x20 - (param_2 & 7)));
    if ((param_4 & 1) == 0) {
      bVar3 = bVar3 & bVar1 ^ bVar1;
    }
    else {
      bVar3 = bVar3 | bVar1;
    }
    *pbVar2 = bVar3;
  }
  return;
}