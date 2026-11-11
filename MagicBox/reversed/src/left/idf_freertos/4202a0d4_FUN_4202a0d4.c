// strings: REENT malloc succeeded

int * FUN_4202a0d4(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  
  puVar4 = *(undefined4 **)(param_1 + 0x24);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)(*(code *)PTR_FUN_4200056c)(0x10);
    *(undefined4 **)(param_1 + 0x24) = puVar4;
    puVar1 = puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)
               (*(code *)PTR_FUN_420000a8)
                         (PTR_s__builds_idf_crosstool_NG__build__42001db8,0x6b,0,
                          PTR_s_REENT_malloc_succeeded_42001db4);
    }
    puVar1[1] = 0;
    puVar1[2] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
  }
  iVar5 = puVar4[3];
  if (iVar5 == 0) {
    uVar2 = (*(code *)PTR_FUN_42001dbc)(param_1,4,0x21);
    iVar5 = *(int *)(param_1 + 0x24);
    puVar4[3] = uVar2;
    iVar5 = *(int *)(iVar5 + 0xc);
    if (iVar5 != 0) goto LAB_4202a124;
LAB_4202a11e:
    piVar3 = (int *)0x0;
  }
  else {
LAB_4202a124:
    piVar6 = (int *)(param_2 * 4 + iVar5);
    piVar3 = (int *)*piVar6;
    if (piVar3 == (int *)0x0) {
      iVar5 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
      piVar3 = (int *)(*(code *)PTR_FUN_42001dbc)(param_1,1,(iVar5 + 5) * 4);
      if (piVar3 == (int *)0x0) goto LAB_4202a11e;
      *(uint *)((int)piVar3 + 4) = param_2;
      *(int *)((int)piVar3 + 8) = iVar5;
    }
    else {
      *piVar6 = *piVar3;
    }
    *(undefined4 *)((int)piVar3 + 0x10) = 0;
    *(undefined4 *)((int)piVar3 + 0xc) = 0;
  }
  return piVar3;
}