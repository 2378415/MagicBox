// 4200f7ec  FUN_4200f7ec  FUN_4200f7ec  size=80

void FUN_4200f7ec(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_42000e58;
  puVar1 = DAT_42000e54;
  DAT_42000e58[0xc5] = 0;
  *puVar1 = 0;
  *puVar2 = 0;
  *(undefined1 *)(puVar2 + 1) = 0;
  puVar2[0x82] = 0;
  puVar2[0x83] = 0;
  *(undefined1 *)(puVar2 + 0x84) = 0;
  puVar1[0xc] = 0;
  puVar1[0x429] = 0;
  memw();
  puVar1[0x321] = 0;
  if (*(int *)(puVar1 + 4) != 0) {
    *(undefined1 *)(*(int *)(puVar1 + 4) + 0x1d5) = 0;
  }
  return;
}


