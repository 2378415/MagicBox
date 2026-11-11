// 40378e68  FUN_40378e68  FUN_40378e68  size=236

void FUN_40378e68(char param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = DAT_40374978;
  uVar1 = DAT_40374970;
  if (param_1 == '\0') {
    memw();
    memw();
    *DAT_40374978 = *DAT_40374978 | 0x80;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_40374990;
  }
  else {
    memw();
    memw();
    *DAT_4037496c = *DAT_4037496c | DAT_40374970;
    memw();
    memw();
    *DAT_40374974 = *DAT_40374974 | uVar1;
    puVar2 = DAT_40374978;
    memw();
    memw();
    *DAT_40374978 = *DAT_40374978 & DAT_4037497c;
    uVar1 = DAT_40374658;
    uVar3 = DAT_40374658 | 0x6c0;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_40374980 | DAT_40374984;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_40374988 | (uVar3 >> 6 & 7) << 0xd;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_4037498c | (uVar3 >> 9 & 7) << 10;
    memw();
    memw();
    *puVar2 = *puVar2 & 0xfffffdff | (uVar1 >> 0xc & 1) << 9;
    memw();
    memw();
    *puVar2 = *puVar2 | DAT_40374870;
  }
  return;
}


