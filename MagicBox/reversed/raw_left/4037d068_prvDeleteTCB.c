// 4037d068  prvDeleteTCB  FUN_4037d068  size=71
// strings: pxTCB->ucStaticallyAllocated == ( ( uint8_t ) 2 

void FUN_4037d068(int param_1)

{
  char cVar1;
  
  FUN_4037c17c(param_1);
  (*(code *)PTR_FUN_40374f28)(param_1 + 0x5c);
  cVar1 = *(char *)(param_1 + 0x151);
  if (cVar1 == '\0') {
    FUN_4037c43c(*(undefined4 *)(param_1 + 0x30));
    FUN_4037c43c(param_1);
  }
  else if (cVar1 == '\x01') {
    FUN_4037c43c(param_1);
  }
  else if (cVar1 != '\x02') {
    FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40374f24,PTR_s_prvDeleteTCB_40374f20,
                 PTR_s_pxTCB_>ucStaticallyAllocated______40374f1c);
  }
  return;
}


