// strings: app_init | project-name | 15:00:57 | May  4 2025

undefined4 FUN_42002014(void)

{
  int *piVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined1 auStack_40 [9];
  undefined1 uStack_37;
  
  piVar1 = DAT_42000024;
  if (*DAT_42000024 == 0) {
    FUN_42001fcc();
  }
  puVar2 = PTR_DAT_42000028;
  if (2 < *(uint *)PTR_DAT_42000028) {
    uVar4 = (*(code *)PTR_FUN_4200005c)();
    puVar3 = PTR_s_app_init_4200002c;
    (*DAT_42000060)(PTR_DAT_42000030,uVar4,PTR_s_app_init_4200002c);
    if (2 < *(uint *)puVar2) {
      uVar4 = (*(code *)PTR_FUN_4200005c)();
      (*DAT_42000060)(PTR_DAT_42000038,uVar4,puVar3,PTR_s_project_name_42000034);
      if (2 < *(uint *)puVar2) {
        uVar4 = (*(code *)PTR_FUN_4200005c)();
        (*DAT_42000060)(PTR_DAT_42000040,uVar4,puVar3,PTR_DAT_4200003c);
        if (2 < *(uint *)puVar2) {
          uVar4 = (*(code *)PTR_FUN_4200005c)();
          (*DAT_42000060)(PTR_DAT_4200004c,uVar4,puVar3,PTR_s_May_4_2025_42000048,
                          PTR_s_15_00_57_42000044);
        }
      }
    }
  }
  if (*piVar1 == 0) {
    FUN_42001fcc();
  }
  (*DAT_42000064)(auStack_40,piVar1,10);
  uStack_37 = 0;
  if (2 < *(uint *)puVar2) {
    uVar4 = (*(code *)PTR_FUN_4200005c)();
    puVar3 = PTR_s_app_init_4200002c;
    (*DAT_42000060)(PTR_DAT_42000050,uVar4,PTR_s_app_init_4200002c,auStack_40);
    if (2 < *(uint *)puVar2) {
      uVar4 = (*(code *)PTR_FUN_4200005c)();
      (*DAT_42000060)(PTR_DAT_42000058,uVar4,puVar3,PTR_s_v5_4_1_42000054);
    }
  }
  return 0;
}