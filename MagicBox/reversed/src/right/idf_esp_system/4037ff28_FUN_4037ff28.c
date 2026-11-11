void FUN_4037ff28(int *param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)param_1[1];
  memw();
  memw();
  puVar1[0xf] = puVar1[0xf] & 0xfffffffd;
  memw();
  memw();
  puVar1[7] = puVar1[7] & 0x3ffffff | DAT_403750ec;
  memw();
  memw();
  puVar1[6] = puVar1[6] | DAT_403745e0;
  memw();
  puVar1[1] = param_2 & 0xffffff;
  memw();
  puVar1[2] = 0;
  memw();
  memw();
  *puVar1 = *puVar1 | DAT_40374890;
  if ((param_1[6] & 1U) == 0) {
    (**(code **)(*param_1 + 0x40))(param_1);
  }
  return;
}