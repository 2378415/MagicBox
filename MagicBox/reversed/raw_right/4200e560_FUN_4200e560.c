// 4200e560  FUN_4200e560  FUN_4200e560  size=60

undefined4 FUN_4200e560(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  puVar2 = *(undefined1 **)(*(int *)(param_1 + 0x2af0) + 0xa58);
  *puVar2 = 0x20;
  puVar2[1] = 0xc;
  puVar2[2] = (char)param_2;
  puVar2[3] = (char)((uint)param_2 >> 8);
  puVar2[4] = 0;
  puVar2[5] = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  uVar1 = FUN_4200df94(*(undefined4 *)(param_1 + 0x2af0),puVar2,0);
  return uVar1;
}


