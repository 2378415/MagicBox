// 4037bbe8  spinlock_acquire  FUN_4037bbe8  size=332
// strings: lock | lock->count > 0 && lock->count < 0xFF | spinlock.h | spinlock_acquire | lock->owner == core_owner_id | lock->count == 0 | lock->owner == SPINLOCK_FREE || lock->owner == o | lock->count < 0xFF

undefined4 FUN_4037bbe8(uint *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  uint in_t0;
  undefined1 uVar8;
  uint uVar9;
  undefined1 in_CCOUNT;
  undefined1 in_PRID;
  
  uVar9 = 0;
  uVar5 = rsil(3);
  if (param_1 == (uint *)0x0) {
    uVar9 = 0;
    FUN_40381d9c(PTR_s_spinlock_h_3c030b80_0x28_40374d1c,0x54,PTR_s_spinlock_acquire_40374d18,
                 PTR_DAT_40374d14);
  }
  uVar8 = (undefined1)uVar9;
  uVar3 = rsil(3);
  uVar4 = rsr(in_PRID);
  if (uVar4 == *param_1) {
    uVar9 = param_1[1];
    if (0xfd < uVar9 - 1) {
      uVar9 = in_t0;
      FUN_40381d9c(PTR_s_spinlock_h_3c030b80_0x28_40374d1c,0x6a,PTR_s_spinlock_acquire_40374d18,
                   PTR_s_lock_>count_>_0____lock_>count_<_40374d20);
    }
    param_1[1] = uVar9 + 1;
    wsr(uVar8,uVar3);
    rsync();
LAB_4037bd03:
    uVar9 = rsr(in_PRID);
    uVar9 = uVar9 >> 0xd & 1;
    piVar6 = (int *)(uVar9 * 4 + DAT_40374d38);
    iVar7 = *piVar6 + 1;
    *piVar6 = iVar7;
    if (iVar7 == 1) {
      *(undefined4 *)(DAT_40374d3c + uVar9 * 4) = uVar5;
    }
    uVar5 = 1;
  }
  else {
    uVar9 = uVar9 & 0xffffcfff;
    iVar7 = FUN_403788fc(param_1,DAT_40374b44,uVar4);
    uVar1 = DAT_40374b44;
    uVar8 = (undefined1)uVar9;
    if ((param_2 == 0) || (iVar7 != 0)) {
      uVar9 = *param_1;
      if (iVar7 != 0) goto LAB_4037bc80;
    }
    else {
      iVar7 = rsr(in_CCOUNT);
      if (param_2 == 0xffffffff) {
        do {
          uVar9 = uVar9 & 0xffffcfff;
          iVar7 = FUN_403788fc(param_1,uVar1,uVar4);
          uVar8 = (undefined1)uVar9;
        } while (iVar7 == 0);
LAB_4037bd31:
        uVar9 = *param_1;
LAB_4037bc80:
        if (uVar4 != uVar9) {
          FUN_40381d9c(PTR_s_spinlock_h_3c030b80_0x28_40374d1c,0x8d,PTR_s_spinlock_acquire_40374d18,
                       PTR_s_lock_>owner____core_owner_id_40374d24);
        }
        if (param_1[1] != 0) {
          FUN_40381d9c(PTR_s_spinlock_h_3c030b80_0x28_40374d1c,0x8e,PTR_s_spinlock_acquire_40374d18,
                       PTR_s_lock_>count____0_40374d28);
        }
        param_1[1] = 1;
        wsr(uVar8,uVar3);
        rsync();
        goto LAB_4037bd03;
      }
      do {
        uVar9 = uVar9 & 0xffffcfff;
        iVar2 = FUN_403788fc(param_1,uVar1,uVar4);
        uVar8 = (undefined1)uVar9;
        if (iVar2 != 0) goto LAB_4037bd31;
        iVar2 = rsr(in_CCOUNT);
      } while ((uint)(iVar2 - iVar7) <= param_2);
      uVar9 = *param_1;
    }
    if (((uVar4 ^ DAT_40374d2c) != uVar9) && (uVar9 != DAT_40374b44)) {
      FUN_40381d9c(PTR_s_spinlock_h_3c030b80_0x28_40374d1c,0x91,PTR_s_spinlock_acquire_40374d18,
                   PTR_s_lock_>owner____SPINLOCK_FREE____l_40374d30);
    }
    if (0xfe < param_1[1]) {
      FUN_40381d9c(PTR_s_spinlock_h_3c030b80_0x28_40374d1c,0x92,PTR_s_spinlock_acquire_40374d18,
                   PTR_s_lock_>count_<_0xFF_40374d34);
    }
    wsr(uVar8,uVar3);
    rsync();
    (*DAT_40374d10)(uVar5);
    uVar5 = 0;
  }
  return uVar5;
}


