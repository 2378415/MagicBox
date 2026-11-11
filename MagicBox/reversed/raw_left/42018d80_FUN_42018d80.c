// 42018d80  FUN_42018d80  FUN_42018d80  size=31

undefined4 FUN_42018d80(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_42018d30(param_1,param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x10);
    (*(code *)PTR_FUN_42000570)();
  }
  return uVar2;
}


