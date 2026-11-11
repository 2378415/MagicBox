// 40376c50  FUN_40376c50  FUN_40376c50  size=88

void FUN_40376c50(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 uVar3;
  int local_30 [12];
  
  uVar3 = 0;
  iVar1 = FUN_4037e0e0();
  if (iVar1 != 1) {
    iVar1 = *param_1;
    if (iVar1 == 0) {
      iVar1 = FUN_40381ce4(PTR_s_locks_c_3c035754_0x18_40374764,0xb8,
                           PTR_s_lock_release_generic_4037476c,PTR_s_h_3c03aeb8_0x34_40374768);
    }
    uVar2 = rsr(uVar3);
    if ((uVar2 & 0xf) == 0) {
      if (param_2 == 4) {
        FUN_4037b8d4();
      }
      else {
        FUN_4037b768(iVar1,0,0,0);
      }
    }
    else {
      if (param_2 == 4) {
                    /* WARNING: Subroutine does not return */
        FUN_40381c60();
      }
      local_30[0] = 0;
      FUN_4037ba5c(iVar1,local_30);
      if (local_30[0] != 0) {
        FUN_4037c210();
      }
    }
  }
  return;
}


