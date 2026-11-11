// strings: Tasks currently running: | task_wdt | cpus_fail != 0 | task_wdt.c | task_wdt_isr

void FUN_4201a270(void)

{
  char cVar1;
  bool bVar2;
  undefined *puVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined *puVar9;
  uint uVar10;
  undefined1 in_PRID;
  uint local_30 [12];
  
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_42001864,0xffffffff);
  piVar4 = DAT_42001868;
  FUN_4201a4cc(*(undefined4 *)*DAT_42001868);
  cVar1 = *(char *)(*piVar4 + 0xc);
  local_30[0] = 0;
  iVar6 = FUN_4201a168(0,0,local_30);
  puVar3 = PTR_DAT_42000028;
  if (iVar6 == 0) {
    if (*(int *)PTR_DAT_42000028 == 0) goto LAB_4201a2fc;
    uVar7 = (*(code *)PTR_FUN_4200005c)();
    puVar9 = PTR_s_task_wdt_42001870;
    (*DAT_42000060)(PTR_DAT_420018ec,uVar7,PTR_s_task_wdt_42001870,
                    PTR_s_Tasks_currently_running__420018fc);
    iVar6 = 0;
    if (*(int *)puVar3 == 0) goto LAB_4201a2fc;
    do {
      uVar7 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000c90)(iVar6);
      uVar8 = (*(code *)PTR_FUN_420018f8)();
      (*DAT_42000060)(PTR_DAT_42001900,uVar7,puVar9,iVar6,uVar8);
      if (iVar6 == 1) break;
LAB_4201a2fc:
      iVar6 = 1;
      puVar9 = PTR_s_task_wdt_42001870;
    } while (*(int *)puVar3 != 0);
    (*(code *)PTR_FUN_420004e0)(PTR_DAT_42001864);
    if (DAT_42001904 != (code *)0x0) {
      (*DAT_42001904)();
    }
    uVar5 = local_30[0];
    if (local_30[0] == 0) {
      (*(code *)PTR_FUN_420000a8)
                (PTR_s_task_wdt_c_3c03aad8_0x25_4200188c,0x1fa,PTR_s_task_wdt_isr_4200190c,
                 PTR_s_cpus_fail____0_42001908);
    }
    uVar10 = rsr(in_PRID);
    uVar10 = uVar10 >> 0xd & 1;
    bVar2 = uVar10 == 0;
    if (cVar1 == '\0') {
      if ((uVar5 & 1 << (sbyte)uVar10) != 0) {
        if (*(int *)puVar3 != 0) {
          uVar7 = (*(code *)PTR_FUN_4200005c)();
          (*DAT_42000060)(PTR_DAT_42001890,uVar7,PTR_s_task_wdt_42001870,uVar10);
        }
        (*(code *)PTR_FUN_42001910)(100);
      }
      if ((uVar5 & 1 << bVar2) != 0) {
        if (*(int *)puVar3 != 0) {
          uVar7 = (*(code *)PTR_FUN_4200005c)();
          (*DAT_42000060)(PTR_DAT_42001894,uVar7,PTR_s_task_wdt_42001870,bVar2);
        }
        (*(code *)PTR_FUN_42001918)(bVar2);
      }
    }
    else {
      if ((~uVar5 & 3) == 0) {
        if (*(int *)puVar3 != 0) {
          uVar7 = (*(code *)PTR_FUN_4200005c)();
          (*DAT_42000060)(PTR_DAT_42001890,uVar7,PTR_s_task_wdt_42001870,uVar10);
        }
        (*(code *)PTR_FUN_42001910)(100);
        (*(code *)PTR_FUN_42001914)(bVar2);
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      if ((uVar5 & 1 << bVar2) != 0) {
        (*(code *)PTR_FUN_42001914)(bVar2);
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      FUN_42019e34(1);
    }
  }
  else {
    (*(code *)PTR_FUN_420004e0)(PTR_DAT_42001864);
  }
  return;
}