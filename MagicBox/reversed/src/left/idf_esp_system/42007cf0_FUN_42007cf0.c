undefined8 FUN_42007cf0(void)

{
  undefined8 uVar1;
  
  uVar1 = (*(code *)PTR_FUN_420008e4)();
  return CONCAT44((int)((ulonglong)uVar1 >> 0x20) + DAT_420008e0[1] + *DAT_420008e0,
                  (int)uVar1 + *DAT_420008e0);
}