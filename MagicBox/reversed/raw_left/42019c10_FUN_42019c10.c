// 42019c10  FUN_42019c10  FUN_42019c10  size=32

undefined4 FUN_42019c10(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_DAT_42001840;
  *(undefined4 *)PTR_DAT_42001840 = *(undefined4 *)PTR_DAT_4200183c;
  puVar2 = PTR_PTR_42001844;
  *(undefined4 *)(puVar1 + 4) = 0;
  *(undefined4 *)(puVar1 + 8) = 0;
  *(undefined4 *)(puVar1 + 0xc) = 0;
  *(undefined **)(param_1 + 8) = puVar2;
  *(undefined **)(param_1 + 0xc) = puVar1;
  return 0;
}


