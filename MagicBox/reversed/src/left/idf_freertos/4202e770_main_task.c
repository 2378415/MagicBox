// strings: main_task | esp_task_wdt_init(&twdt_config)

void FUN_4202e770(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined1 in_PRID;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  uVar3 = (*(code *)PTR_FUN_4200005c)();
  puVar1 = PTR_s_main_task_42001edc;
  uVar5 = rsr(in_PRID);
  (*(code *)PTR_FUN_42000118)
            (3,PTR_s_main_task_42001edc,PTR_DAT_42001ee0,uVar3,PTR_s_main_task_42001edc,
             uVar5 >> 0xd & 1);
  puVar2 = PTR_FUN_42001ee4;
  uVar5 = rsr(in_PRID);
  FUN_42004048(PTR_FUN_42001ee4,(uVar5 >> 0xd & 1) == 0);
  do {
    memw();
  } while (*DAT_42001ed8 == '\0');
  uVar5 = rsr(in_PRID);
  FUN_42004148(puVar2,(uVar5 >> 0xd & 1) == 0);
  FUN_420049cc();
  uStack_28 = 0;
  local_30 = DAT_42001ee8;
  uStack_2c = 3;
  iVar4 = FUN_42019fa8(&local_30);
  if (iVar4 != 0) {
    (*(code *)PTR_FUN_42000a1c)
              (iVar4,PTR_s__IDF_components_freertos_app_sta_42001ef4,199,PTR_s_main_task_42001ef0,
               PTR_s_esp_task_wdt_init__twdt_config__42001eec);
  }
  uVar3 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)(3,puVar1,PTR_DAT_42001ef8,uVar3,puVar1);
  FUN_4200daa4();
  uVar3 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)(3,puVar1,PTR_DAT_42001efc,uVar3,puVar1);
  (*(code *)PTR_FUN_42000d7c)(iVar4);
  return;
}