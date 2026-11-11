void FUN_4037b230(undefined4 param_1,undefined1 *param_2)

{
  byte bVar1;
  uint *puVar2;
  uint *puVar3;
  
  (*DAT_40374ca4)(0,param_1);
  puVar2 = DAT_40374c90;
  memw();
  memw();
  *DAT_40374c90 = *DAT_40374c90 & DAT_40374868;
  memw();
  memw();
  *puVar2 = *puVar2 | DAT_40374c94;
  if (param_2 != (undefined1 *)0x0) {
    (*DAT_40374ca8)(0,*param_2);
    puVar3 = DAT_40374c98;
    bVar1 = param_2[1];
    memw();
    if (bVar1 == 0) {
      memw();
      *puVar2 = *puVar2 & DAT_40374864;
    }
    else {
      memw();
      *puVar2 = *puVar2 | DAT_40374a60;
      memw();
      memw();
      *puVar3 = (uint)*(byte *)(*DAT_40374860 + 0x18) + (bVar1 - 1) & 0x3f | *puVar3 & 0xffffffc0;
    }
    puVar3 = DAT_40374ca0;
    puVar2 = DAT_40374c9c;
    memw();
    memw();
    *DAT_40374c9c = *DAT_40374c9c & 0xffff0000 | (uint)*(ushort *)(param_2 + 2);
    memw();
    memw();
    *puVar2 = ((byte)param_2[4] - 1) * 0x10000000 | *puVar2 & 0xfffffff;
    memw();
    memw();
    *puVar3 = ((byte)param_2[5] & 1) * 2 | *puVar3 & 0xfffffffd;
  }
  return;
}