// 40376690  esp_intr_disable  FUN_40376690  size=239
// strings: svd != NULL | esp_intr_disable

undefined4 FUN_40376690(int *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_a3;
  ushort *puVar4;
  uint *puVar5;
  uint uVar6;
  undefined *puVar7;
  uint *in_t0;
  undefined1 in_PRID;
  
  if (param_1 == (int *)0x0) {
    uVar3 = 0x102;
  }
  else {
    iVar2 = FUN_4037bbc4();
    if (iVar2 == 0) {
      FUN_4037bbe8(PTR_DAT_403746c8,0xffffffff);
    }
    else {
      FUN_4037bbe8(PTR_DAT_403746c8,0xffffffff);
    }
    puVar4 = (ushort *)param_1[1];
    if (puVar4 == (ushort *)0x0) {
      iVar2 = (int)(char)(*(uint *)*param_1 >> 0x16);
      bVar1 = true;
    }
    else {
      *puVar4 = *puVar4 | 1;
      puVar7 = (undefined *)(*(uint *)param_1[1] >> 1 & 0xff);
      iVar2 = (int)(char)(*(uint *)param_1[1] >> 1);
      puVar5 = *(uint **)(*param_1 + 4);
      if (puVar5 != (uint *)0x0) goto LAB_403766f8;
      puVar7 = PTR_s_esp_intr_disable_403746dc;
      puVar5 = in_t0;
      FUN_40381d9c(PTR_s_intr_alloc_c_3c031654_0x20_403746e0,0x37c,PTR_s_esp_intr_disable_403746dc,
                   PTR_s_svd____NULL_403746d8);
      iVar2 = extraout_a3;
      do {
        if (((char)puVar7 == (char)(*puVar5 >> 1)) && ((*puVar5 & 1) == 0)) {
          bVar1 = false;
          goto LAB_40376713;
        }
        puVar5 = (uint *)puVar5[5];
LAB_403766f8:
      } while (puVar5 != (uint *)0x0);
      bVar1 = true;
    }
LAB_40376713:
    if (iVar2 < 0) {
      uVar6 = rsr(in_PRID);
      if ((*(uint *)*param_1 >> 0x10 & 1) != (uVar6 >> 0xd & 1)) {
        iVar2 = FUN_4037bbc4();
        if (iVar2 == 0) {
          FUN_4037bd38(PTR_DAT_403746c8);
        }
        else {
          FUN_4037bd38(PTR_DAT_403746c8);
        }
        return 0x102;
      }
      FUN_40376680(*(uint *)*param_1 >> 0x11 & 0x1f);
    }
    else if (bVar1) {
      (*DAT_403746e4)(*(uint *)*param_1 >> 0x10 & 1,iVar2,6);
    }
    iVar2 = FUN_4037bbc4();
    if (iVar2 == 0) {
      FUN_4037bd38(PTR_DAT_403746c8);
      uVar3 = 0;
    }
    else {
      FUN_4037bd38(PTR_DAT_403746c8);
      uVar3 = 0;
    }
  }
  return uVar3;
}


