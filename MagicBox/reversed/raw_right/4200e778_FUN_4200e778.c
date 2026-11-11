// 4200e778  FUN_4200e778  FUN_4200e778  size=106

int FUN_4200e778(int param_1,undefined1 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = *(undefined1 **)(*(int *)(param_1 + 0x2af0) + 0xa58);
  *puVar2 = 0xa3;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = param_2;
  puVar2[5] = 0;
  puVar2[6] = 4;
  puVar2[7] = 0;
  iVar1 = FUN_4200df94(*(undefined4 *)(param_1 + 0x2af0),puVar2,
                       DAT_42000c54 + (uint)*(byte *)(*(int *)(param_1 + 0x2af4) + 4) * 0x20);
  if (-1 < iVar1) {
    (*DAT_420002fc)(param_3,DAT_42000c54 + (uint)*(byte *)(*(int *)(param_1 + 0x2af4) + 4) * 0x20,4)
    ;
  }
  return iVar1;
}


