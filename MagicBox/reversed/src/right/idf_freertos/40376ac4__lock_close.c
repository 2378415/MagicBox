// strings: xQueueGetMutexHolder( ( h ) ) == ((void *)0)

void FUN_40376ac4(int *param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_4037bbe8(PTR_DAT_4037471c,0xffffffff);
  iVar2 = *param_1;
  if (iVar2 != 0) {
    iVar1 = FUN_4037b2e8(iVar2);
    if (iVar1 != 0) {
      FUN_40381d9c(PTR_s_locks_c_3c032e6c_0x18_40374728,100,PTR_s__lock_close_40374740,
                   PTR_s_xQueueGetMutexHolder____h________4037473c);
    }
    FUN_4037ba14(iVar2);
    *param_1 = 0;
  }
  FUN_4037bd38(PTR_DAT_4037471c);
  return;
}