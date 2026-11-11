// 403783a8  slowrd  FUN_403783a8  size=343
// strings: spi_flash

int FUN_403783a8(int *param_1)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  uint local_30;
  int aiStack_2c [11];
  
  iVar4 = DAT_403748fc;
  if ((((param_1 == (int *)0x0) || (piVar9 = (int *)*param_1, piVar9 == (int *)0x0)) ||
      (*piVar9 == 0)) || (piVar9[1] == 0)) {
    return 0x102;
  }
  uVar7 = param_1[4];
  aiStack_2c[0] = 0;
  if (uVar7 < 0x10) {
    iVar8 = 0xb;
    while( true ) {
      iVar3 = (*(code *)PTR_FUN_40374930)(param_1,aiStack_2c);
      iVar8 = iVar8 + -1;
      if (iVar3 != iVar4) break;
      if (iVar8 == 0) {
        return iVar3;
      }
    }
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  else {
    aiStack_2c[0] = *(int *)*DAT_40374860;
  }
  param_1[6] = aiStack_2c[0];
  iVar4 = FUN_40378fd8(param_1);
  if ((iVar4 == 0) && (iVar4 = FUN_40378234(param_1), iVar4 != 0)) {
    return iVar4;
  }
  iVar4 = FUN_40378340(param_1,&local_30);
  puVar1 = PTR_DAT_40374414;
  if (iVar4 != 0) {
    if (*(int *)PTR_DAT_40374414 == 0) {
      return iVar4;
    }
    uVar5 = FUN_40381bb0();
    (*DAT_40374438)(PTR_DAT_40374918,uVar5,PTR_s_spi_flash_40374908);
    return iVar4;
  }
  if (*(code **)(param_1[1] + 0x74) == (code *)0x0) {
    if (*(uint *)PTR_DAT_40374414 < 2) goto LAB_403784c0;
    uVar5 = FUN_40381bb0();
    (*DAT_40374438)(PTR_DAT_4037491c,uVar5,PTR_s_spi_flash_40374908);
    uVar10 = *(uint *)puVar1;
  }
  else {
    uVar6 = (**(code **)(param_1[1] + 0x74))(param_1);
    uVar2 = DAT_40374920;
    puVar1 = PTR_DAT_40374414;
    uVar10 = *(uint *)PTR_DAT_40374414;
    if (((uVar6 & 2) == 0) && (DAT_40374920 < local_30)) {
      if (uVar10 < 2) {
        local_30 = DAT_40374920;
        goto LAB_403784c0;
      }
      uVar5 = FUN_40381bb0();
      (*DAT_40374438)(PTR_DAT_40374924,uVar5,PTR_s_spi_flash_40374908);
      uVar10 = *(uint *)puVar1;
      local_30 = uVar2;
    }
  }
  if (2 < uVar10) {
    uVar5 = FUN_40381bb0();
    (*DAT_40374438)(PTR_DAT_4037492c,uVar5,PTR_s_spi_flash_40374908,
                    PTR_s_slowrd_40374928 + param_1[4] * 10);
  }
LAB_403784c0:
  puVar1 = PTR_PTR_403748f8;
  iVar4 = (*(code *)**(undefined4 **)PTR_PTR_403748f8)(param_1);
  if (iVar4 == 0) {
    if ((0xf < uVar7) ||
       ((iVar4 = (**(code **)(param_1[1] + 0x58))(param_1), iVar4 == 0x108 && (1 < param_1[4] - 4U))
       )) {
      iVar4 = 0;
    }
    iVar4 = (**(code **)(*(int *)puVar1 + 4))(param_1,iVar4);
  }
  return iVar4;
}


