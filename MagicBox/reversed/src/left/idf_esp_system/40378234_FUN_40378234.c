// strings: issi | spi_flash

int FUN_40378234(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  
  puVar2 = PTR_PTR_403748f8;
  puVar1 = PTR_DAT_40374414;
  uVar6 = *(undefined4 *)(param_1 + 0x18);
  piVar7 = *(int **)PTR_PTR_40374904;
  while( true ) {
    iVar4 = *piVar7;
    iVar5 = FUN_40378fd8(param_1);
    if (iVar4 == 0) break;
    if (iVar5 != 0) goto LAB_403782ae;
    uVar8 = *(uint *)puVar1;
    *(int *)(param_1 + 4) = iVar4;
    if (3 < uVar8) {
      uVar3 = FUN_40381bb0();
      (*DAT_40374438)(PTR_DAT_4037490c,uVar3,PTR_s_spi_flash_40374908,**(undefined4 **)(param_1 + 4)
                     );
    }
    iVar4 = (*(code *)**(undefined4 **)puVar2)(param_1);
    if (iVar4 != 0) {
      return iVar4;
    }
    piVar7 = piVar7 + 1;
    iVar4 = (**(code **)(*(int *)(param_1 + 4) + 8))(param_1,uVar6);
    iVar5 = *(int *)puVar2;
    if (iVar4 != 0) {
      *(undefined4 *)(param_1 + 4) = 0;
    }
    iVar4 = (**(code **)(iVar5 + 4))(param_1,0);
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  if (iVar5 == 0) {
    return 0x105;
  }
LAB_403782ae:
  if (2 < *(uint *)PTR_DAT_40374414) {
    uVar6 = FUN_40381bb0();
    (*DAT_40374438)(PTR_DAT_40374910,uVar6,PTR_s_spi_flash_40374908,**(undefined4 **)(param_1 + 4));
  }
  return 0;
}