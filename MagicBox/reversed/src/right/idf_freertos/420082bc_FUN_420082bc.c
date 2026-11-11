undefined4 FUN_420082bc(uint param_1,uint param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  puVar1 = PTR_DAT_42000848;
  if (param_1 < 3) {
    if (param_2 < 4) {
      puVar3 = PTR_DAT_42000848 + param_1 * 0x18 + 0xc;
      (*(code *)PTR_FUN_420003a8)(puVar3,0xffffffff);
      FUN_42024aa8(puVar1 + param_1 * 0x18 + 8,param_2);
      (*(code *)PTR_FUN_420003ac)(puVar3);
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