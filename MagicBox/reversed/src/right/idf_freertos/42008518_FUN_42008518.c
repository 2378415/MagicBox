int FUN_42008518(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 local_30;
  undefined4 local_2c [11];
  
  if (param_1 < 3) {
    puVar2 = PTR_DAT_42000848 + param_1 * 0x18 + 8;
    FUN_42024a10(puVar2,&local_30);
    iVar1 = FUN_42013a38(local_30,0,local_2c);
    if (iVar1 == 0) {
      puVar3 = PTR_DAT_42000848 + param_1 * 0x18 + 0xc;
      (*(code *)PTR_FUN_420003a8)(puVar3,0xffffffff);
      FUN_42024a3c(puVar2,param_2,local_2c[0]);
      (*(code *)PTR_FUN_420003ac)(puVar3);
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}