// strings: REENT malloc succeeded

void FUN_4202a518(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  if ((param_3 & 3) != 0) {
    param_2 = FUN_4202a19c(param_1,param_2,
                           *(undefined4 *)(PTR_DAT_42001dc8 + ((param_3 & 3) - 1) * 4),0);
  }
  param_3 = (int)param_3 >> 2;
  if (param_3 == 0) {
    return;
  }
  puVar3 = *(undefined4 **)(param_1 + 0x24);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)(*(code *)PTR_FUN_4200056c)(0x10);
    *(undefined4 **)(param_1 + 0x24) = puVar3;
    puVar1 = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)
               (*(code *)PTR_FUN_420000a8)
                         (PTR_s__builds_idf_crosstool_NG__build__42001db8,0x1b3,0,
                          PTR_s_REENT_malloc_succeeded_42001db4);
    }
    puVar1[1] = 0;
    puVar1[2] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
  }
  puVar1 = (undefined4 *)puVar3[2];
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)FUN_4202a374(param_1,0x271);
    puVar3[2] = puVar1;
    *puVar1 = 0;
  }
  do {
    uVar4 = param_3 & 1;
    param_3 = (int)param_3 >> 1;
    uVar2 = param_2;
    if (uVar4 != 0) {
      uVar2 = FUN_4202a39c(param_1,param_2,puVar1);
      FUN_4202a15c(param_1,param_2);
      if (param_3 == 0) {
        return;
      }
    }
    puVar3 = (undefined4 *)*puVar1;
    if ((undefined4 *)*puVar1 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)FUN_4202a39c(param_1,puVar1,puVar1);
      *puVar1 = puVar3;
      *puVar3 = 0;
    }
    puVar1 = puVar3;
    param_2 = uVar2;
  } while( true );
}