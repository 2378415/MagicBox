// strings: lock | core_owner_id == lock->owner | spinlock.h | spinlock_release | lock->count < 0x100 | nesting > 0 | port.c | vPortExitCritical

void FUN_4037bd38(int *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *in_t0;
  undefined1 uVar6;
  undefined1 in_PRID;
  
  uVar6 = 0;
  if (param_1 == (int *)0x0) {
    uVar6 = 0;
    FUN_40381d9c(PTR_s_spinlock_h_3c030b80_0x28_40374d1c,0xb5,PTR_s_spinlock_release_40374d40,
                 PTR_DAT_40374d14);
  }
  uVar5 = rsil(3);
  iVar3 = rsr(in_PRID);
  if (iVar3 != *param_1) {
    uVar5 = FUN_40381d9c(PTR_s_spinlock_h_3c030b80_0x28_40374d1c,0xbe,
                         PTR_s_spinlock_release_40374d40,PTR_s_core_owner_id____lock_>owner_40374d44
                        );
  }
  uVar1 = param_1[1] - 1;
  param_1[1] = uVar1;
  if (uVar1 == 0) {
    *param_1 = DAT_40374b44;
  }
  else if (0xff < uVar1) {
    uVar5 = FUN_40381d9c(PTR_s_spinlock_h_3c030b80_0x28_40374d1c,0xc4,
                         PTR_s_spinlock_release_40374d40,PTR_s_lock_>count_<_0x100_40374d48);
  }
  wsr(uVar6,uVar5);
  rsync();
  uVar1 = rsr(in_PRID);
  uVar1 = uVar1 >> 0xd & 1;
  iVar3 = uVar1 << 2;
  piVar2 = (int *)(uVar1 * 4 + DAT_40374d38);
  piVar4 = (int *)*piVar2;
  if (*piVar2 < 1) {
    piVar2 = in_t0;
    iVar3 = FUN_40381d9c(PTR_s_port_c_3c032bc8_0x3a_40374cf4,0x1fa,PTR_s_vPortExitCritical_40374d50,
                         PTR_s_nesting_>_0_40374d4c);
    piVar4 = piVar2;
  }
  *piVar2 = (int)piVar4 + -1;
  if ((int)piVar4 + -1 == 0) {
    (*DAT_40374d10)(*(undefined4 *)(DAT_40374d3c + iVar3));
  }
  return;
}