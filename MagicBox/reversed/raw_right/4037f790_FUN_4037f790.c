// 4037f790  FUN_4037f790  FUN_4037f790  size=198

undefined4 FUN_4037f790(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  puVar1 = (uint *)param_1[1];
  memw();
  if ((puVar1[4] & 0x40000000) == 0) {
    uVar2 = 0;
  }
  else {
    memw();
    uVar2 = (puVar1[5] >> 0x1b) + 1 & 0xfffffff8;
    if (uVar2 == 0x20) {
      uVar4 = 0;
      goto LAB_4037f7c3;
    }
  }
  uVar4 = 0xffffffff >> (uVar2 & 0x1f);
LAB_4037f7c3:
  memw();
  puVar1[1] = param_3 << 0x20 - (0x20 - (-(uVar2 - 0x20) & 0x1f)) | uVar4;
  iVar3 = param_4 * 8;
  memw();
  memw();
  puVar1[4] = puVar1[4] & DAT_403747e8 | (uint)(iVar3 != 0) << 0x1c;
  if (iVar3 != 0) {
    memw();
    memw();
    puVar1[7] = puVar1[7] & 0xfffc0000 | iVar3 - 1U & 0x3ffff;
  }
  memw();
  memw();
  *puVar1 = *puVar1 | DAT_403749a0;
  do {
    memw();
  } while ((*puVar1 & 0x800000) != 0);
  memw();
  memw();
  *puVar1 = *puVar1 | DAT_40374890;
  (**(code **)(*param_1 + 0x40))();
  if (param_4 != 0) {
    FUN_4037f310(puVar1,param_2,param_4);
  }
  return 0;
}


