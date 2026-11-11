void FUN_40379370(char param_1,char param_2)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar2 = DAT_40374a4c;
  puVar1 = DAT_40374a48;
  memw();
  if (param_1 == '\0') {
    memw();
    *DAT_40374a48 = *DAT_40374a48 | 0x40;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_40374a50 | 0x500;
  }
  else {
    memw();
    *DAT_40374a48 = *DAT_40374a48 & 0xffffffbf;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_40374a50 | 0x140;
    (*DAT_40374444)(0x32);
  }
  memw();
  if (param_2 == '\0') {
    memw();
    *puVar1 = *puVar1 | 0x80;
  }
  else {
    memw();
    *puVar1 = *puVar1 & 0xffffff7f;
  }
  return;
}