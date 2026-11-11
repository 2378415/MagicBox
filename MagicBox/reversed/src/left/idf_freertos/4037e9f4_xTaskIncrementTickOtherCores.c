// strings: xCoreID != 0

uint FUN_4037e9f4(void)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint in_t0;
  undefined1 in_PRID;
  
  uVar3 = rsr(in_PRID);
  uVar3 = uVar3 >> 0xd & 1;
  if (uVar3 == 0) {
    uVar3 = in_t0;
    FUN_40381ce4(PTR_s_freertos_tasks_c_additions_h_3c034f28_0x28_40375058,0x5b,
                 PTR_s_xTaskIncrementTickOtherCores_40375054,PTR_s_xCoreID____0_40375050);
  }
  puVar1 = PTR_DAT_40374ef4;
  memw();
  uVar2 = 0;
  if (*(int *)(uVar3 * 4 + DAT_40374ed8) == 0) {
    FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
    memw();
    memw();
    uVar2 = *(uint *)(*(int *)(*(int *)(DAT_40374e18 + uVar3 * 4) + 0x2c) * 0x14 + DAT_40374efc);
    FUN_4037c094(puVar1);
    memw();
    uVar2 = *(int *)(DAT_40374f78 + uVar3 * 4) != 0 | uVar2;
  }
  return uVar2;
}