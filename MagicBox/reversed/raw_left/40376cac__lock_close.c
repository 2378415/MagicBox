// 40376cac  _lock_close  FUN_40376cac  size=59
// strings: xQueueGetMutexHolder( ( h ) ) == ((void *)0)

void FUN_40376cac(int *param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_4037bf44(PTR_DAT_40374758,0xffffffff);
  iVar2 = *param_1;
  if (iVar2 != 0) {
    iVar1 = FUN_4037b678(iVar2);
    if (iVar1 != 0) {
      FUN_40381ce4(PTR_s_locks_c_3c035754_0x18_40374764,100,PTR_s__lock_close_40374774,
                   PTR_s_xQueueGetMutexHolder____h________40374770);
    }
    FUN_4037bdf8(iVar2);
    *param_1 = iVar1;
  }
  FUN_4037c094(PTR_DAT_40374758);
  return;
}


