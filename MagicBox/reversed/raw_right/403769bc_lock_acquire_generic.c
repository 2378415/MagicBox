// 403769bc  lock_acquire_generic  FUN_403769bc  size=164
// strings: h != ((void *)0)

undefined4 FUN_403769bc(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  int local_30 [12];
  
  uVar5 = 0;
  iVar3 = *param_1;
  if (iVar3 == 0) {
    uVar5 = 0;
    iVar3 = FUN_4037db0c();
    if (iVar3 == 1) {
      return 0;
    }
    FUN_40376980(param_1,param_3);
    iVar3 = *param_1;
    if (iVar3 == 0) {
      FUN_40381d9c(PTR_s_locks_c_3c032e6c_0x18_40374728,0x7b,PTR_s_lock_acquire_generic_40374730,
                   PTR_s_h______void___0__4037472c);
    }
  }
  iVar1 = FUN_4037db0c();
  if (iVar1 == 1) {
    uVar2 = 0;
  }
  else {
    uVar4 = rsr(uVar5);
    if ((uVar4 & 0xf) == 0) {
      if (param_3 == 4) {
        iVar3 = FUN_4037b914(iVar3,param_2);
      }
      else {
        iVar3 = FUN_4037b80c(iVar3,param_2);
      }
    }
    else {
      if (param_3 == 4) {
                    /* WARNING: Subroutine does not return */
        FUN_40381ce0();
      }
      local_30[0] = 0;
      iVar3 = FUN_4037b958(iVar3,0,local_30);
      if (iVar3 == 0 && param_2 != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_40381ce0();
      }
      if (local_30[0] != 0) {
        FUN_4037be34();
      }
    }
    if (iVar3 == 1) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}


