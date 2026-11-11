// 4202e834  FUN_4202e834  FUN_4202e834  size=104
// strings: main | esp_startup_start_app | res == pdTRUE

void FUN_4202e834(void)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_420031d8();
  FUN_4200327c();
  FUN_42019c30();
  iVar1 = (*(code *)PTR_FUN_420004b0)(PTR_FUN_42001f04,PTR_DAT_42001f00,DAT_42000988,0,1,0,0);
  if (iVar1 != 1) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_app_startup_c_3c03497c_0x1a_42001f10,0x56,PTR_s_esp_startup_start_app_42001f0c,
               PTR_s_res____pdTRUE_42001f08);
  }
  if (DAT_42001f14 != (code *)0x0) {
    (*DAT_42001f14)();
  }
  if (3 < *(uint *)PTR_DAT_42000028) {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*DAT_42000060)(PTR_DAT_42001f1c,uVar2,PTR_s_app_start_42001f18);
  }
  (*(code *)PTR_FUN_42001f20)();
  return;
}


