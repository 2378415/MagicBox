// strings: task_wdt | add_entry

undefined4 FUN_42019ca0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  byte bVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  puVar3 = (undefined4 *)(*(code *)PTR_FUN_42000910)(1,0x10);
  puVar2 = PTR_DAT_42001864;
  if (puVar3 == (undefined4 *)0x0) {
    return 0x101;
  }
  if (param_1 == 0) {
    puVar3[2] = param_2;
    (*(code *)PTR_FUN_420004dc)(puVar2,0xffffffff);
    puVar8 = (undefined4 *)*DAT_42001868;
    if (puVar8 != (undefined4 *)0x0) {
      puVar9 = (undefined4 *)puVar8[1];
      if (puVar9 == (undefined4 *)0x0) goto LAB_42019e16;
      bVar7 = 0;
      bVar1 = false;
      puVar5 = puVar9;
      do {
        if (puVar3 == puVar5) {
          bVar1 = true;
        }
        else {
          bVar7 = bVar7 | *(byte *)(puVar5 + 3) ^ 1;
        }
        puVar5 = (undefined4 *)*puVar5;
      } while (puVar5 != (undefined4 *)0x0);
      if (bVar1) {
        if (*(int *)PTR_DAT_42000028 != 0) {
          uVar4 = (*(code *)PTR_FUN_4200005c)();
          (*DAT_42000060)(PTR_DAT_4200187c,uVar4,PTR_s_task_wdt_42001870,PTR_s_add_entry_4200186c,
                          0xc3);
        }
        goto LAB_42019db0;
      }
LAB_42019db6:
      piVar6 = DAT_42001868;
      *puVar3 = puVar9;
      puVar8[1] = puVar3;
      if (*(char *)((int)puVar8 + 0xd) != '\0') {
        FUN_4201a4ec(*puVar8);
        *(undefined1 *)(*piVar6 + 0xd) = 0;
      }
      if (bVar7 == 1) goto LAB_42019dce;
      goto LAB_42019dde;
    }
  }
  else {
    puVar3[1] = param_2;
    (*(code *)PTR_FUN_420004dc)();
    puVar8 = (undefined4 *)*DAT_42001868;
    if (puVar8 != (undefined4 *)0x0) {
      puVar9 = (undefined4 *)puVar8[1];
      if (puVar9 != (undefined4 *)0x0) {
        puVar10 = (undefined4 *)0x0;
        bVar7 = 0;
        puVar5 = puVar9;
        do {
          if (puVar3[1] == puVar5[1]) {
            puVar10 = puVar5;
          }
          else {
            bVar7 = bVar7 | *(byte *)(puVar5 + 3) ^ 1;
          }
          puVar5 = (undefined4 *)*puVar5;
        } while (puVar5 != (undefined4 *)0x0);
        if (puVar10 != (undefined4 *)0x0) {
          if (*(int *)PTR_DAT_42000028 != 0) {
            uVar4 = (*(code *)PTR_FUN_4200005c)();
            (*DAT_42000060)(PTR_DAT_42001878,uVar4,PTR_s_task_wdt_42001870,PTR_s_add_entry_4200186c,
                            0xc0);
          }
LAB_42019db0:
          uVar4 = 0x102;
          goto LAB_42019dfc;
        }
        goto LAB_42019db6;
      }
LAB_42019e16:
      piVar6 = DAT_42001868;
      *puVar3 = 0;
      puVar8[1] = puVar3;
      if (*(char *)((int)puVar8 + 0xd) != '\0') {
        FUN_4201a4ec(*puVar8);
        *(undefined1 *)(*piVar6 + 0xd) = 0;
      }
LAB_42019dde:
      FUN_4201a4a4(*(undefined4 *)*piVar6);
      for (piVar6 = *(int **)(*piVar6 + 4); piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
        *(undefined1 *)(piVar6 + 3) = 0;
      }
LAB_42019dce:
      (*(code *)PTR_FUN_420004e0)(puVar2);
      *param_3 = puVar3;
      return 0;
    }
  }
  if (*(int *)PTR_DAT_42000028 != 0) {
    uVar4 = (*(code *)PTR_FUN_4200005c)();
    (*DAT_42000060)(PTR_DAT_42001874,uVar4,PTR_s_task_wdt_42001870,PTR_s_add_entry_4200186c,0xbb);
  }
  uVar4 = 0x103;
LAB_42019dfc:
  (*(code *)PTR_FUN_420004e0)(puVar2);
  (*(code *)PTR_FUN_42000570)(puVar3);
  return uVar4;
}