// 4201a554  flash_hal  FUN_4201a554  size=94
// strings: flash_hal

int FUN_4201a554(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  iVar2 = *(int *)(param_1 + 0x2c);
  uVar3 = CONCAT44(iVar2,*(int *)(param_1 + 0x30));
  if (*(int *)(param_1 + 0x30) < iVar2) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_flash_hal_42001930,PTR_DAT_42001934,uVar1,PTR_s_flash_hal_42001930,iVar2);
    uVar3 = (*(code *)PTR_FUN_42000330)();
  }
  iVar2 = (int)((ulonglong)uVar3 >> 0x20);
  uVar4 = (*DAT_4200193c)();
  if ((int)((ulonglong)uVar4 >> 0x20) != 0) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (2,PTR_s_flash_hal_42001930,PTR_DAT_42001938,uVar1,PTR_s_flash_hal_42001930,(int)uVar4
               ,uVar4);
  }
  return (iVar2 + (int)uVar3 + -1) / iVar2;
}


