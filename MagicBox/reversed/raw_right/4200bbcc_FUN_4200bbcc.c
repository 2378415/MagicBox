// 4200bbcc  FUN_4200bbcc  FUN_4200bbcc  size=52

void FUN_4200bbcc(int param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_42000a70;
  uVar1 = DAT_42000a6c;
  *DAT_42000a70 = DAT_42000a6c;
  puVar2[2] = DAT_42000a78;
  puVar2[1] = 0xe8;
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  *puVar2 = uVar1;
  if (*(char *)(param_1 + 0x20) != '\0') {
    puVar2[0x14] = puVar2[0x14] + 0x40;
  }
  DAT_42000a70[0x25] = param_2 & 0xff;
  return;
}


