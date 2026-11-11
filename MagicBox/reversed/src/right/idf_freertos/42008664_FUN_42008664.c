undefined4 FUN_42008664(uint param_1,undefined4 param_2,int param_3)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  puVar1 = PTR_DAT_42000848;
  if (param_1 < 3) {
    if (param_3 < 0x80) {
      puVar3 = PTR_DAT_42000848 + param_1 * 0x18 + 8;
      memw();
      *(undefined4 *)(*(int *)(PTR_DAT_42000848 + param_1 * 0x18 + 8) + 0x10) = 2;
      (*(code *)PTR_FUN_420003a8)(puVar1 + param_1 * 0x18 + 0xc,0xffffffff);
      FUN_420136d0(puVar3,param_3);
      memw();
      memw();
      *(uint *)(*(int *)(PTR_DAT_42000848 + param_1 * 0x18 + 8) + 0xc) =
           *(uint *)(*(int *)(PTR_DAT_42000848 + param_1 * 0x18 + 8) + 0xc) | 2;
      (*(code *)PTR_FUN_420003ac)(puVar1 + param_1 * 0x18 + 0xc);
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}