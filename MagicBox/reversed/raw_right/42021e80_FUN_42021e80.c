// 42021e80  FUN_42021e80  FUN_42021e80  size=181
// strings: Balloc succeeded

void FUN_42021e80(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,int *param_5,
                 int *param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint local_30;
  uint auStack_2c [11];
  
  iVar1 = FUN_42021628(param_1,1);
  if (iVar1 == 0) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s__builds_idf_crosstool_NG__build__4200130c,0x30f,0,
               PTR_s_Balloc_succeeded_42001314);
  }
  uVar3 = param_4 >> 0x14 & 0x7ff;
  local_30 = param_4 & 0xfffff;
  if (uVar3 != 0) {
    local_30 = local_30 | 0x100000;
  }
  if (param_3 == 0) {
    iVar4 = FUN_4202185c(&local_30);
    uVar2 = iVar4 + 0x20;
    *(uint *)(iVar1 + 0x14) = local_30;
    iVar4 = 1;
  }
  else {
    auStack_2c[0] = param_3;
    uVar2 = FUN_4202185c(auStack_2c);
    if (uVar2 == 0) {
      *(uint *)(iVar1 + 0x14) = auStack_2c[0];
    }
    else {
      uVar5 = local_30 << 0x20 - (0x20 - (-(uVar2 - 0x20) & 0x1f));
      local_30 = local_30 >> (uVar2 & 0x1f);
      *(uint *)(iVar1 + 0x14) = uVar5 | auStack_2c[0];
    }
    iVar4 = 1;
    *(uint *)(iVar1 + 0x18) = local_30;
    if (local_30 != 0) {
      iVar4 = 2;
    }
  }
  *(int *)(iVar1 + 0x10) = iVar4;
  if (uVar3 == 0) {
    *param_5 = uVar2 - 0x432;
    iVar1 = FUN_4202180c(*(undefined4 *)(iVar1 + iVar4 * 4 + 0x10));
    iVar1 = iVar4 * 0x20 - iVar1;
  }
  else {
    *param_5 = (uVar3 - 0x433) + uVar2;
    iVar1 = -(uVar2 - 0x35);
  }
  *param_6 = iVar1;
  return;
}


