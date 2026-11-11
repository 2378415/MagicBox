// 420261fc  esp_startup_start_app  FUN_420261fc  size=76
// strings: main | esp_startup_start_app | res == pdTRUE

void FUN_420261fc(void)

{
  int iVar1;
  
  FUN_42001c44();
  FUN_42001cf8();
  FUN_42012b94();
  iVar1 = (*(code *)PTR_FUN_42000380)(PTR_FUN_42001460,PTR_DAT_4200145c,DAT_4200077c,0,1,0,0);
  if (iVar1 != 1) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_app_startup_c_3c0321e4_0x1a_4200146c,0x56,PTR_s_esp_startup_start_app_42001468,
               PTR_s_res____pdTRUE_42001464);
  }
  if (DAT_42001470 != (code *)0x0) {
    (*DAT_42001470)();
  }
  (*(code *)PTR_FUN_42001474)();
  return;
}


