undefined4 FUN_420062a0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_FUN_42000730)(0);
  uVar2 = 0;
  if ((iVar1 != 0) && (iVar1 = FUN_420245f4(iVar1,param_1), uVar2 = 0, iVar1 != 0)) {
    uVar2 = *(undefined4 *)(iVar1 + 4);
  }
  return uVar2;
}