void FUN_42002124(void)

{
  undefined4 *puVar1;
  
  for (puVar1 = (undefined4 *)PTR_PTR_420001f0; PTR_PTR_420001f4 <= puVar1; puVar1 = puVar1 + -1) {
    (*(code *)*puVar1)();
  }
  return;
}