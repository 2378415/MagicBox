// strings: i == 0 || s_log_cache[(i - 1) / 2].generation <  | esp_log_cache_get_level

undefined4 FUN_420047a8(int param_1,uint *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined8 uVar5;
  
  piVar1 = DAT_42000574;
  iVar2 = *DAT_42000578;
  if (iVar2 != 0) {
    iVar3 = 0;
    piVar4 = DAT_42000574;
    while (param_1 != *piVar4) {
      uVar5 = CONCAT44(iVar3 + 1,iVar3);
      piVar4 = piVar4 + 2;
      if (iVar2 == iVar3 + 1) goto LAB_420047fc;
      while (iVar3 = (int)((ulonglong)uVar5 >> 0x20),
            (uint)piVar1[iVar3 * 2 + 1] >> 3 <= (uint)piVar1[((uint)uVar5 & 0xfffffffe) + 1] >> 3) {
        piVar4 = (int *)PTR_s_esp_log_cache_get_level_3c03ccf7_1_42000588;
        uVar5 = (*(code *)PTR_FUN_420000a8)
                          (PTR_s_log_binary_heap_c_3c032f7c_0x37_42000584,99,
                           PTR_s_esp_log_cache_get_level_3c03ccf7_1_42000588,
                           PTR_s_i____0____s_log_cache__i___1____2_4200057c);
      }
    }
    if (iVar2 != iVar3) {
      *param_2 = piVar1[iVar3 * 2 + 1] & 7;
      piVar4 = DAT_42000590;
      if (iVar2 == 0x1f) {
        iVar2 = *DAT_42000590 + 1;
        piVar1[iVar3 * 2 + 1] = piVar1[iVar3 * 2 + 1] & 7U | *DAT_42000590 << 3;
        *piVar4 = iVar2;
        FUN_420046e8();
        if (iVar2 == DAT_42000594) {
          iVar3 = 0;
          iVar2 = 0x1f;
          do {
            piVar1[iVar3 * 2 + 1] = piVar1[iVar3 * 2 + 1] & 7U | iVar3 << 3;
            iVar3 = iVar3 + 1;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
          *piVar4 = iVar3;
        }
      }
      return 1;
    }
  }
LAB_420047fc:
  *DAT_4200058c = *DAT_4200058c + 1;
  return 0;
}