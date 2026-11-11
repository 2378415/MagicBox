// strings: REENT malloc succeeded

void FUN_4202a15c(int param_1,int *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    puVar1 = (undefined4 *)(*(code *)PTR_FUN_4200056c)(0x10);
    *(undefined4 **)(param_1 + 0x24) = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)
               (*(code *)PTR_FUN_420000a8)
                         (PTR_s__builds_idf_crosstool_NG__build__42001db8,0x8f,0,
                          PTR_s_REENT_malloc_succeeded_42001db4);
    }
    puVar1[1] = 0;
    puVar1[2] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
  }
  if (param_2 != (int *)0x0) {
    piVar2 = (int *)(param_2[1] * 4 + *(int *)(*(int *)(param_1 + 0x24) + 0xc));
    *param_2 = *piVar2;
    *piVar2 = (int)param_2;
  }
  return;
}