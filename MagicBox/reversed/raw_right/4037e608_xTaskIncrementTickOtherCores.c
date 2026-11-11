// 4037e608  xTaskIncrementTickOtherCores  FUN_4037e608  size=122
// strings: xCoreID != 0 | xTaskIncrementTickOtherCores

bool FUN_4037e608(void)

{
  bool bVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  uVar2 = rsr(in_PRID);
  uVar2 = uVar2 >> 0xd & 1;
  if (uVar2 == 0) {
    FUN_40381d9c(PTR_s_freertos_tasks_c_additions_h_3c03295c_0x28_40374f8c,0x5b,
                 PTR_s_xTaskIncrementTickOtherCores_40374f88,PTR_s_xCoreID____0_40374f84);
  }
  memw();
  if (*(int *)(uVar2 * 4 + DAT_40374e18) == 0) {
    FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
    memw();
    memw();
    bVar1 = 1 < *(uint *)(DAT_40374e34 + *(int *)(*(int *)(uVar2 * 4 + DAT_40374d64) + 0x2c) * 0x14)
    ;
    FUN_4037bd38(PTR_DAT_40374e54);
    memw();
    if (*(int *)(uVar2 * 4 + DAT_40374eac) != 0) {
      bVar1 = true;
    }
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


