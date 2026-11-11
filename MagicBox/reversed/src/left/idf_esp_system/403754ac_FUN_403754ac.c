void FUN_403754ac(void)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  puVar2 = DAT_4037444c;
  puVar1 = DAT_40374448;
  memw();
  uVar4 = *DAT_40374448;
  memw();
  uVar3 = *DAT_4037444c;
  FUN_4037ee64(1,2);
  memw();
  uVar5 = *puVar1;
  memw();
  *puVar1 = ((uVar4 ^ 0xffffffff) & 1) * 2 & uVar5 ^ uVar5;
  memw();
  uVar4 = *puVar2;
  memw();
  *puVar2 = (uVar3 >> 1 & 1 ^ 1) & uVar4 ^ uVar4;
  FUN_4037ee98(1,2);
  return;
}