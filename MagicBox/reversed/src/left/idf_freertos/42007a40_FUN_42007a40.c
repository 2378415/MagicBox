void FUN_42007a40(int param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_420008a0;
  if (*(int *)(param_1 + 4) != *(int *)(PTR_DAT_420008a0 + 4)) {
    FUN_4201fc4c(param_1);
  }
  if (*(int *)(param_1 + 8) != *(int *)(puVar1 + 8)) {
    FUN_4201fc4c(param_1);
  }
  if (*(int *)(param_1 + 0xc) != *(int *)(puVar1 + 0xc)) {
    FUN_4201fc4c(param_1);
  }
  return;
}