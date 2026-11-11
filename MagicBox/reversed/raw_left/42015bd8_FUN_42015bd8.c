// 42015bd8  FUN_42015bd8  FUN_42015bd8  size=286

undefined4 FUN_42015bd8(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint local_30;
  
  uVar1 = DAT_4200034c;
  memw();
  iVar4 = *(int *)((param_1 & 0xff) * 8 + DAT_420013e0 + 4);
  iVar2 = (param_2 & 0x7f) * 0x20;
  if ((param_2 & 0x80) == 0) {
    puVar3 = (uint *)(iVar4 + 0xb00 + iVar2);
    memw();
    if ((int)*puVar3 < 0) {
      memw();
      memw();
      *puVar3 = *puVar3 | DAT_42000550;
      uVar5 = DAT_4200142c;
      memw();
      memw();
      *puVar3 = *puVar3 | uVar1;
      memw();
      local_30 = 0;
      do {
        memw();
        local_30 = local_30 + 1;
        memw();
        if (uVar5 < local_30) break;
        memw();
      } while ((puVar3[2] & 2) == 0);
      memw();
      puVar3[2] = 2;
    }
    memw();
    uVar5 = *(uint *)(iVar4 + 0x83c);
    uVar1 = DAT_42000d30 << 0x20 - (0x20 - (param_2 & 7)) ^ 0xffffffff;
  }
  else {
    puVar3 = (uint *)(iVar4 + 0x900 + iVar2);
    memw();
    if ((int)*puVar3 < 0) {
      memw();
      memw();
      *puVar3 = *puVar3 | DAT_42000550;
      uVar5 = DAT_4200142c;
      memw();
      memw();
      *puVar3 = *puVar3 | uVar1;
      memw();
      local_30 = 0;
      do {
        memw();
        local_30 = local_30 + 1;
        memw();
        if (uVar5 < local_30) break;
        memw();
      } while ((puVar3[2] & 2) == 0);
      memw();
      puVar3[2] = 2;
    }
    memw();
    uVar5 = *(uint *)(iVar4 + 0x83c);
    uVar1 = (uint)(0xfffffffefffffffe >> 0x20 - (param_2 & 7));
  }
  memw();
  *(uint *)(iVar4 + 0x83c) = uVar5 & uVar1;
  memw();
  memw();
  *(uint *)(iVar4 + 0x81c) = uVar1 & *(uint *)(iVar4 + 0x81c);
  memw();
  *puVar3 = 0;
  return 0;
}


