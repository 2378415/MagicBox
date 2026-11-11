// 42019fa8  esp_task_wdt_init  FUN_42019fa8  size=227
// strings: esp_task_wdt_init

int FUN_42019fa8(int param_1)

{
  int *piVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  piVar1 = DAT_42001868;
  if ((param_1 == 0) || (3 < *(uint *)(param_1 + 4))) {
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_task_wdt_42001870,PTR_DAT_420018c4,uVar3,PTR_s_task_wdt_42001870,
               PTR_s_esp_task_wdt_init_420018c0,0x202);
    iVar4 = 0x102;
  }
  else if (*DAT_42001868 == 0) {
    puVar5 = (undefined4 *)(*(code *)PTR_FUN_42000910)(1,0x10);
    puVar2 = PTR_FUN_420018d0;
    if (puVar5 == (undefined4 *)0x0) {
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (1,PTR_s_task_wdt_42001870,PTR_DAT_420018cc,uVar3,PTR_s_task_wdt_42001870,
                 PTR_s_esp_task_wdt_init_420018c0,0x209);
      iVar4 = 0x101;
    }
    else {
      *(undefined1 *)(puVar5 + 3) = *(undefined1 *)(param_1 + 8);
      iVar4 = FUN_4201a3dc(param_1,puVar2,puVar5);
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 4);
        *piVar1 = (int)puVar5;
        puVar5[2] = iVar4;
        if (iVar4 != 0) {
          FUN_42019f30();
          puVar5 = (undefined4 *)*piVar1;
        }
        if (puVar5[1] == 0) {
          *(undefined1 *)((int)puVar5 + 0xd) = 1;
          return 0;
        }
        *(undefined1 *)((int)puVar5 + 0xd) = 0;
        FUN_4201a4ec(*puVar5);
        return 0;
      }
    }
    (*(code *)PTR_FUN_42000570)(puVar5);
  }
  else {
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_task_wdt_42001870,PTR_DAT_420018c8,uVar3,PTR_s_task_wdt_42001870,
               PTR_s_esp_task_wdt_init_420018c0,0x203);
    iVar4 = 0x103;
  }
  return iVar4;
}


