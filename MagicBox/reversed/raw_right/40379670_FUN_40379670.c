// 40379670  FUN_40379670  FUN_40379670  size=431

void FUN_40379670(uint param_1)

{
  uint *puVar1;
  
  memw();
  memw();
  *DAT_40374a08 = *DAT_40374a08 & 0xffffffef | (param_1 & 1) << 4;
  puVar1 = DAT_40374a0c;
  memw();
  memw();
  *DAT_40374a0c = *DAT_40374a0c & 0xfffffeff | (param_1 >> 1 & 1) << 8;
  memw();
  memw();
  *puVar1 = *puVar1 & DAT_40374a10 | (param_1 >> 1 & 1) << 0xb;
  puVar1 = DAT_40374a14;
  memw();
  memw();
  *DAT_40374a14 = *DAT_40374a14 & 0xffffffef | (param_1 >> 6 & 1) << 4;
  memw();
  memw();
  *puVar1 = *puVar1 & 0xfffffffb | (param_1 >> 6 & 1) << 2;
  memw();
  memw();
  *puVar1 = *puVar1 & 0xfffffffe | param_1 >> 6 & 1;
  puVar1 = DAT_40374a18;
  memw();
  memw();
  *DAT_40374a18 = *DAT_40374a18 & 0xfffffff7 | (param_1 >> 4 & 1) << 3;
  memw();
  memw();
  *puVar1 = *puVar1 & 0xfffffffd | (param_1 >> 4 & 1) * 2;
  puVar1 = DAT_40374a1c;
  memw();
  memw();
  *DAT_40374a1c = *DAT_40374a1c & 0xffffffdf | (param_1 >> 5 & 1) << 5;
  memw();
  memw();
  *puVar1 = *puVar1 & 0xfffffff7 | (param_1 >> 5 & 1) << 3;
  memw();
  memw();
  *puVar1 = *puVar1 & 0xfffffffd | (param_1 >> 5 & 1) * 2;
  memw();
  memw();
  *DAT_40374a20 = *DAT_40374a20 & 0xffffffdf | (param_1 >> 6 & 1) << 5;
  memw();
  memw();
  *DAT_40374a24 = *DAT_40374a24 & 0xfffffbff | (param_1 >> 6 & 1) << 10;
  if ((param_1 & 0x80) == 0) {
    memw();
    memw();
    *DAT_40374a28 = *DAT_40374a28 & DAT_40374a30;
  }
  else {
    memw();
    memw();
    *DAT_40374a28 = *DAT_40374a28 | DAT_40374a2c;
  }
  if ((param_1 & 0x100) == 0) {
    memw();
    memw();
    *DAT_40374a28 = *DAT_40374a28 & 0xfffffff8;
  }
  else {
    memw();
    memw();
    *DAT_40374a28 = *DAT_40374a28 | 7;
  }
  return;
}


