int FUN_4201c594(int param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  byte local_30 [48];
  
  iVar1 = DAT_42001a44;
  if ((*(char *)(param_1 + 0x12) != '\0') &&
     (iVar1 = FUN_4201c3a0(*(undefined4 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0x10),param_2,
                           local_30), iVar1 == 0)) {
    uVar2 = (uint)local_30[0];
    if ((uVar2 == 0x48) || (uVar2 == 0x41)) {
      uVar2 = 0x42;
    }
    *param_3 = uVar2;
  }
  return iVar1;
}