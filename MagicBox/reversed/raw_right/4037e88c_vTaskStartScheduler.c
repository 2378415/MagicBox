// 4037e88c  vTaskStartScheduler  FUN_4037e88c  size=97
// strings: xReturn != ( -1 ) | tasks.c | vTaskStartScheduler

void FUN_4037e88c(void)

{
  int iVar1;
  
  iVar1 = FUN_4037e7fc();
  if ((iVar1 == 1) && (iVar1 = FUN_4037c77c(), iVar1 == 1)) {
    rsil(3);
    FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
    memw();
    *DAT_40374e20 = 0xffffffff;
    memw();
    *DAT_40374e8c = 1;
    memw();
    *DAT_40374e68 = 0;
    FUN_4037bd38(PTR_DAT_40374e54);
    FUN_4037bb00();
  }
  else if (iVar1 == -1) {
    FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374fbc,
                 PTR_s_vTaskStartScheduler_40374fb8,PTR_s_xReturn_______1___40374fb4);
  }
  memw();
  return;
}


