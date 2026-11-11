// 403796b8  FUN_403796b8  FUN_403796b8  size=470
// strings: gfff

void FUN_403796b8(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_30 [12];
  uint uStack_24;
  
  uVar3 = (int)((longlong)(int)param_1 * (longlong)DAT_40374a7c >> 0x25) - ((int)param_1 >> 0x1f);
  uStack_24 = 0;
  FUN_40379604(auStack_30);
  uVar2 = uStack_24;
  if (uStack_24 < param_1) {
    if (param_1 == 0xf0) {
      FUN_40376b50(0x6d,1,4,4,0,*PTR_DAT_40374a80);
      FUN_40376b50(0x6d,1,6,4,0,*PTR_DAT_40374a84);
      (*DAT_40374444)(0x28);
      memw();
      memw();
      *DAT_40374a88 = *DAT_40374a88 & DAT_40374a8c;
LAB_4037979c:
      puVar1 = DAT_40374a70;
      memw();
      memw();
      *DAT_40374a74 = *DAT_40374a74 & 0xfffffffc | 2;
      memw();
      memw();
      *puVar1 = *puVar1 & 0xfffffc00;
      memw();
      memw();
      *puVar1 = *puVar1 & DAT_40374a90 | 0x400;
      *DAT_40374a94 = DAT_40374700;
      (*DAT_40374aa0)(0xf0);
      if (uVar2 < 0xf1) {
        return;
      }
      goto LAB_40379870;
    }
    memw();
    memw();
    *DAT_40374a88 = (7 >> (uVar3 & 0x1f)) << 0xd | *DAT_40374a88 & DAT_40374a8c;
    if (param_1 != 0xa0) goto LAB_40379764;
LAB_40379781:
    memw();
    memw();
    *DAT_40374a74 = *DAT_40374a74 & 0xfffffffc | 1;
  }
  else {
    if (param_1 == 0xa0) goto LAB_40379781;
    if (param_1 == 0xf0) goto LAB_4037979c;
LAB_40379764:
    if (param_1 != 0x50) {
                    /* WARNING: Subroutine does not return */
      FUN_40381c60();
    }
    memw();
    memw();
    *DAT_40374a74 = *DAT_40374a74 & 0xfffffffc;
  }
  puVar1 = DAT_40374a70;
  memw();
  memw();
  *DAT_40374a70 = *DAT_40374a70 & 0xfffffc00;
  memw();
  memw();
  *puVar1 = *puVar1 & DAT_40374a90 | 0x400;
  *DAT_40374a94 = DAT_40374700;
  (*DAT_40374aa0)(param_1);
  if (uVar2 <= param_1) {
    return;
  }
  if (uVar2 == 0xf0) {
    FUN_40376b50(0x6d,1,4,4,0,*PTR_DAT_40374a98);
    FUN_40376b50(0x6d,1,6,4,0,*PTR_DAT_40374a9c);
    (*DAT_40374444)(0x28);
  }
LAB_40379870:
  memw();
  memw();
  *DAT_40374a88 = (7 >> (uVar3 & 0x1f)) << 0xd | *DAT_40374a88 & DAT_40374a8c;
  return;
}


