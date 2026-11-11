// strings: cpus_fail != 0 | task_wdt.c | task_wdt_isr

void FUN_42013044(void)

{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_30 [12];
  
  (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000f7c,0xffffffff);
  piVar2 = DAT_42000f78;
  FUN_420131c8(*(undefined4 *)*DAT_42000f78);
  local_30[0] = 0;
  uVar1 = *(undefined1 *)(*piVar2 + 0xc);
  iVar3 = FUN_42012fb8(0,0,local_30);
  iVar4 = 0;
  if (iVar3 == 0) {
    for (; iVar4 < 2; iVar4 = iVar4 + 1) {
    }
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000f7c);
    if (DAT_42000fd4 != (code *)0x0) {
      (*DAT_42000fd4)();
    }
    iVar4 = local_30[0];
    if (local_30[0] == 0) {
      iVar4 = (*(code *)PTR_FUN_42000044)
                        (PTR_s_task_wdt_c_3c034434_0x25_42000f88,0x1fa,PTR_s_task_wdt_isr_42000fdc,
                         PTR_s_cpus_fail____0_42000fd8);
    }
    FUN_42012dcc(iVar4,uVar1);
  }
  else {
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000f7c);
  }
  return;
}