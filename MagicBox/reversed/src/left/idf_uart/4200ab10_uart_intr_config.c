// strings: uart_intr_config | uart

undefined4 FUN_4200ab10(uint param_1,uint *param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  
  puVar7 = PTR_DAT_42000a3c;
  if (param_1 < 3) {
    if (param_2 != (uint *)0x0) {
      puVar2 = PTR_DAT_42000a3c + param_1 * 0x18 + 0xc;
      memw();
      *(undefined4 *)(*(int *)(PTR_DAT_42000a3c + param_1 * 0x18 + 8) + 0x10) = DAT_42000b5c;
      (*(code *)PTR_FUN_420004dc)(puVar2,0xffffffff);
      puVar3 = puVar7 + param_1 * 0x18 + 8;
      if ((*param_2 & 0x100) == 0) {
        FUN_4201aa04(puVar3,*param_2 & 0x100);
      }
      else {
        FUN_4201aa04(puVar3,(char)param_2[1]);
      }
      uVar5 = *param_2;
      if ((uVar5 & 1) != 0) {
        FUN_4202d758(puVar3,*(undefined1 *)((int)param_2 + 6));
        uVar5 = *param_2;
      }
      if ((uVar5 & 2) != 0) {
        FUN_4201a934(puVar3,*(undefined1 *)((int)param_2 + 5));
        uVar5 = *param_2;
      }
      iVar6 = *(int *)(puVar7 + param_1 * 0x18 + 8);
      memw();
      memw();
      *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) | uVar5;
      (*(code *)PTR_FUN_420004e0)(puVar2);
      return 0;
    }
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar4 = 0x3b6;
    puVar7 = PTR_DAT_42000b3c;
  }
  else {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar4 = 0x3b5;
    puVar7 = PTR_DAT_42000a58;
  }
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_42000a54,puVar7,uVar1,PTR_DAT_42000a54,PTR_s_uart_intr_config_42000b58,uVar4)
  ;
  return 0xffffffff;
}