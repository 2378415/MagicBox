// 420147fc  FUN_420147fc  FUN_420147fc  size=120

bool FUN_420147fc(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  ushort uVar5;
  
  iVar3 = DAT_42001378;
  iVar2 = DAT_42001370;
  bVar1 = *(byte *)(param_2 + 2);
  uVar5 = *(ushort *)(param_2 + 4) & 0x7ff;
  bVar4 = (byte)(*(ushort *)(param_2 + 4) >> 0xb) & 3;
  if ((char)bVar1 < '\0') {
    iVar3 = DAT_4200135c + (bVar1 & 0x7f) * 0xc + param_1 * DAT_42001360;
    *(ushort *)(iVar3 + DAT_4200136c) = uVar5;
    *(byte *)(iVar3 + iVar2) = bVar4;
  }
  else {
    iVar2 = DAT_4200135c + (uint)bVar1 * 0xc + param_1 * DAT_42001360;
    *(ushort *)(iVar2 + DAT_42001374) = uVar5;
    *(byte *)(iVar2 + iVar3) = bVar4;
  }
  iVar2 = FUN_42015a20(param_1,param_2);
  return iVar2 == 0;
}


