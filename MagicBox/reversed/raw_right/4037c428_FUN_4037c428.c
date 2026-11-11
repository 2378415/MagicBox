// 4037c428  FUN_4037c428  FUN_4037c428  size=52

/* WARNING: Control flow encountered bad instruction data */

bool FUN_4037c428(int param_1,uint param_2,uint param_3,int param_4)

{
  bool bVar1;
  
  memw();
  *(uint *)(param_1 + 4) = param_2;
  *(int *)(param_1 + 0x10) = param_1;
  if (param_3 < param_2) {
    cust0();
    cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  bVar1 = *(uint *)(param_1 + 0x18) <= param_3 - param_4;
  if (!bVar1) {
    FUN_4037c924(*DAT_40374dc4,param_1 + 4);
  }
  return bVar1;
}


