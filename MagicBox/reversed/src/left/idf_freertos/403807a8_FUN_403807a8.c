void FUN_403807a8(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint *puVar2;
  undefined8 uVar3;
  
  uVar3 = (*(code *)param_1[2])(param_3,param_4);
  puVar2 = (uint *)*param_1;
  memw();
  uVar1 = 1 << 0x20 - (0x20 - (-(param_2 + -0x18) & 0x1fU));
  memw();
  *puVar2 = uVar1 & *puVar2 ^ *puVar2;
  memw();
  memw();
  puVar2[param_2 * 2 + 7] =
       (uint)(CONCAT44(puVar2[param_2 * 2 + 7] >> 0x14,(int)((ulonglong)uVar3 >> 0x20) << 0xc) >>
             0xc);
  memw();
  puVar2[param_2 * 2 + 8] = (uint)uVar3;
  memw();
  puVar2[param_2 + 0x14] = 1;
  memw();
  memw();
  *puVar2 = uVar1 | *puVar2;
  return;
}