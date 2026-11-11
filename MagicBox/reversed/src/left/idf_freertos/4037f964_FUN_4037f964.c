// strings: ;E@BA=

undefined4 FUN_4037f964(int *param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  code *pcVar5;
  uint local_30 [12];
  
  puVar2 = (uint *)param_1[1];
  memw();
  if ((puVar2[4] & 0x40000000) == 0) {
    param_3 = 0xffffffff;
  }
  else {
    memw();
    uVar3 = (puVar2[5] >> 0x1b) + 1;
    if ((uVar3 & 0xfffffff8) != 0x20) {
      param_3 = (uint)(((ulonglong)param_3 << 0x20 | 0xffffffff) >> (uVar3 & 0x18));
    }
  }
  memw();
  puVar2[1] = param_3;
  memw();
  iVar4 = param_4 * 8;
  memw();
  puVar2[4] = puVar2[4] & DAT_4037486c | (uint)(iVar4 != 0) << 0x1c;
  if (iVar4 != 0) {
    memw();
    memw();
    puVar2[7] = (uint)(CONCAT44(puVar2[7] >> 0x12,(iVar4 + -1) * 0x4000) >> 0xe);
  }
  memw();
  memw();
  *puVar2 = *puVar2 | DAT_403751a0;
  do {
    memw();
    uVar3 = *puVar2 >> 0x17 & 1;
  } while ((*puVar2 & 0x800000) != 0);
  memw();
  pcVar5 = *(code **)(*param_1 + 0x40);
  memw();
  *puVar2 = *puVar2 | DAT_40374920;
  (*pcVar5)();
  if (param_4 != 0) {
    if (((param_2 | param_4) & 3) == 0) {
      (*DAT_4037450c)(param_2,puVar2 + 0x26,param_4);
    }
    else {
      uVar1 = param_4 + 3 >> 2;
      if (uVar1 != 0) {
        do {
          iVar4 = (param_4 < 4) * param_4 + (uint)(param_4 >= 4) * 4;
          memw();
          local_30[0] = puVar2[uVar3 + 0x26];
          uVar3 = uVar3 + 1;
          (*DAT_4037450c)(param_2,local_30,iVar4);
          param_4 = param_4 - iVar4;
          param_2 = param_2 + iVar4;
        } while (uVar3 != uVar1);
      }
    }
  }
  return 0;
}