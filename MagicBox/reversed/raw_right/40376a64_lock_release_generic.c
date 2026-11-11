// 40376a64  lock_release_generic  FUN_40376a64  size=90

void FUN_40376a64(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 uVar3;
  int local_30 [12];
  
  uVar3 = 0;
  iVar1 = FUN_4037db0c();
  if (iVar1 != 1) {
    iVar1 = *param_1;
    if (iVar1 == 0) {
      iVar1 = FUN_40381d9c(PTR_s_locks_c_3c032e6c_0x18_40374728,0xb8,
                           PTR_s_lock_release_generic_40374738,PTR_DAT_40374734);
    }
    uVar2 = rsr(uVar3);
    if ((uVar2 & 0xf) == 0) {
      if (param_2 == 4) {
        FUN_4037b548();
      }
      else {
        FUN_4037b39c(iVar1,0,0);
      }
    }
    else {
      if (param_2 == 4) {
                    /* WARNING: Subroutine does not return */
        FUN_40381ce0();
      }
      local_30[0] = 0;
      FUN_4037b664(iVar1,local_30);
      if (local_30[0] != 0) {
        FUN_4037be34();
      }
    }
  }
  return;
}


