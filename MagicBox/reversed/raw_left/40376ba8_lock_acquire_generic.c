// 40376ba8  lock_acquire_generic  FUN_40376ba8  size=159
// strings: h != ((void *)0) | lock_acquire_generic

int FUN_40376ba8(int *param_1,int param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  int local_40 [4];
  int iStack_30;
  
  uVar5 = 0;
  iVar3 = *param_1;
  if (iVar3 == 0) {
    uVar5 = 0;
    iVar3 = FUN_4037e0e0();
    puVar1 = PTR_DAT_40374758;
    if (iVar3 == 1) {
      return 0;
    }
    FUN_4037bf44(PTR_DAT_40374758,0xffffffff);
    if (*param_1 == 0) {
      iVar3 = FUN_4037b894(param_3);
      if (iVar3 == 0) goto LAB_40376bd4;
      *param_1 = iVar3;
    }
    FUN_4037c094(puVar1);
    iVar3 = *param_1;
    if (iVar3 == 0) {
      FUN_40381ce4(PTR_s_locks_c_3c035754_0x18_40374764,0x7b,PTR_s_lock_acquire_generic_40374760,
                   PTR_s_h______void___0__4037475c);
    }
  }
  iVar2 = FUN_4037e0e0();
  if (iVar2 == 1) {
    return 0;
  }
  uVar4 = rsr(uVar5);
  if ((uVar4 & 0xf) == 0) {
    if (param_3 == 4) {
      iStack_30 = FUN_4037bcfc();
    }
    else {
      iStack_30 = FUN_4037bbf4(iVar3,param_2);
    }
LAB_40376c42:
    return -(uint)(iStack_30 != 1);
  }
  if (param_3 != 4) {
    local_40[0] = 0;
    iStack_30 = FUN_4037bd38(iVar3,0,local_40);
    if ((iStack_30 != 0) || (param_2 == 0)) {
      if (local_40[0] != 0) {
        FUN_4037c210();
      }
      goto LAB_40376c42;
    }
  }
LAB_40376bd4:
                    /* WARNING: Subroutine does not return */
  FUN_40381c60();
}


