// 42026180  FUN_42026180  FUN_42026180  size=122
// strings: esp_task_wdt_init(&twdt_config)

void FUN_42026180(void)

{
  int iVar1;
  uint uVar2;
  undefined1 in_PRID;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  uVar2 = rsr(in_PRID);
  FUN_42002a44(PTR_FUN_42001448,(uVar2 >> 0xd & 1) == 0);
  do {
    memw();
  } while (*DAT_42001444 == '\0');
  uVar2 = rsr(in_PRID);
  FUN_42002b10(PTR_FUN_42001448,(uVar2 >> 0xd & 1) == 0);
  FUN_42002d68();
  (*DAT_42000240)(&local_30,0,0xc);
  local_30 = DAT_4200144c;
  uStack_2c = 3;
  iVar1 = FUN_42012ec4(&local_30);
  if (iVar1 != 0) {
    (*(code *)PTR_FUN_42000840)
              (iVar1,PTR_s__IDF_components_freertos_app_sta_42001458,199,PTR_s_main_task_42001454,
               PTR_s_esp_task_wdt_init__twdt_config__42001450);
  }
  FUN_4200f1d4();
  (*(code *)PTR_FUN_42000cc4)(0);
  return;
}


