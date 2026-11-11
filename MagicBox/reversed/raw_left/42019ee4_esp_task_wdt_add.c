// 42019ee4  esp_task_wdt_add  FUN_42019ee4  size=76
// strings: esp_task_wdt_add

undefined4 FUN_42019ee4(int param_1)

{
  undefined4 uVar1;
  undefined1 auStack_30 [48];
  
  if (*DAT_42001868 == 0) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_task_wdt_42001870,PTR_DAT_420018a0,uVar1,PTR_s_task_wdt_42001870,
               PTR_s_esp_task_wdt_add_4200189c,0x29d);
    uVar1 = 0x103;
  }
  else {
    if (param_1 == 0) {
      param_1 = (*(code *)PTR_FUN_42000474)();
    }
    uVar1 = FUN_42019ca0(1,param_1,auStack_30);
  }
  return uVar1;
}


