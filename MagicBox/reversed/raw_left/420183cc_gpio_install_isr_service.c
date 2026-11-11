// 420183cc  gpio_install_isr_service  FUN_420183cc  size=157
// strings: GPIO isr service already installed | gpio_install_isr_service | 8d7@H | hx7@

int FUN_420183cc(uint param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar2 = PTR_PTR_420015e0;
  if (*(int *)(PTR_PTR_420015e0 + 0x10) == 0) {
    uVar3 = DAT_420006dc;
    if ((param_1 >> 10 & 1) == 0) {
      uVar3 = DAT_42000988;
    }
    iVar4 = (*(code *)PTR_FUN_42000bd4)(0x31,8,uVar3);
    puVar1 = PTR_DAT_420015a8;
    if (iVar4 == 0) {
      return 0x101;
    }
    (*(code *)PTR_FUN_420004dc)(PTR_DAT_420015a8,0xffffffff);
    if (*(int *)(puVar2 + 0x10) == 0) {
      *(int *)(puVar2 + 0x10) = iVar4;
      (*(code *)PTR_FUN_420004e0)();
      iVar4 = FUN_42018314(PTR_LAB_4200163c,0,param_1,PTR_DAT_42001638);
      if (iVar4 == 0) {
        return 0;
      }
      FUN_420182c8();
      return iVar4;
    }
    (*(code *)PTR_FUN_420004e0)(puVar1);
    (*(code *)PTR_FUN_42000570)(iVar4);
  }
  else {
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar3,PTR_DAT_4200159c,
               PTR_s_gpio_install_isr_service_42001630,0x1f6,
               PTR_s_GPIO_isr_service_already_install_42001634);
  }
  return 0x103;
}


