undefined4 FUN_4202d4fc(int param_1,uint param_2,uint *param_3,char param_4,uint *param_5)

{
  byte *pbVar1;
  uint uVar2;
  
  *param_5 = 0;
  if (param_4 != '\0') {
    if (param_4 == '\x01') {
      uVar2 = *param_3 + 1;
      if (param_2 < uVar2) {
        return 0;
      }
      *param_5 = (uint)*(byte *)(param_1 + *param_3);
      *param_3 = uVar2;
    }
    else if (param_4 == '\x02') {
      uVar2 = *param_3 + 2;
      if (param_2 < uVar2) {
        return 0;
      }
      *param_5 = (uint)*(ushort *)(param_1 + *param_3);
      *param_3 = uVar2;
    }
    else {
      if (param_4 != '\x03') {
        return 0;
      }
      uVar2 = *param_3 + 4;
      if (param_2 < uVar2) {
        return 0;
      }
      pbVar1 = (byte *)(param_1 + *param_3);
      *param_5 = (uint)pbVar1[1] << 8 | (uint)pbVar1[2] << 0x10 | (uint)*pbVar1 |
                 (uint)pbVar1[3] << 0x18;
      *param_3 = uVar2;
    }
  }
  return 1;
}