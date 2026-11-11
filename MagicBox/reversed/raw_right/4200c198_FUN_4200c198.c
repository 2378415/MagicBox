// 4200c198  FUN_4200c198  FUN_4200c198  size=107

void FUN_4200c198(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  
  memw();
  puVar1 = (uint *)(*(int *)(param_1 + 8) + 0x440);
  memw();
  uVar2 = *puVar1;
  memw();
  memw();
  memw();
  memw();
  if (((uVar2 & 0x1000) == 0) && (param_2 == 1)) {
    memw();
    memw();
    *puVar1 = uVar2 & 0xffffffd1 | DAT_4200077c;
  }
  memw();
  if (((uVar2 & 0x1000) != 0) && (param_2 == 0)) {
    memw();
    memw();
    *(uint *)(*(int *)(param_1 + 8) + 0x440) = uVar2 & 0xffffffd1 & DAT_42000888;
  }
  return;
}


