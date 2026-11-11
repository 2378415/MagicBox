void FUN_42015324(uint param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = DAT_420013c8;
  iVar3 = DAT_420013c4;
  bVar1 = *param_2;
  uVar4 = *(undefined4 *)(param_2 + 4);
  if ((char)bVar1 < '\0') {
    iVar2 = DAT_4200135c + (bVar1 & 0x7f) * 0xc + (param_1 & 0xff) * DAT_42001360;
    *(byte *)(iVar2 + DAT_420013cc) = bVar1;
    *(undefined4 *)(iVar2 + iVar3) = uVar4;
  }
  else {
    iVar3 = DAT_4200135c + (uint)bVar1 * 0xc + (param_1 & 0xff) * DAT_42001360;
    *(byte *)(iVar3 + DAT_420013d4) = bVar1;
    *(undefined4 *)(iVar3 + iVar2) = uVar4;
  }
  return;
}