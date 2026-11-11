void FUN_420046c8(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = DAT_42000564;
  piVar1 = (int *)*DAT_42000564;
  while (piVar1 != (int *)0x0) {
    piVar3 = (int *)*piVar1;
    *piVar2 = (int)piVar3;
    (*(code *)PTR_FUN_42000570)(piVar1);
    piVar1 = piVar3;
  }
  return;
}