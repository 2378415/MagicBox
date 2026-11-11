void FUN_4200d724(int param_1,uint param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  uVar3 = DAT_42000d14;
  puVar2 = DAT_42000d10;
  DAT_42000d10[2] = DAT_42000d18;
  puVar4 = *(undefined4 **)(param_1 + 0x1c);
  puVar2[1] = 0xe8;
  *puVar2 = uVar3;
  cVar1 = *(char *)(param_1 + 0x20);
  *puVar4 = uVar3;
  if (cVar1 != '\0') {
    puVar4[0x14] = puVar4[0x14] + 0x40;
  }
  puVar2[0x25] = param_2 & 0xff;
  return;
}