// strings: SERIAL_SETUP | ,q7@|e

void serial_setup(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1 + DAT_420012c8 <= DAT_420012cc) {
    FUN_4200abe0(0,100);
    FUN_4200af94(0);
    iVar1 = FUN_42009d74(0,param_1);
    if (iVar1 == 0) {
      *(uint *)PTR_DAT_420011f8 = param_1;
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (3,PTR_s_SERIAL_SETUP_420012d0,PTR_DAT_420012d4,uVar2,PTR_s_SERIAL_SETUP_420012d0,
                 param_1);
      uVar3 = 1;
      if (DAT_420012d8 < param_1) {
        uVar3 = (uint)((ulonglong)param_1 * (ulonglong)DAT_420012dc >> 0x32);
      }
      (*(code *)PTR_FUN_42000dcc)(uVar3,200);
    }
  }
  return;
}