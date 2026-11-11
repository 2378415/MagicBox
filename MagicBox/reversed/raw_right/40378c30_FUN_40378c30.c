// 40378c30  FUN_40378c30  FUN_40378c30  size=99

void FUN_40378c30(void)

{
  uint *puVar1;
  uint uVar2;
  undefined4 local_50 [20];
  
  puVar1 = DAT_40374944;
  memw();
  memw();
  *DAT_40374944 = *DAT_40374944 | 0x10;
  memw();
  memw();
  *puVar1 = *puVar1 | 3;
  memw();
  memw();
  *puVar1 = *puVar1 | 0xc;
  (*DAT_403744d4)(local_50,PTR_DAT_40374948,0x24);
  for (uVar2 = 0; uVar2 < 9; uVar2 = uVar2 + 1) {
    memw();
    memw();
    *(uint *)local_50[uVar2] = *(uint *)local_50[uVar2] | DAT_4037494c;
  }
  return;
}


