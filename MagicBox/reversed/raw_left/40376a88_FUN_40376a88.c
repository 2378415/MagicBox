// 40376a88  FUN_40376a88  FUN_40376a88  size=52

void FUN_40376a88(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = DAT_40374518;
  if (*(int *)PTR_DAT_40374738 == param_1) {
    memw();
    memw();
    uVar2 = *(uint *)(DAT_40374518 + 0x40);
    uVar3 = *(uint *)PTR_DAT_40374740;
    *(uint *)PTR_DAT_4037473c = *(uint *)PTR_DAT_4037473c | *(uint *)(DAT_40374518 + 0x40);
    memw();
    *(uint *)(iVar1 + 0x40) = uVar2 & uVar3;
  }
  return;
}


