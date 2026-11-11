undefined4 FUN_42007664(int param_1)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = PTR_DAT_42000848 + param_1 * 0x18 + 0xc;
  (*(code *)PTR_FUN_420003a8)(puVar2,0xffffffff);
  iVar3 = *(int *)(param_1 * 4 + DAT_42000844);
  iVar1 = *(int *)(iVar3 + 0x38);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar3 + 0x38) = 0;
    *(undefined4 *)(iVar3 + 0x2c) = 0;
    *(undefined4 *)(iVar3 + 0x30) = 0;
  }
  (*(code *)PTR_FUN_420003ac)(puVar2);
  (*(code *)PTR_FUN_420004c0)(iVar1);
  return 0;
}