// 42008110  esp_timer_systimer  FUN_42008110  size=163
// strings: esp_timer_systimer

int FUN_42008110(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_42000950;
  if (*DAT_42000950 == 0) {
    iVar3 = FUN_42005720(0x3b,DAT_42000960,PTR_FUN_4200095c,0,DAT_42000950);
    uVar2 = DAT_42000934;
    if (iVar3 == 0) {
      if (*DAT_42000968 == 0) {
        *DAT_42000968 = param_1;
        (*(code *)PTR_FUN_42000970)(uVar2,2);
      }
      iVar3 = (*(code *)PTR_FUN_42000974)(*piVar1);
      if ((iVar3 != 0) && (*(int *)PTR_DAT_42000028 != 0)) {
        uVar2 = (*(code *)PTR_FUN_4200005c)();
        (*DAT_42000060)(PTR_DAT_4200096c,uVar2,PTR_s_esp_timer_systimer_42000954,iVar3);
      }
    }
    else if (*(int *)PTR_DAT_42000028 != 0) {
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*DAT_42000060)(PTR_DAT_42000964,uVar2,PTR_s_esp_timer_systimer_42000954,iVar3);
    }
  }
  else {
    if (*(int *)PTR_DAT_42000028 != 0) {
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*DAT_42000060)(PTR_DAT_42000958,uVar2,PTR_s_esp_timer_systimer_42000954);
    }
    iVar3 = 0x103;
  }
  return iVar3;
}


