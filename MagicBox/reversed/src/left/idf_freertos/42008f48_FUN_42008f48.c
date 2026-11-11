undefined4 FUN_42008f48(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined4 local_30 [12];
  
  puVar1 = PTR_DAT_42000a3c;
  iVar4 = (param_1 & 0xffff) * 0x18;
  local_30[0] = 0;
  puVar3 = PTR_DAT_42000a3c + iVar4 + 0xc;
  (*(code *)PTR_FUN_420004c8)();
  (*(code *)PTR_FUN_420004dc)(puVar3,0xffffffff);
  uVar2 = DAT_42000a44;
  if (*(int *)(*(int *)(param_1 * 4 + DAT_42000a40) + 0xc) == 1) {
    iVar5 = *(int *)(puVar1 + param_1 * 0x18 + 8);
    memw();
    memw();
    *(uint *)(iVar5 + 0x20) = *(uint *)(iVar5 + 0x20) & 0xffffffbf;
    memw();
    *(uint *)(iVar5 + 0x10) = uVar2;
    memw();
    memw();
    *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | uVar2;
  }
  FUN_4202cec4(puVar1 + iVar4 + 8,param_2,param_3,local_30);
  (*(code *)PTR_FUN_420004c8)();
  (*(code *)PTR_FUN_420004e0)(puVar3);
  return local_30[0];
}