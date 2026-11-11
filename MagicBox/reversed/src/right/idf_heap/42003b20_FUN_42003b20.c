int FUN_42003b20(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = FUN_42003ac4();
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)(*(code *)PTR_FUN_42000484)(0x14,DAT_420004fc);
    if (puVar3 == (undefined4 *)0x0) {
      iVar2 = 0x101;
    }
    else {
      puVar3[1] = param_1;
      puVar3[2] = param_2;
      *puVar3 = param_3;
      puVar3[3] = param_4;
      (*(code *)PTR_FUN_420003a8)(PTR_DAT_420004e4,0xffffffff);
      if ((param_4 & 1) == 0) {
        FUN_42003ab0(param_3);
      }
      else {
        FUN_42003aa0(param_3);
      }
      puVar1 = PTR_DAT_42000500;
      puVar3[4] = *(undefined4 *)PTR_DAT_42000500;
      *(undefined4 **)puVar1 = puVar3;
      (*(code *)PTR_FUN_420003ac)(PTR_DAT_420004e4);
    }
  }
  return iVar2;
}