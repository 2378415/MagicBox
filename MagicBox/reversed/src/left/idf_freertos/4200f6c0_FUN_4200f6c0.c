void FUN_4200f6c0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  memw();
  memw();
  memw();
  if ((*DAT_42000dc0 != 0) && (*(int *)(*DAT_42000dc0 + 0x210) != 0)) {
    memw();
    memw();
    *DAT_42000e04 = 1;
    memw();
    if (*DAT_42000e08 != 0) {
      (*(code *)PTR_FUN_42000484)(*DAT_42000e08,0,0,2);
    }
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    if (*DAT_42000dfc < *DAT_42000e00) {
      uVar2 = *DAT_42000e0c;
      uVar1 = (*(code *)PTR_FUN_42000b70)();
      (*(code *)PTR_FUN_42000e40)(uVar2,1,uVar1,0);
    }
  }
  return;
}