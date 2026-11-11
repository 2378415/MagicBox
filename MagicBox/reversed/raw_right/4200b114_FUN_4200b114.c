// 4200b114  FUN_4200b114  FUN_4200b114  size=199
// strings: checksum_size <= 32 | Calculated checksum | Image checksum

int FUN_4200b114(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_80;
  undefined1 auStack_7c [4];
  undefined1 auStack_78 [36];
  undefined1 auStack_54 [8];
  int iStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_44 [68];
  
  local_80 = 0;
  (*DAT_42000240)(auStack_7c,0,0x30);
  iStack_4c = 0;
  uVar2 = FUN_420246b8();
  uStack_48 = 0;
  (*DAT_42000240)(auStack_44,0,0x20);
  if (0x20 < uVar2) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_core_dump_flash_c_3c033284_0x21_42000a24,0x156,
               PTR_s_esp_core_dump_image_check_3c037ac7_1_42000a20,
               PTR_s_checksum_size_<__32_42000a1c);
  }
  iVar3 = FUN_4200b094(&local_80,&iStack_4c);
  if (iVar3 == 0) {
    uVar5 = iStack_4c - uVar2;
    FUN_420246c0(auStack_54);
    iVar3 = 0;
    for (; uVar5 != 0; uVar5 = uVar5 - iVar6) {
      iVar6 = (uVar5 < 0x20) * uVar5 + (uint)(uVar5 >= 0x20) * 0x20;
      iVar4 = FUN_420120b8(local_80,iVar3,auStack_78,iVar6);
      if (iVar4 != 0) {
        return iVar4;
      }
      FUN_4200b990(auStack_54,auStack_78,iVar6);
      iVar3 = iVar3 + iVar6;
    }
    FUN_4200b9ac(auStack_54,&uStack_48);
    iVar3 = FUN_420120b8(local_80,iStack_4c - uVar2,auStack_44,uVar2);
    uVar1 = uStack_48;
    if (iVar3 == 0) {
      iVar4 = (*DAT_420009a4)(uStack_48,auStack_44,uVar2);
      iVar3 = 0;
      if (iVar4 != 0) {
        FUN_4200b954(PTR_s_Calculated_checksum_42000a28,uVar1);
        FUN_4200b954(PTR_s_Image_checksum_42000a2c,auStack_44);
        iVar3 = 0x109;
      }
    }
  }
  return iVar3;
}


