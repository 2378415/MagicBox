undefined4 FUN_4200e524(int param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  puVar2 = *(undefined1 **)(*(int *)(param_1 + 0x2af0) + 0xa58);
  *puVar2 = 0x23;
  puVar2[1] = 1;
  puVar2[2] = param_3;
  puVar2[3] = 0;
  puVar2[4] = param_2;
  puVar2[5] = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  uVar1 = FUN_4200df94(*(undefined4 *)(param_1 + 0x2af0),puVar2,0);
  return uVar1;
}