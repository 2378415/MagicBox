void FUN_420182c8(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_420015a8,0xffffffff);
  puVar2 = PTR_PTR_420015e0;
  iVar4 = *(int *)(PTR_PTR_420015e0 + 0x10);
  if (iVar4 == 0) {
    (*(code *)PTR_FUN_420004e0)(PTR_DAT_420015a8);
  }
  else {
    uVar3 = *(undefined4 *)(PTR_PTR_420015e0 + 0x14);
    *(undefined4 *)(PTR_PTR_420015e0 + 0x10) = 0;
    *(undefined4 *)(puVar2 + 0x14) = 0;
    puVar1 = PTR_DAT_420015a8;
    *(undefined4 *)(puVar2 + 0xc) = 3;
    (*(code *)PTR_FUN_420004e0)(puVar1);
    FUN_42005814(uVar3);
    (*(code *)PTR_FUN_42000570)(iVar4);
  }
  return;
}