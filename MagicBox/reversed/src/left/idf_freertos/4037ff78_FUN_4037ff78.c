// strings: ;E@BA

undefined4 FUN_4037ff78(int *param_1,uint param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  uint local_30 [12];
  
  puVar1 = (uint *)param_1[1];
  memw();
  if ((puVar1[6] & 0x40000000) != 0) {
    memw();
  }
  memw();
  puVar1[1] = param_3;
  memw();
  iVar5 = param_4 * 8;
  memw();
  puVar1[6] = puVar1[6] & DAT_4037486c | (uint)(iVar5 != 0) << 0x1c;
  memw();
  uVar3 = iVar5 - 1U & 0x3ff;
  if (iVar5 == 0) {
    uVar3 = 0;
  }
  memw();
  puVar1[10] = puVar1[10] & 0xfffffc00 | uVar3;
  memw();
  pcVar4 = *(code **)(*param_1 + 0x40);
  memw();
  *puVar1 = *puVar1 | DAT_40374870;
  (*pcVar4)();
  uVar3 = 0;
  if (param_4 != 0) {
    if (((param_2 | param_4) & 3) == 0) {
      (*DAT_4037450c)(param_2,puVar1 + 0x16,param_4);
    }
    else {
      uVar2 = param_4 + 3 >> 2;
      if (uVar2 != 0) {
        do {
          iVar5 = (param_4 < 4) * param_4 + (uint)(param_4 >= 4) * 4;
          memw();
          local_30[0] = puVar1[uVar3 + 0x16];
          uVar3 = uVar3 + 1;
          (*DAT_4037450c)(param_2,local_30,iVar5);
          param_4 = param_4 - iVar5;
          param_2 = param_2 + iVar5;
        } while (uVar3 != uVar2);
      }
    }
  }
  return 0;
}