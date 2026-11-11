void FUN_4202d150(int param_1,int param_2)

{
  byte *pbVar1;
  uint uVar2;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x210) != 0)) && (param_2 - 1U < 5)) {
    uVar2 = (uint)*(byte *)(param_1 + 0x20c) * 8 +
            *(int *)((param_2 - 1U) * 4 + *(int *)(param_1 + 0x210));
    if (uVar2 < (uint)(*(int *)(param_1 + (uint)*(byte *)(param_1 + 0x52c) * 4 + 0x524) << 3)) {
      pbVar1 = (byte *)(param_1 + (uint)*(byte *)(param_1 + 0x52c) * 0x100 + 0x321 + (uVar2 >> 3));
      *pbVar1 = (byte)(0xfffffffefffffffe >> 0x20 - (uVar2 & 7)) & *pbVar1;
    }
  }
  return;
}