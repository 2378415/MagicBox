// 42012b94  esp_crosscore_int_init  FUN_42012b94  size=112
// strings: /IDF/components/esp_system/crosscore_int.c | esp_crosscore_int_init

void FUN_42012b94(void)

{
  int iVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000f5c,0xffffffff);
  uVar2 = rsr(in_PRID);
  memw();
  *(undefined4 *)((uVar2 >> 0xd & 1) * 4 + DAT_42000f60) = 0;
  (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000f5c);
  uVar2 = rsr(in_PRID);
  if ((uVar2 >> 0xd & 1) == 0) {
    iVar1 = FUN_42003938(0x4f,0x400,PTR_FUN_42000f64,DAT_42000f60,0);
  }
  else {
    iVar1 = FUN_42003938(0x50,0x400,PTR_FUN_42000f64,DAT_42000f68,0);
  }
  if (iVar1 != 0) {
    (*(code *)PTR_FUN_42000840)
              (iVar1,PTR_s__IDF_components_esp_system_cross_42000f74,0x68,
               PTR_s_esp_crosscore_int_init_42000f70,PTR_DAT_42000f6c);
  }
  return;
}


