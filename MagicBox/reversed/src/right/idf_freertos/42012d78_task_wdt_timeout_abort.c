// strings: ret == pdTRUE | @[7@

void FUN_42012d78(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_30 [4];
  undefined4 uStack_2c;
  
  (*DAT_42000240)(auStack_30,0,0xc);
  (*(code *)PTR_FUN_420001ec)(6);
  uVar1 = (*(code *)PTR_FUN_42000344)();
  iVar2 = (*(code *)PTR_FUN_420009d8)(uVar1,auStack_30);
  if (iVar2 != 1) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_task_wdt_c_3c034434_0x25_42000f88,0x17a,PTR_s_task_wdt_timeout_abort_42000f84,
               PTR_s_ret____pdTRUE_42000f80);
  }
  *DAT_420001ac = 1;
  *DAT_420009d4 = 1;
  (*(code *)PTR_FUN_42000f8c)(uStack_2c);
  return;
}