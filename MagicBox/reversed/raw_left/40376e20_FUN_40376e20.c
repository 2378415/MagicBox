// 40376e20  FUN_40376e20  FUN_40376e20  size=48
// strings: lock != NULL && 'Uninitialized lock used'

void FUN_40376e20(int *param_1)

{
  int *local_30 [12];
  
  local_30[0] = param_1;
  if (param_1 == (int *)0x0) {
    FUN_40381ce4(PTR_s_locks_c_3c035754_0x18_40374764,0x133,PTR_s_check_lock_nonzero_4037477c,
                 PTR_s_lock____NULL_____Uninitialized_l_40374778);
  }
  if (*param_1 == DAT_40374780) {
    local_30[0] = DAT_40374788;
  }
  FUN_40376ba8(local_30,0xffffffff,4);
  return;
}


