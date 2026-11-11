// 403792a4  FUN_403792a4  FUN_403792a4  size=201

void FUN_403792a4(char param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar3 = DAT_40374a28;
  puVar2 = DAT_40374a24;
  uVar1 = DAT_40374a20;
  if (param_1 == '\0') {
    memw();
    memw();
    *DAT_40374a28 = *DAT_40374a28 | 0x80;
    memw();
    memw();
    *puVar3 = *puVar3 & DAT_40374a44;
  }
  else {
    memw();
    memw();
    *DAT_40374a1c = *DAT_40374a1c | DAT_40374a20;
    puVar3 = DAT_40374a28;
    memw();
    memw();
    *puVar2 = *puVar2 | uVar1;
    memw();
    memw();
    *puVar3 = *puVar3 & DAT_40374a2c;
    memw();
    memw();
    *puVar3 = *puVar3 & DAT_40374a30 | DAT_40374a34;
    memw();
    memw();
    *puVar3 = *puVar3 & DAT_40374a38 | DAT_40374a3c;
    memw();
    memw();
    *puVar3 = *puVar3 & DAT_40374a40 | DAT_40374a08;
    memw();
    memw();
    *puVar3 = *puVar3 | 0x200;
    memw();
    memw();
    *puVar3 = *puVar3 | DAT_403748ec;
  }
  return;
}


