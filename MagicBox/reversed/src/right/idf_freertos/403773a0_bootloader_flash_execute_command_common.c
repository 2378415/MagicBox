// strings: mosi_len <= 32 | miso_len <= 32 | bootloader_flash.c | bootloader_flash_execute_command_common

uint FUN_403773a0(uint param_1,int param_2,uint param_3,uint param_4,uint param_5,undefined4 param_6
                 ,byte param_7)

{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint in_t0;
  uint local_50;
  uint uStack_4c;
  uint uStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  
  puVar6 = &local_50;
  param_1 = param_1 & 0xff;
  param_4 = param_4 & 0xff;
  param_5 = param_5 & 0xff;
  uVar2 = (uint)param_7;
  uStack_40 = param_6;
  if (0x20 < param_5) {
    param_1 = in_t0;
    FUN_40381d9c(PTR_s_bootloader_flash_c_3c033ef0_0x39_403747c4,0x242,
                 PTR_s_bootloader_flash_execute_command_403747c0,PTR_s_mosi_len_<__32_403747bc);
    in_t0 = param_1;
  }
  if (0x20 < uVar2) {
    param_1 = in_t0;
    FUN_40381d9c(PTR_s_bootloader_flash_c_3c033ef0_0x39_403747c4,0x243,
                 PTR_s_bootloader_flash_execute_command_403747c0,PTR_s_miso_len_<__32_403747c8);
  }
  puVar1 = DAT_403747cc;
  memw();
  uStack_3c = DAT_403747cc[2];
  memw();
  uStack_38 = DAT_403747cc[6];
  memw();
  uStack_34 = DAT_403747cc[7];
  memw();
  uStack_30 = DAT_403747cc[8];
  memw();
  DAT_403747cc[2] = 0;
  memw();
  memw();
  puVar1[2] = puVar1[2] | DAT_403747d0;
  memw();
  memw();
  puVar1[6] = puVar1[6] | DAT_4037450c;
  memw();
  memw();
  memw();
  uStack_48 = param_1 | puVar1[8] & 0xffff0000;
  memw();
  memw();
  memw();
  puVar1[8] = uStack_48;
  memw();
  memw();
  memw();
  uStack_4c = puVar1[8] & 0xfffffff | DAT_403747d4;
  memw();
  memw();
  memw();
  puVar1[8] = uStack_4c;
  memw();
  memw();
  puVar1[0xf] = puVar1[0xf] & 0xfffffffd | (uint)(param_2 == 0x20) * 2;
  memw();
  memw();
  puVar1[7] = puVar1[7] & 0x3ffffff | (param_2 + -1) * 0x4000000;
  memw();
  memw();
  puVar1[6] = puVar1[6] & DAT_403747d8 | (uint)(param_2 != 0) << 0x1e;
  memw();
  puVar1[1] = param_3;
  puVar1 = DAT_403747cc;
  if (uVar2 != 0) {
    param_4 = param_4 + *(byte *)(*DAT_403747dc + 0x19);
  }
  memw();
  memw();
  DAT_403747cc[6] = DAT_403747cc[6] & DAT_403747e0 | (uint)(param_4 != 0) << 0x1d;
  memw();
  memw();
  puVar1[7] = puVar1[7] & 0xffffffc0 | param_4 - 1 & 0x3f;
  memw();
  memw();
  puVar1[6] = puVar1[6] & DAT_403747e4 | (uint)(param_5 != 0) << 0x1b;
  if (param_5 == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = param_5 - 1 & 0x3ff;
  }
  memw();
  memw();
  DAT_403747cc[9] = uVar9 | DAT_403747cc[9] & 0xfffffc00;
  param_5 = param_5 >> 3;
  uVar9 = param_5 + 3;
  puVar3 = &uStack_40;
  for (iVar5 = 0; iVar5 < (int)(uVar9 >> 2); iVar5 = iVar5 + 1) {
    uStack_44 = 0;
    iVar7 = (param_5 < 4) * param_5 + (uint)(param_5 >= 4) * 4;
    (*DAT_403744d4)(&uStack_44,puVar3,iVar7);
    memw();
    DAT_403747cc[iVar5 + 0x16] = uStack_44;
    param_5 = param_5 - iVar7;
    puVar3 = (undefined4 *)(iVar7 + (int)puVar3);
  }
  memw();
  memw();
  DAT_403747cc[6] = DAT_403747cc[6] & DAT_403747e8 | (uint)(uVar2 != 0) << 0x1c;
  puVar1 = DAT_403747cc;
  if (uVar2 == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = uVar2 - 1 & 0x3ff;
  }
  memw();
  memw();
  DAT_403747cc[10] = uVar9 | DAT_403747cc[10] & 0xfffffc00;
  memw();
  memw();
  *puVar1 = *puVar1 | DAT_403747ec;
  puVar1 = DAT_403747cc;
  do {
    memw();
  } while (*DAT_403747cc != 0);
  memw();
  DAT_403747cc[2] = uStack_3c;
  memw();
  puVar1[6] = uStack_38;
  memw();
  puVar1[7] = uStack_34;
  memw();
  puVar1[8] = uStack_30;
  local_50 = 0;
  uVar9 = (uint)(param_7 >> 3);
  if ((param_7 >> 3 & 3) == 0) {
    (*DAT_403744d4)(&local_50,DAT_403747f0,uVar9);
  }
  else {
    uVar4 = uVar9;
    for (uVar8 = 0; uVar8 < uVar9 + 3 >> 2; uVar8 = uVar8 + 1) {
      iVar5 = (uVar4 < 4) * uVar4 + (uint)(uVar4 >= 4) * 4;
      memw();
      uStack_44 = DAT_403747cc[uVar8 + 0x16];
      (*DAT_403744d4)(puVar6,&uStack_44,iVar5);
      puVar6 = (uint *)((int)puVar6 + iVar5);
      uVar4 = uVar4 - iVar5;
    }
  }
  if (uVar2 < 0x20) {
    local_50 = -1 << 0x20 - (0x20 - (uVar2 & 0x1f)) & local_50 ^ local_50;
  }
  return local_50;
}