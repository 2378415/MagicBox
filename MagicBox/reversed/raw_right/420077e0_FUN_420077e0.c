// 420077e0  FUN_420077e0  FUN_420077e0  size=167

undefined4 FUN_420077e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 local_30 [12];
  
  local_30[0] = 0;
  puVar4 = PTR_DAT_42000848 + param_1 * 0x18 + 0xc;
  iVar3 = (*(code *)PTR_FUN_42000394)();
  if (iVar3 == 0) {
    (*(code *)PTR_FUN_420003a8)(puVar4,0xffffffff);
  }
  else {
    (*(code *)PTR_FUN_420003a8)(puVar4,0xffffffff);
  }
  puVar1 = PTR_DAT_42000848;
  if (*(int *)(*(int *)(param_1 * 4 + DAT_42000844) + 0xc) == 1) {
    memw();
    memw();
    *(uint *)(*(int *)(PTR_DAT_42000848 + param_1 * 0x18 + 8) + 0x20) =
         *(uint *)(*(int *)(PTR_DAT_42000848 + param_1 * 0x18 + 8) + 0x20) & 0xffffffbf;
    uVar2 = DAT_42000874;
    memw();
    *(uint *)(*(int *)(puVar1 + param_1 * 0x18 + 8) + 0x10) = DAT_42000874;
    iVar3 = *(int *)(puVar1 + param_1 * 0x18 + 8);
    memw();
    memw();
    *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) | uVar2;
  }
  FUN_420244e0(PTR_DAT_42000848 + param_1 * 0x18 + 8,param_2,param_3,local_30);
  iVar3 = (*(code *)PTR_FUN_42000394)();
  if (iVar3 == 0) {
    (*(code *)PTR_FUN_420003ac)(puVar4);
  }
  else {
    (*(code *)PTR_FUN_420003ac)(puVar4);
  }
  return local_30[0];
}


