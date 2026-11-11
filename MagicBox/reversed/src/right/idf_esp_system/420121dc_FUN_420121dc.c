void FUN_420121dc(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)*DAT_42000e68;
  uVar1 = (*(code *)PTR_FUN_42000e6c)();
  *puVar2 = uVar1;
  return;
}