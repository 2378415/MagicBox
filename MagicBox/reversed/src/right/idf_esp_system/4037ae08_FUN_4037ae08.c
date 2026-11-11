void FUN_4037ae08(undefined4 param_1,undefined1 *param_2)

{
  uint *puVar1;
  
  (*DAT_40374bec)(0,param_1);
  puVar1 = DAT_40374bd8;
  memw();
  memw();
  *DAT_40374bd8 = *DAT_40374bd8 & DAT_403747e4;
  memw();
  memw();
  *puVar1 = *puVar1 | DAT_40374bdc;
  if (param_2 != (undefined1 *)0x0) {
    (*DAT_40374bf0)(0,*param_2);
    if (param_2[1] == '\0') {
      memw();
      memw();
      *DAT_40374bd8 = *DAT_40374bd8 & DAT_403747e0;
    }
    else {
      memw();
      memw();
      *DAT_40374bd8 = *DAT_40374bd8 | DAT_403749c8;
      memw();
      memw();
      *DAT_40374be0 =
           *DAT_40374be0 & 0xffffffc0 |
           ((byte)param_2[1] - 1) + (uint)*(byte *)(*DAT_403747dc + 0x18) & 0x3f;
    }
    puVar1 = DAT_40374be4;
    memw();
    memw();
    *DAT_40374be4 = *DAT_40374be4 & 0xffff0000 | (uint)*(ushort *)(param_2 + 2);
    memw();
    memw();
    *puVar1 = *puVar1 & 0xfffffff | ((byte)param_2[4] - 1) * 0x10000000;
    memw();
    memw();
    *DAT_40374be8 = *DAT_40374be8 & 0xfffffffd | (uint)(byte)param_2[5] * 2 & 2;
  }
  return;
}