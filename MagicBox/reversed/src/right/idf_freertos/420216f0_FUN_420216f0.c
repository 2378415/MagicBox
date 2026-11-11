// strings: Balloc succeeded

void FUN_420216f0(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = *(int *)(param_2 + 0x10);
  uVar4 = *(uint *)(param_2 + 0x14);
  uVar6 = (uVar4 & 0xffff) * param_3 + param_4;
  uVar5 = (uVar4 >> 0x10) * param_3 + (uVar6 >> 0x10);
  uVar4 = uVar5 >> 0x10;
  *(uint *)(param_2 + 0x14) = uVar5 * 0x10000 + (uVar6 & 0xffff);
  if (uVar4 != 0) {
    iVar1 = param_2;
    if (*(int *)(param_2 + 8) <= iVar3) {
      iVar1 = FUN_42021628(param_1,*(int *)(param_2 + 4) + 1);
      iVar2 = iVar1;
      if (iVar1 == 0) {
        iVar2 = (*(code *)PTR_FUN_42000044)
                          (PTR_s__builds_idf_crosstool_NG__build__4200130c,0xba,0,
                           PTR_s_Balloc_succeeded_42001314);
      }
      (*DAT_420002fc)(iVar2 + 0xc,param_2 + 0xc,(*(int *)(param_2 + 0x10) + 2) * 4);
      FUN_420216b0(param_1,param_2);
    }
    *(uint *)(iVar3 * 4 + iVar1 + 0x14) = uVar4;
    *(int *)(iVar1 + 0x10) = iVar3 + 1;
  }
  return;
}