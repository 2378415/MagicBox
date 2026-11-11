void FUN_4200d9f0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int local_30 [12];
  
  local_30[0] = 0;
  iVar1 = (*(code *)PTR_FUN_42000394)();
  if (iVar1 == 0) {
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    uVar3 = (*(code *)PTR_FUN_420008f8)();
    (*(code *)PTR_FUN_42000b80)(uVar2,1,uVar3,0);
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    uVar3 = (*(code *)PTR_FUN_42000b88)();
    iVar1 = (*(code *)PTR_FUN_42000b80)(uVar2,6,uVar3,local_30,0);
    if ((iVar1 == 1) && (local_30[0] == 1)) {
      (*(code *)PTR_FUN_420008ac)();
    }
  }
  return;
}