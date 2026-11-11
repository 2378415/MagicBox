void FUN_42007c74(uint *param_1)

{
  ulonglong uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  
  uVar3 = DAT_420008d4;
  (*(code *)PTR_FUN_420008d8)(DAT_420008d4);
  piVar2 = DAT_420008cc;
  if (*DAT_420008cc != 0 || DAT_420008cc[1] != 0) {
    FUN_42007b90();
    *piVar2 = 0;
    piVar2[1] = 0;
  }
  (*(code *)PTR_FUN_420008dc)(uVar3);
  uVar7 = *param_1;
  uVar6 = param_1[2];
  iVar4 = uVar7 * DAT_4200087c;
  iVar5 = param_1[1] * DAT_4200087c;
  uVar1 = (ulonglong)DAT_4200087c;
  uVar8 = FUN_42007cf0();
  FUN_42007d0c((iVar4 + uVar6) - (int)uVar8,
               iVar5 + (int)(uVar7 * uVar1 >> 0x20) + ((int)uVar6 >> 0x1f) + uVar6 +
               (int)((ulonglong)uVar8 >> 0x20) * -2);
  return;
}