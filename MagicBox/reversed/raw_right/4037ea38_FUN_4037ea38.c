// 4037ea38  FUN_4037ea38  FUN_4037ea38  size=149

void FUN_4037ea38(void)

{
  char cVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  
  FUN_4037e9d0();
  cVar1 = DAT_40374fd8[1];
  if (*DAT_40374fd8 == '\0') {
    uVar4 = 0;
  }
  else {
    uVar4 = 4;
  }
  (*DAT_40374fe0)(uVar4);
  if (cVar1 == '\0') {
    uVar4 = 0;
  }
  else {
    uVar4 = 4;
  }
  (*DAT_40374fe4)(uVar4);
  puVar2 = DAT_40374438;
  memw();
  memw();
  *DAT_40374438 = *DAT_40374438;
  puVar3 = DAT_4037443c;
  memw();
  memw();
  *DAT_4037443c = *DAT_4037443c & 0xfffffffd;
  memw();
  memw();
  *puVar2 = *puVar2 & 0xfffffffe;
  memw();
  memw();
  *puVar3 = *puVar3;
  memw();
  memw();
  *puVar2 = *puVar2;
  memw();
  memw();
  *puVar3 = *puVar3 & 0xfffffffe;
  memw();
  memw();
  *puVar2 = *puVar2 & 0xfffffffd;
  memw();
  memw();
  *puVar3 = *puVar3;
  return;
}


