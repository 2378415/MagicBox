// strings: esp_timer

int FUN_4201af0c(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_42001a0c;
  if (*DAT_42001a0c == 0) {
    iVar3 = (*(code *)PTR_FUN_420004b0)
                      (PTR_FUN_42001a18,PTR_s_esp_timer_42001a10,DAT_42000988,0,0x16,DAT_42001a0c,0)
    ;
    if (iVar3 == 1) {
      iVar3 = FUN_42008110(PTR_FUN_42001a20);
      if (iVar3 != 0) {
        if (*(int *)PTR_DAT_42000028 != 0) {
          uVar2 = (*(code *)PTR_FUN_4200005c)();
          (*DAT_42000060)(PTR_DAT_42001a24,uVar2,PTR_s_esp_timer_42001a10);
        }
        if (*piVar1 != 0) {
          (*(code *)PTR_FUN_42000d7c)();
          *piVar1 = 0;
        }
      }
    }
    else {
      if (*(int *)PTR_DAT_42000028 != 0) {
        uVar2 = (*(code *)PTR_FUN_4200005c)();
        (*DAT_42000060)(PTR_DAT_42001a1c,uVar2,PTR_s_esp_timer_42001a10);
      }
      iVar3 = 0x101;
    }
  }
  else {
    if (*(int *)PTR_DAT_42000028 != 0) {
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*DAT_42000060)(PTR_DAT_42001a14,uVar2,PTR_s_esp_timer_42001a10);
    }
    iVar3 = 0x103;
  }
  return iVar3;
}