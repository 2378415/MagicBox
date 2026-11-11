undefined4 FUN_40376f2c(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_4037d560();
  param_2[1] = uVar1;
  uVar1 = DAT_40374790;
  param_2[3] = 0;
  param_2[2] = 0;
  *param_2 = 0;
  FUN_40376ce8(uVar1);
  uVar2 = (*(code *)PTR_FUN_40374794)();
  FUN_40376d08(DAT_40374790);
  uVar3 = (*(code *)PTR_FUN_40374798)();
  uVar1 = (*DAT_40374500)((int)uVar3 + (int)uVar2,
                          (int)((ulonglong)uVar3 >> 0x20) + (int)((ulonglong)uVar2 >> 0x20) +
                          (int)uVar2,DAT_403746f8,0);
  return uVar1;
}