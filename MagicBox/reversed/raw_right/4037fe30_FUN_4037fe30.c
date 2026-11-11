// 4037fe30  FUN_4037fe30  FUN_4037fe30  size=203

undefined4 FUN_4037fe30(int *param_1,uint param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint local_30 [12];
  
  puVar1 = (uint *)param_1[1];
  memw();
  if ((puVar1[6] & 0x40000000) != 0) {
    memw();
  }
  memw();
  puVar1[1] = param_3;
  iVar3 = param_4 * 8;
  memw();
  memw();
  puVar1[6] = puVar1[6] & DAT_403747e8 | (uint)(iVar3 != 0) << 0x1c;
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = iVar3 - 1U & 0x3ff;
  }
  memw();
  memw();
  puVar1[10] = uVar4 | puVar1[10] & 0xfffffc00;
  memw();
  memw();
  *puVar1 = *puVar1 | DAT_403747ec;
  (**(code **)(*param_1 + 0x40))();
  if (param_4 != 0) {
    if (((param_2 & 3) == 0) && ((param_4 & 3) == 0)) {
      (*DAT_403744d4)(param_2,puVar1 + 0x16,param_4);
    }
    else {
      uVar4 = param_4;
      for (uVar2 = 0; uVar2 < param_4 + 3 >> 2; uVar2 = uVar2 + 1) {
        iVar3 = (uVar4 < 4) * uVar4 + (uint)(uVar4 >= 4) * 4;
        memw();
        local_30[0] = puVar1[uVar2 + 0x16];
        (*DAT_403744d4)(param_2,local_30,iVar3);
        param_2 = iVar3 + param_2;
        uVar4 = uVar4 - iVar3;
      }
    }
  }
  return 0;
}


