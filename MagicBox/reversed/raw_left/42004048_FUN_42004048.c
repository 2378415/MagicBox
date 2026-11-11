// 42004048  FUN_42004048  FUN_42004048  size=83

undefined4 FUN_42004048(undefined4 param_1,uint param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0x102;
  if (param_2 < 2) {
    (*(code *)PTR_FUN_420004dc)(PTR_DAT_420004d8,0xffffffff);
    puVar1 = PTR_DAT_420004d8;
    if (*(int *)(DAT_420004d0 + param_2 * 0x20) == 0) {
      *(undefined4 *)(param_2 * 0x20 + DAT_420004d0) = param_1;
      (*(code *)PTR_FUN_420004e0)(puVar1);
      uVar2 = 0;
    }
    else {
      (*(code *)PTR_FUN_420004e0)(PTR_DAT_420004d8);
      uVar2 = 0x101;
    }
  }
  return uVar2;
}


