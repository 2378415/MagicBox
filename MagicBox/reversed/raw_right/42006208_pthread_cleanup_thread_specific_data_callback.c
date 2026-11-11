// 42006208  pthread_cleanup_thread_specific_data_callback  FUN_42006208  size=69
// strings: tls != NULL | pthread_cleanup_thread_specific_data_callback

void FUN_42006208(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_2 == (int *)0x0) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_pthread_local_storage_c_3c032f60_0x19_4200072c,0x80,
               PTR_s_pthread_cleanup_thread_specific__42000728,PTR_s_tls____NULL_42000724);
  }
  while (puVar2 = (undefined4 *)*param_2, puVar2 != (undefined4 *)0x0) {
    *param_2 = puVar2[2];
    iVar1 = FUN_420061d8(*puVar2);
    if ((iVar1 != 0) && (*(code **)(iVar1 + 4) != (code *)0x0)) {
      (**(code **)(iVar1 + 4))(puVar2[1]);
    }
    (*(code *)PTR_FUN_420004c0)(puVar2);
  }
  (*(code *)PTR_FUN_420004c0)(param_2);
  return;
}


