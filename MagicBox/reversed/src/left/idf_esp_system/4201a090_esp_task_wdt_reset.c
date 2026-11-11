// strings: esp_task_wdt_reset

undefined4 FUN_4201a090(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  byte bVar5;
  int *piVar6;
  undefined4 *puVar7;
  
  piVar4 = DAT_42001868;
  if (*DAT_42001868 == 0) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_task_wdt_42001870,PTR_DAT_420018a0,uVar1,PTR_s_task_wdt_42001870,
               PTR_s_esp_task_wdt_reset_420018d4,0x2b8);
    return 0x103;
  }
  iVar2 = (*(code *)PTR_FUN_42000474)();
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_42001864,0xffffffff);
  puVar7 = (undefined4 *)*piVar4;
  piVar3 = (int *)puVar7[1];
  if (piVar3 != (int *)0x0) {
    piVar6 = (int *)0x0;
    bVar5 = 0;
    do {
      if (iVar2 == piVar3[1]) {
        piVar6 = piVar3;
      }
      else {
        bVar5 = bVar5 | *(byte *)(piVar3 + 3) ^ 1;
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)0x0);
    if (piVar6 != (int *)0x0) {
      *(undefined1 *)(piVar6 + 3) = 1;
      if (bVar5 == 0) {
        FUN_4201a4a4(*puVar7);
        for (piVar4 = *(int **)(*piVar4 + 4); piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
          *(undefined1 *)(piVar4 + 3) = 0;
        }
      }
      uVar1 = 0;
      goto LAB_4201a14f;
    }
  }
  if (*(int *)PTR_DAT_42000028 != 0) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*DAT_42000060)(PTR_DAT_420018d8,uVar1,PTR_s_task_wdt_42001870,PTR_s_esp_task_wdt_reset_420018d4
                    ,0x2c1);
  }
  uVar1 = 0x105;
LAB_4201a14f:
  (*(code *)PTR_FUN_420004e0)(PTR_DAT_42001864);
  return uVar1;
}