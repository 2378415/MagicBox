// strings: 0 && 'LDO dbias need to modified' | rtc_clk.c | rtc_clk_cpu_freq_to_8m

void FUN_40379950(int *param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined4 local_30;
  
  iVar6 = *param_1;
  memw();
  if ((*DAT_40374a70 >> 10 & 3) == 1) {
    if (iVar6 == 0) {
      FUN_40379894(param_1[3],param_1[2]);
      if (*DAT_40374a18 == 0) {
        memw();
        memw();
        *DAT_403749d4 = *DAT_403749d4 | 0x540;
        *DAT_40374ab0 = 0;
        return;
      }
      return;
    }
    if (iVar6 == 1) goto LAB_40379b1f;
  }
  else {
    if (iVar6 == 0) {
      FUN_40379894(param_1[3],param_1[2]);
      return;
    }
    if (iVar6 == 1) {
      memw();
      memw();
      *DAT_403749d4 = *DAT_403749d4 & 0xfffffabf;
      iVar6 = FUN_40379564();
      puVar1 = DAT_40374ab4;
      iVar5 = param_1[1];
      if (iVar5 == 0x140) {
        memw();
        memw();
        *DAT_40374a74 = *DAT_40374a74 & 0xfffffffb;
        memw();
        memw();
        *puVar1 = *puVar1 & 0xfffffffb;
        memw();
        memw();
        *puVar1 = *puVar1 | 8;
        if (iVar6 == 0x20) {
          uVar3 = 6;
          uVar2 = 0x51;
        }
        else {
          uVar3 = 4;
          uVar2 = 0x50;
        }
        FUN_40376b18(0x66,1,4,0x69);
        local_30 = 0x73;
        bVar4 = false;
      }
      else {
        if (iVar5 != 0x1e0) {
                    /* WARNING: Subroutine does not return */
          FUN_40381c60();
        }
        memw();
        memw();
        *DAT_40374a74 = *DAT_40374a74 | 4;
        memw();
        memw();
        *puVar1 = *puVar1 & 0xfffffffb;
        memw();
        uVar3 = 8;
        memw();
        *puVar1 = *puVar1 | 8;
        bVar4 = iVar6 == 0x20;
        if (bVar4) {
          local_30 = 0x70;
          uVar3 = 0x1a;
          uVar2 = 0x41;
        }
        else {
          local_30 = 0x73;
          uVar2 = 0x50;
        }
        FUN_40376b18(0x66,1,4,0x6b);
      }
      FUN_40376b18(0x66,1,2,uVar2);
      FUN_40376b18(0x66,1,3,uVar3);
      FUN_40376b50(0x66,1,5,2,0,bVar4);
      FUN_40376b50(0x66,1,5,6,4,bVar4);
      FUN_40376b18(0x66,1,6,local_30);
      FUN_40376b50(0x66,1,9,1,0,3);
      do {
        memw();
      } while ((*puVar1 & 0x1000000) == 0);
      (*DAT_40374444)(10);
      memw();
      memw();
      *puVar1 = *puVar1 & 0xfffffff7;
      memw();
      memw();
      *puVar1 = *puVar1 | 4;
      *DAT_40374ab0 = iVar5;
LAB_40379b1f:
      FUN_403796b8(param_1[3]);
      return;
    }
  }
  if (iVar6 == 2) {
    FUN_40381ce4(PTR_s_rtc_clk_c_3fc95e88_0x2d_40374ac0,0x19e,
                 PTR_s_rtc_clk_cpu_freq_to_8m_3fc95c7b_1_40374abc,
                 PTR_s_0_____LDO_dbias_need_to_modified_40374ab8);
  }
  return;
}