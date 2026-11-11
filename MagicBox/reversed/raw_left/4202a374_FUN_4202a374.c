// 4202a374  FUN_4202a374  FUN_4202a374  size=40
// strings: Balloc succeeded

int FUN_4202a374(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_4202a0d4(param_1,1);
  iVar2 = iVar1;
  if (iVar1 == 0) {
    iVar2 = (*(code *)PTR_FUN_420000a8)
                      (PTR_s__builds_idf_crosstool_NG__build__42001db8,0x145,0,
                       PTR_s_Balloc_succeeded_42001dc0);
  }
  *(undefined4 *)(iVar2 + 0x14) = param_2;
  *(undefined4 *)(iVar2 + 0x10) = 1;
  return iVar1;
}


