void FUN_420148b0(uint param_1,undefined4 param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  param_1 = param_1 & 0xff;
  pbVar1 = (byte *)(DAT_4200135c + param_1 * DAT_42001360);
  iVar3 = *(int *)(pbVar1 + 0xc);
  iVar2 = *(int *)(pbVar1 + 8) + param_3;
  *(int *)(pbVar1 + 8) = iVar2;
  *(int *)(pbVar1 + 0xc) = iVar3 - param_3;
  if (iVar3 - param_3 == 0) {
    if (pbVar1[0x14] == 0) {
      if (*(short *)(pbVar1 + 6) == 0) {
        return;
      }
      if ((*pbVar1 & 0x80) == 0) {
        return;
      }
      FUN_42016068(param_1,0,0,0);
      return;
    }
    pbVar1[0x14] = 0;
    iVar2 = 0;
  }
  FUN_42015ec8(param_1,0x80,iVar2);
  return;
}