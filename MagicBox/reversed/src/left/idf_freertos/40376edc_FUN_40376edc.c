// strings: lock != NULL && 'Uninitialized lock used'

void FUN_40376edc(int param_1)

{
  int local_30 [12];
  
  local_30[0] = param_1;
  if (param_1 == 0) {
    FUN_40381ce4(PTR_s_locks_c_3c035754_0x18_40374764,0x133,PTR_s_check_lock_nonzero_4037477c,
                 PTR_s_lock____NULL_____Uninitialized_l_40374778);
  }
  FUN_40376c50(local_30,4);
  return;
}