// 403779d0  bootloader_flash_execute_command_common  FUN_403779d0  size=627
// strings: mosi_len <= 32 | miso_len <= 32 | bootloader_flash.c | bootloader_flash_execute_command_common

uint FUN_403779d0(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4,uint param_5,
                 undefined4 param_6,byte param_7)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined *puVar9;
  uint in_t0;
  undefined8 uVar10;
  uint uStack_38;
  uint uStack_34;
  undefined4 auStack_30 [12];
  
  uVar10 = CONCAT44(param_3,param_2);
  puVar9 = (undefined *)(param_5 & 0xff);
  uVar6 = (uint)param_7;
  param_1 = param_1 & 0xff;
  param_4 = param_4 & 0xff;
  uVar8 = 0x20;
  auStack_30[0] = param_6;
  if ((undefined *)0x20 < puVar9) {
    puVar9 = PTR_s_bootloader_flash_execute_command_40374844;
    param_4 = in_t0;
    uVar10 = FUN_40381ce4(PTR_s_bootloader_flash_c_3c039d44_0x39_40374848,0x242,
                          PTR_s_bootloader_flash_execute_command_40374844,
                          PTR_s_mosi_len_<__32_40374840);
    uVar8 = param_4;
    in_t0 = param_4;
  }
  if (uVar8 < uVar6) {
    puVar9 = PTR_s_bootloader_flash_execute_command_40374844;
    param_4 = in_t0;
    uVar10 = FUN_40381ce4(PTR_s_bootloader_flash_c_3c039d44_0x39_40374848,0x243,
                          PTR_s_bootloader_flash_execute_command_40374844,
                          PTR_s_miso_len_<__32_4037484c);
  }
  puVar1 = DAT_40374850;
  iVar7 = (int)uVar10;
  memw();
  uVar3 = DAT_40374850[2];
  memw();
  uVar4 = DAT_40374850[6];
  memw();
  uVar2 = DAT_40374850[7];
  memw();
  uVar5 = DAT_40374850[8];
  memw();
  DAT_40374850[2] = 0;
  memw();
  memw();
  puVar1[2] = puVar1[2] | DAT_40374854;
  memw();
  memw();
  puVar1[6] = puVar1[6] | DAT_40374550;
  uVar8 = DAT_40374858;
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  puVar1[8] = puVar1[8] & 0xffff0000 | param_1;
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  puVar1[8] = puVar1[8] & 0xfffffff | uVar8;
  memw();
  memw();
  puVar1[0xf] = puVar1[0xf] & 0xfffffffd | (uint)(iVar7 == 0x20) * 2;
  memw();
  memw();
  puVar1[7] = puVar1[7] & 0x3ffffff | (iVar7 + -1) * 0x4000000;
  memw();
  memw();
  puVar1[6] = puVar1[6] & DAT_4037485c | (uint)(iVar7 != 0) << 0x1e;
  memw();
  puVar1[1] = (uint)((ulonglong)uVar10 >> 0x20);
  uVar8 = param_4;
  if (uVar6 != 0) {
    uVar8 = param_4 + *(byte *)(*DAT_40374860 + 0x19);
    param_4 = uVar8 & 0xff;
  }
  memw();
  memw();
  puVar1[6] = puVar1[6] & DAT_40374864 | (uint)(uVar8 != 0) << 0x1d;
  memw();
  memw();
  puVar1[7] = puVar1[7] & 0xffffffc0 | param_4 - 1 & 0x3f;
  memw();
  memw();
  puVar1[6] = puVar1[6] & DAT_40374868 | (uint)(puVar9 != (undefined *)0x0) << 0x1b;
  memw();
  if (puVar9 == (undefined *)0x0) {
    memw();
    puVar1[9] = puVar1[9] & 0xfffffc00;
  }
  else {
    memw();
    puVar1[9] = puVar1[9] & 0xfffffc00 | (uint)(puVar9 + -1) & 0x3ff;
    if (((uint)puVar9 >> 3) + 3 >> 2 == 1) {
      uStack_38 = 0;
      (*DAT_4037450c)(&uStack_38,auStack_30);
      memw();
      puVar1[0x16] = uStack_38;
    }
  }
  memw();
  memw();
  puVar1[6] = puVar1[6] & DAT_4037486c | (uint)(uVar6 != 0) << 0x1c;
  memw();
  uVar8 = uVar6 - 1 & 0x3ff;
  if (uVar6 == 0) {
    uVar8 = 0;
  }
  memw();
  puVar1[10] = puVar1[10] & 0xfffffc00 | uVar8;
  memw();
  memw();
  *puVar1 = *puVar1 | DAT_40374870;
  do {
    memw();
    uStack_34 = *puVar1;
  } while (uStack_34 != 0);
  memw();
  puVar1[2] = uVar3;
  memw();
  puVar1[6] = uVar4;
  memw();
  puVar1[7] = uVar2;
  memw();
  puVar1[8] = uVar5;
  if ((param_7 >> 3 & 3) == 0) {
    (*DAT_4037450c)(&uStack_34,DAT_40374874);
  }
  else {
    memw();
    uStack_38 = puVar1[0x16];
    (*DAT_4037450c)(&uStack_34,&uStack_38,param_7 >> 3);
  }
  if (uVar6 != 0x20) {
    uStack_34 = -1 << 0x20 - (0x20 - (uVar6 & 0x1f)) & uStack_34 ^ uStack_34;
  }
  return uStack_34;
}


