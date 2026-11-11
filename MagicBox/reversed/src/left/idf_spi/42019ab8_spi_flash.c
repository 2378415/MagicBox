// strings: P 8@ | spi_flash

int FUN_42019ab8(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_60 [2];
  undefined1 uStack_58;
  undefined1 uStack_50;
  int iStack_44;
  undefined1 uStack_3a;
  undefined4 uStack_34;
  undefined4 uStack_30;
  
  iVar5 = *DAT_420016f8;
  local_60[0] = 0;
  uStack_58 = 1;
  uStack_50 = 1;
  uStack_34 = 0x50;
  iVar2 = (*DAT_420017f0)();
  uStack_50 = iVar2 == 0;
  FUN_42019a7c(local_60);
  iVar2 = (*(code *)PTR_FUN_42001824)();
  if (iVar2 != 0) {
    uStack_3a = 1;
    (*(code *)PTR_FUN_42001828)(local_60);
  }
  uStack_30 = 0x50;
  if (iStack_44 == 0) {
    uStack_30 = 0xa0;
    memw();
    uVar6 = *(uint *)(DAT_4200180c + 0xec) & 3;
    if (((uVar6 != 2) && (uStack_30 = 0xf0, uVar6 != 3)) && (uStack_30 = 0x50, uVar6 != 0)) {
      uStack_30 = 0x78;
    }
  }
  iVar2 = (*(code *)PTR_FUN_4200182c)(PTR_DAT_42001810,local_60);
  puVar1 = PTR_PTR_42001808;
  if ((iVar2 == 0) && (iVar2 = (*(code *)PTR_FUN_42001830)(PTR_PTR_42001808), iVar2 == 0)) {
    uVar6 = *(uint *)(iVar5 + 4);
    if (*(uint *)(puVar1 + 0x14) < uVar6) {
      if (*(int *)PTR_DAT_42000028 != 0) {
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        (*DAT_42000060)(PTR_DAT_42001814,uVar3,PTR_s_spi_flash_42001800,
                        *(uint *)(puVar1 + 0x14) >> 10,*(uint *)(iVar5 + 4) >> 10);
      }
      iVar2 = 0x104;
    }
    else {
      if ((uVar6 < *(uint *)(puVar1 + 0x14)) && (1 < *(uint *)PTR_DAT_42000028)) {
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        (*DAT_42000060)(PTR_DAT_42001818,uVar3,PTR_s_spi_flash_42001800,
                        *(uint *)(puVar1 + 0x14) >> 10,*(uint *)(iVar5 + 4) >> 10);
        uVar6 = *(uint *)(iVar5 + 4);
      }
      if (DAT_42000240 < uVar6) {
        iVar4 = (*(code *)PTR_FUN_42001834)();
        if (iVar4 != 0) {
          if (*(int *)PTR_DAT_42000028 != 0) {
            uVar3 = (*(code *)PTR_FUN_4200005c)();
            (*DAT_42000060)(PTR_DAT_42001820,uVar3,PTR_s_spi_flash_42001800,
                            PTR_s_esp_flash_init_default_chip_4200181c,0x19f);
          }
          return iVar4;
        }
        uVar6 = *(uint *)(iVar5 + 4);
      }
      *(uint *)(puVar1 + 0x14) = uVar6;
      *DAT_42000cbc = puVar1;
    }
  }
  return iVar2;
}