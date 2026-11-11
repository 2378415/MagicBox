int FUN_4200e894(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = *(undefined1 **)(*(int *)(param_1 + 0x2af0) + 0xa58);
  *puVar2 = 0xa0;
  puVar2[1] = 6;
  puVar2[2] = 0;
  puVar2[3] = 0x29;
  puVar2[4] = 0;
  puVar2[5] = 0;
  puVar2[6] = 9;
  puVar2[7] = 0;
  iVar1 = FUN_4200df94(*(undefined4 *)(param_1 + 0x2af0),puVar2,
                       DAT_42000c54 + (uint)*(byte *)(*(int *)(param_1 + 0x2af4) + 4) * 0x20);
  if (-1 < iVar1) {
    (*DAT_420002fc)(param_2,DAT_42000c54 + (uint)*(byte *)(*(int *)(param_1 + 0x2af4) + 4) * 0x20,9)
    ;
  }
  return iVar1;
}