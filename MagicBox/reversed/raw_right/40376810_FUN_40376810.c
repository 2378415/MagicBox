// 40376810  FUN_40376810  FUN_40376810  size=52

void FUN_40376810(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_403744dc;
  if (*(int *)PTR_DAT_403746fc == param_1) {
    memw();
    *(uint *)PTR_DAT_40374700 = *(uint *)PTR_DAT_40374700 | *(uint *)(DAT_403744dc + 0x40);
    memw();
    memw();
    *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & *(uint *)PTR_DAT_40374704;
  }
  return;
}


