// 42007d0c  FUN_42007d0c  FUN_42007d0c  size=39

void FUN_42007d0c(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  (*(code *)PTR_FUN_420008d8)(DAT_420008e8);
  uVar1 = DAT_420008e8;
  memw();
  *DAT_420008ec = param_1;
  memw();
  *DAT_420008f0 = param_2;
  (*(code *)PTR_FUN_420008dc)(uVar1);
  return;
}


