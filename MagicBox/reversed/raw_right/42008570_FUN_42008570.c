// 42008570  FUN_42008570  FUN_42008570  size=86

undefined4 FUN_42008570(uint param_1,uint param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  
  puVar1 = PTR_DAT_42000848;
  if (param_1 < 3) {
    puVar3 = PTR_DAT_42000848 + param_1 * 0x18 + 0xc;
    (*(code *)PTR_FUN_420003a8)(puVar3,0xffffffff);
    iVar4 = *(int *)(param_1 * 4 + DAT_42000844);
    *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & (param_2 ^ 0xffffffff);
    memw();
    memw();
    *(uint *)(*(int *)(puVar1 + param_1 * 0x18 + 8) + 0xc) =
         *(uint *)(*(int *)(puVar1 + param_1 * 0x18 + 8) + 0xc) & (param_2 ^ 0xffffffff);
    (*(code *)PTR_FUN_420003ac)(puVar3);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


