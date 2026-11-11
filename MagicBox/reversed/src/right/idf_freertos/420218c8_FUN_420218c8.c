// strings: Balloc succeeded

int FUN_420218c8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_42021628(param_1,1);
  iVar2 = iVar1;
  if (iVar1 == 0) {
    iVar2 = (*(code *)PTR_FUN_42000044)
                      (PTR_s__builds_idf_crosstool_NG__build__4200130c,0x145,0,
                       PTR_s_Balloc_succeeded_42001314);
  }
  *(undefined4 *)(iVar2 + 0x14) = param_2;
  *(undefined4 *)(iVar2 + 0x10) = 1;
  return iVar1;
}