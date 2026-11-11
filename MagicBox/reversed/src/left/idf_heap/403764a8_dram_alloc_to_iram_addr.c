// strings: esp_ptr_in_diram_dram((void *)dstart) || esp_ptr | heap_caps_base.c | dram_alloc_to_iram_addr | esp_ptr_in_diram_dram((void *)dend) || esp_ptr_i | (dstart & 3) == 0 | (dend & 3) == 0

undefined4 * FUN_403764a8(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  uint in_t0;
  ulonglong uVar9;
  uint local_30;
  uint uStack_2c;
  uint auStack_28 [10];
  
  local_30 = param_1;
  uStack_2c = param_2;
  auStack_28[0] = param_3;
  FUN_40377e80(&local_30,&uStack_2c,auStack_28);
  iVar3 = DAT_403746c4;
  uVar2 = DAT_403746b0;
  iVar1 = DAT_40374604;
  if (DAT_40374614 < uStack_2c - 1) {
    return (undefined4 *)0x0;
  }
  if ((auStack_28[0] & 1) == 0) {
    if ((auStack_28[0] & 2) == 0) goto LAB_403764ed;
  }
  else {
    if ((auStack_28[0] >> 2 & 3) != 0) {
      return (undefined4 *)0x0;
    }
    auStack_28[0] = auStack_28[0] | 2;
  }
  uStack_2c = uStack_2c + 3 & 0xfffffffc;
LAB_403764ed:
  iVar6 = 0;
  do {
    for (puVar7 = (uint *)*DAT_403746b4; puVar7 != (uint *)0x0; puVar7 = (uint *)puVar7[8]) {
      uVar8 = puVar7[7];
      if (((uVar8 != 0) && ((auStack_28[0] & puVar7[iVar6]) != 0)) &&
         ((~(puVar7[1] | *puVar7 | puVar7[2]) & auStack_28[0]) == 0)) {
        if (((auStack_28[0] & 1) == 0) ||
           ((uVar2 < puVar7[3] + iVar3 && (DAT_40374608 < puVar7[3] + iVar1)))) {
          if (local_30 < 5) {
            puVar5 = (undefined4 *)FUN_403809b8();
          }
          else {
            puVar5 = (undefined4 *)FUN_403808dc(uVar8,uStack_2c,local_30,0);
          }
          if (puVar5 != (undefined4 *)0x0) {
            return puVar5;
          }
        }
        else {
          if (local_30 < 5) {
            iVar4 = FUN_403809b8();
          }
          else {
            iVar4 = FUN_403808dc(uVar8,uStack_2c + 4,local_30,0);
          }
          if (iVar4 != 0) {
            uVar8 = uStack_2c + 4 + iVar4;
            uVar9 = CONCAT44(iVar4,iVar4);
            if ((uVar2 < (uint)(iVar4 + iVar3)) &&
               (uVar9 = CONCAT44(iVar4,iVar4), DAT_40374608 < (uint)(iVar4 + DAT_40374604))) {
              uVar8 = in_t0;
              uVar9 = FUN_40381ce4(PTR_s_heap_caps_base_c_3c033a7c_0x16_403746c0,0x29,
                                   PTR_s_dram_alloc_to_iram_addr_403746cc,
                                   PTR_s_esp_ptr_in_diram_dram__void___ds_403746c8);
              in_t0 = uVar8;
            }
            if ((uVar2 < uVar8 + DAT_403746d0) && (DAT_40374608 < uVar8 + DAT_403746d4)) {
              uVar8 = in_t0;
              uVar9 = FUN_40381ce4(PTR_s_heap_caps_base_c_3c033a7c_0x16_403746c0,0x2a,
                                   PTR_s_dram_alloc_to_iram_addr_403746cc,
                                   PTR_s_esp_ptr_in_diram_dram__void___de_403746d8);
              in_t0 = uVar8;
            }
            if ((uVar9 & 3) != 0) {
              uVar8 = in_t0;
              uVar9 = FUN_40381ce4(PTR_s_heap_caps_base_c_3c033a7c_0x16_403746c0,0x2b,
                                   PTR_s_dram_alloc_to_iram_addr_403746cc,
                                   PTR_s__dstart___3_____0_403746dc);
            }
            if ((uVar8 & 3) != 0) {
              uVar9 = FUN_40381ce4(PTR_s_heap_caps_base_c_3c033a7c_0x16_403746c0,0x2c,
                                   PTR_s_dram_alloc_to_iram_addr_403746cc,
                                   PTR_s__dend___3_____0_403746e0);
            }
            puVar5 = (undefined4 *)uVar9;
            if (DAT_40374608 < (uint)((int)puVar5 + DAT_40374604)) {
              puVar5 = (undefined4 *)((int)puVar5 + DAT_403746e4);
            }
            *puVar5 = (int)(uVar9 >> 0x20);
            return puVar5 + 1;
          }
        }
      }
    }
    iVar6 = iVar6 + 1;
    if (iVar6 == 3) {
      return (undefined4 *)0x0;
    }
  } while( true );
}