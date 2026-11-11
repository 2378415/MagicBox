// 42001b54  FUN_42001b54  FUN_42001b54  size=174
// strings: pf7@

void FUN_42001b54(void)

{
  uint uVar1;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  uVar1 = uVar1 >> 0xd & 1;
  (*(code *)PTR_FUN_42000140)(0x19);
  (*DAT_4200005c)(uVar1,0x38,0x19);
  memw();
  memw();
  *DAT_42000128 = *DAT_42000128 | 0x3f;
  memw();
  memw();
  *DAT_4200012c = *DAT_4200012c | 0x3f;
  if (uVar1 == 0) {
    (*DAT_4200005c)(0,0x5e,0x19);
    memw();
    memw();
    *DAT_42000130 = *DAT_42000130 | 0x1f;
    memw();
    memw();
    *DAT_42000134 = *DAT_42000134 | 0x1f;
  }
  else {
    (*DAT_4200005c)(uVar1,0x5f,0x19);
    memw();
    memw();
    *DAT_42000138 = *DAT_42000138 | 0x1f;
    memw();
    memw();
    *DAT_4200013c = *DAT_4200013c | 0x1f;
  }
  (*(code *)PTR_FUN_42000144)(0x19);
  return;
}


