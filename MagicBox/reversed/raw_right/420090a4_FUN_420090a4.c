// 420090a4  FUN_420090a4  FUN_420090a4  size=71

undefined4 FUN_420090a4(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  if (param_1 < 3) {
    if (*(int *)(param_1 * 4 + DAT_42000844) == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      puVar2 = PTR_DAT_42000848 + param_1 * 0x18 + 0xc;
      (*(code *)PTR_FUN_420003a8)(puVar2,0xffffffff);
      *param_2 = *(undefined4 *)(*(int *)(param_1 * 4 + DAT_42000844) + 0x14);
      (*(code *)PTR_FUN_420003ac)(puVar2);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


