// 42016f70  usb_del_phy  FUN_42016f70  size=195
// strings: usb_del_phy | (j7@

undefined4 FUN_42016f70(int *param_1)

{
  undefined *puVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar1 = PTR_DAT_42001534;
  if (param_1 == (int *)0x0) {
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_usb_phy_420014ec,PTR_DAT_42001504,uVar3,PTR_s_usb_phy_420014ec,
               PTR_s_usb_del_phy_42001530,0x1af);
    uVar3 = 0x102;
  }
  else {
    (*(code *)PTR_FUN_420004dc)(PTR_DAT_42001534,0xffffffff);
    piVar2 = DAT_42001538;
    iVar5 = *param_1;
    puVar4 = (undefined4 *)*DAT_42001538;
    puVar4[3] = puVar4[3] + -1;
    if (iVar5 == 2) {
      puVar4[2] = 0;
    }
    else if (iVar5 == 0) {
      memw();
      memw();
      *(uint *)param_1[6] = *(uint *)param_1[6] & DAT_42000a70;
      *puVar4 = 0;
    }
    else {
      puVar4[1] = 0;
    }
    (*(code *)PTR_FUN_420004e0)(puVar1);
    (*(code *)PTR_FUN_42000570)(param_1[5]);
    (*(code *)PTR_FUN_42000570)(param_1);
    (*(code *)PTR_FUN_420004dc)(puVar1,0xffffffff);
    iVar5 = *piVar2;
    if (*(int *)(iVar5 + 0xc) == 0) {
      *piVar2 = 0;
      (*(code *)PTR_FUN_42000aa8)();
      FUN_4201aac0();
      (*(code *)PTR_FUN_42000aac)();
    }
    else {
      iVar5 = 0;
    }
    (*(code *)PTR_FUN_420004e0)(puVar1);
    (*(code *)PTR_FUN_42000570)(iVar5);
    uVar3 = 0;
  }
  return uVar3;
}


