void FUN_40376d50(int *param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 uVar3;
  
  uVar3 = 0;
  iVar1 = FUN_4037e0e0();
  if (iVar1 != 1) {
    if (*param_1 == 0) {
      FUN_40381ce4(PTR_s_locks_c_3c035754_0x18_40374764,0xb8,PTR_s_lock_release_generic_4037476c,
                   PTR_s_h_3c03aeb8_0x34_40374768);
    }
    uVar2 = rsr(uVar3);
    if ((uVar2 & 0xf) != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_40381c60();
    }
    FUN_4037b8d4();
  }
  return;
}