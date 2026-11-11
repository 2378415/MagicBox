// 40379bb8  FUN_40379bb8  FUN_40379bb8  size=380

void FUN_40379bb8(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar1 = DAT_40374ac8;
  memw();
  memw();
  *DAT_40374ac4 = (param_1 & 1) << 4 | *DAT_40374ac4 & 0xffffffef;
  memw();
  uVar3 = param_1 >> 1 & 1;
  memw();
  *puVar1 = *puVar1 & 0xfffffeff | uVar3 << 8;
  puVar2 = DAT_40374ad0;
  memw();
  memw();
  *puVar1 = *puVar1 & DAT_40374acc | uVar3 << 0xb;
  memw();
  uVar3 = param_1 >> 6 & 1;
  memw();
  *puVar2 = *puVar2 & 0xffffffef | uVar3 << 4;
  memw();
  memw();
  *puVar2 = *puVar2 & 0xfffffffb | uVar3 << 2;
  puVar1 = DAT_40374ad4;
  memw();
  memw();
  *puVar2 = *puVar2 & 0xfffffffe | uVar3;
  memw();
  uVar4 = param_1 >> 4 & 1;
  memw();
  *puVar1 = *puVar1 & 0xfffffff7 | uVar4 << 3;
  puVar2 = DAT_40374ad8;
  memw();
  memw();
  *puVar1 = *puVar1 & 0xfffffffd | uVar4 * 2;
  memw();
  uVar4 = param_1 >> 5 & 1;
  memw();
  *puVar2 = *puVar2 & 0xffffffdf | uVar4 << 5;
  memw();
  memw();
  *puVar2 = *puVar2 & 0xfffffff7 | uVar4 << 3;
  puVar1 = DAT_40374adc;
  memw();
  memw();
  *puVar2 = *puVar2 & 0xfffffffd | uVar4 * 2;
  puVar2 = DAT_40374ae0;
  memw();
  memw();
  *puVar1 = *puVar1 & 0xffffffdf | uVar3 << 5;
  memw();
  memw();
  *puVar2 = *puVar2 & 0xfffffbff | uVar3 << 10;
  puVar1 = DAT_40374ae4;
  memw();
  if ((param_1 & 0x80) == 0) {
    memw();
    *DAT_40374ae4 = *DAT_40374ae4 & DAT_40374aec;
  }
  else {
    memw();
    *DAT_40374ae4 = *DAT_40374ae4 | DAT_40374ae8;
  }
  if ((param_1 & 0x100) == 0) {
    memw();
    memw();
    *puVar1 = *puVar1 & 0xfffffff8;
  }
  else {
    memw();
    memw();
    *puVar1 = *puVar1 | 7;
  }
  return;
}


