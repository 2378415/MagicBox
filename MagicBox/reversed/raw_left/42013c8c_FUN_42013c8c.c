// 42013c8c  FUN_42013c8c  FUN_42013c8c  size=62

void FUN_42013c8c(void)

{
  int iVar1;
  int local_30;
  char acStack_2c [44];
  
  acStack_2c[1] = 0;
  iVar1 = FUN_42013b20(0xa3,acStack_2c + 1,1,acStack_2c,&local_30);
  if (((iVar1 == 0) && (local_30 == 1)) && (acStack_2c[0] == '\0')) {
    memw();
    *DAT_42000ec4 = 1;
  }
  else {
    memw();
    *DAT_42000ec4 = 0;
  }
  return;
}


