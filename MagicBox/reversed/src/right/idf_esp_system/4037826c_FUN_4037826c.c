// strings: len_remain < length | ||7@0Z

/* WARNING: Instruction at (ram,0x4037838e) overlaps instruction at (ram,0x4037838c)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4037826c(undefined4 *param_1,undefined1 *param_2,uint param_3,uint param_4)

{
  int unaff_retaddr;
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *in_t0;
  int in_SAR;
  undefined1 auStack_50 [32];
  undefined4 *puStack_30;
  undefined1 *puStack_2c;
  uint uStack_28;
  uint uStack_24;
  
  puVar1 = auStack_50;
  puStack_30 = param_1;
  uStack_28 = param_3;
  iVar2 = (**(code **)(*(int *)PTR_PTR_4037487c + 8))(&puStack_30);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (*(int *)(puStack_30[1] + 0x44) == 0) {
    return DAT_4037488c;
  }
  if ((puStack_30 != (undefined4 *)0x0) && (*(code **)(puStack_30[2] + 8) != (code *)0x0)) {
    iVar2 = (**(code **)(puStack_30[2] + 8))(puStack_30[3],param_3,param_4);
    if (iVar2 == 0x10d) {
      return 0x10d;
    }
    if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_40381ce0();
    }
  }
  uVar6 = uStack_28;
  if (param_2 == (undefined1 *)0x0) {
    return 0x102;
  }
  if ((uint)puStack_30[5] < uStack_28) {
    return 0x102;
  }
  if ((uint)puStack_30[5] < uStack_28 + param_4) {
    return 0x102;
  }
  if (param_4 == 0) {
    return 0;
  }
  iVar2 = DAT_40374828 + -1;
  uVar3 = (**(code **)(*(int *)*puStack_30 + 0x24))((int *)*puStack_30,param_2);
  uStack_24 = -iVar2 & 0xffU | uVar3 & 0xff;
  uVar3 = param_4;
  do {
    if (uStack_24 == 0) {
      iVar2 = (uVar3 < 0x20) * uVar3 + (uint)(uVar3 >= 0x20) * 0x20;
      (*DAT_403744d4)(auStack_50,param_2,iVar2);
      puStack_2c = auStack_50;
    }
    else {
      iVar2 = (uVar3 < DAT_403748a8) * uVar3 + (uVar3 >= DAT_403748a8) * DAT_403748a8;
      puStack_2c = param_2;
    }
    if ((*(code **)(puStack_30[1] + 0x68) != (code *)0x0) &&
       (iVar4 = (**(code **)(puStack_30[1] + 0x68))(puStack_30,0), iVar4 != 0)) {
      return iVar4;
    }
    iVar4 = (*(code *)**(undefined4 **)PTR_PTR_4037487c)(puStack_30);
    if (iVar4 != 0) {
LAB_4037838e:
      in_t0 = (int *)PTR_PTR_4037487c;
      goto code_r0x40378391;
    }
    iVar4 = (**(code **)(puStack_30[1] + 0x44))(puStack_30,puStack_2c,uVar6,iVar2);
    uVar3 = uVar3 - iVar2;
    iVar5 = iVar4;
    if (param_4 <= uVar3) {
      iVar5 = FUN_40381d9c(PTR_s_esp_flash_api_c_3c034314_0x1b_403748a4,0x436,
                           PTR_s_esp_flash_write_403748b0,PTR_s_len_remain_<_length_403748ac);
    }
    if (iVar5 != 0) goto LAB_4037838e;
    if (uVar3 == 0) {
      iVar2 = (**(code **)(*(int *)(unaff_retaddr + 4) + 0xc))
                        (puStack_30,0,1,uStack_28,param_4,_DAT_4033a5c8);
      return iVar2;
    }
    iVar4 = (**(code **)(*(int *)PTR_PTR_4037487c + 4))(puStack_30,0);
    if (iVar4 != 0) {
      puVar1 = (undefined1 *)(CONCAT44(unaff_retaddr,unaff_retaddr) >> in_SAR);
code_r0x40378391:
      (**(code **)(*in_t0 + 0xc))(*(undefined4 *)(puVar1 + 0x20),iVar4);
      return iVar4;
    }
    uVar6 = uVar6 + iVar2;
    param_2 = param_2 + iVar2;
  } while( true );
}