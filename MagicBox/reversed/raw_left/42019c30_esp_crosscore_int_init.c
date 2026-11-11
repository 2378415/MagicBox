// 42019c30  esp_crosscore_int_init  FUN_42019c30  size=108
// strings: /IDF/components/esp_system/crosscore_int.c | esp_crosscore_int_init

void FUN_42019c30(void)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined1 in_PRID;
  
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_42001848,0xffffffff);
  iVar2 = DAT_4200184c;
  puVar1 = PTR_DAT_42001848;
  uVar3 = rsr(in_PRID);
  memw();
  *(undefined4 *)((uVar3 >> 0xd & 1) * 4 + DAT_4200184c) = 0;
  (*(code *)PTR_FUN_420004e0)(puVar1);
  uVar3 = rsr(in_PRID);
  if ((uVar3 >> 0xd & 1) == 0) {
    iVar2 = FUN_42005720(0x4f,0x400,PTR_FUN_42001850,iVar2);
  }
  else {
    iVar2 = FUN_42005720(0x50,0x400,PTR_FUN_42001850,DAT_42001854,0);
  }
  if (iVar2 != 0) {
    (*(code *)PTR_FUN_42000a1c)
              (iVar2,PTR_s__IDF_components_esp_system_cross_42001860,0x68,
               PTR_s_esp_crosscore_int_init_4200185c,PTR_DAT_42001858);
  }
  return;
}


