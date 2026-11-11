// 4037ccdc  prvDeleteTCB  FUN_4037ccdc  size=71
// strings: pxTCB->ucStaticallyAllocated == ( ( uint8_t ) 2 

void FUN_4037ccdc(int param_1)

{
  char cVar1;
  
  FUN_4037be20(param_1);
  (*(code *)PTR_FUN_40374e50)(param_1 + 0x5c);
  cVar1 = *(char *)(param_1 + 0x151);
  if (cVar1 == '\0') {
    FUN_4037c060(*(undefined4 *)(param_1 + 0x30));
    FUN_4037c060(param_1);
  }
  else if (cVar1 == '\x01') {
    FUN_4037c060(param_1);
  }
  else if (cVar1 != '\x02') {
    FUN_40381d9c(PTR_s_tasks_c_3c03257c_0x2a_40374e2c,DAT_40374e4c,PTR_s_prvDeleteTCB_40374e48,
                 PTR_s_pxTCB_>ucStaticallyAllocated______40374e44);
  }
  return;
}


