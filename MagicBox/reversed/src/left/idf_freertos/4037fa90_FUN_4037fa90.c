undefined4 FUN_4037fa90(int param_1,uint param_2,int param_3,int param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  uint local_40;
  
  iVar2 = *(int *)(param_1 + 4);
  memw();
  memw();
  *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) & 0xfffffff7 | (param_5 >> 0x1f) << 3;
  memw();
  param_5 = param_5 & 0xffff;
  memw();
  *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) | DAT_40374870;
  memw();
  memw();
  *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) | DAT_40374a20;
  if (param_2 < 0x100) {
    memw();
    memw();
    *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) | DAT_40374550;
    uVar1 = DAT_40374858;
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) & 0xffff0000 | param_2 & 0xffff;
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) & 0xfffffff | uVar1;
  }
  else {
    memw();
    memw();
    *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) | DAT_40374550;
    uVar1 = DAT_40375194;
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) & 0xffff0000 | param_2 & 0xffff;
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) | uVar1;
  }
  memw();
  memw();
  *(uint *)(iVar2 + 0x3c) = *(uint *)(iVar2 + 0x3c) & 0xfffffffd | (uint)(param_3 == 0x20) * 2;
  memw();
  memw();
  *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0x3ffffff | (param_3 + -1) * 0x4000000;
  memw();
  memw();
  *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) & DAT_4037485c | (uint)(param_3 != 0) << 0x1e;
  memw();
  param_4 = (uint)*(byte *)(param_1 + 0xc) + param_4;
  memw();
  *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) & DAT_40374864 | (uint)(param_4 != 0) << 0x1d;
  memw();
  memw();
  *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xffffffc0 | param_4 - 1U & 0x3f;
  memw();
  memw();
  *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) & DAT_4037486c;
  uVar1 = DAT_40374868;
  memw();
  memw();
  *(uint *)(iVar2 + 0x28) = *(uint *)(iVar2 + 0x28) & 0xfffffc00;
  memw();
  memw();
  *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) & uVar1;
  memw();
  memw();
  *(uint *)(iVar2 + 0x24) = *(uint *)(iVar2 + 0x24) & 0xfffffc00;
  memw();
  memw();
  memw();
  local_40 = *(uint *)(iVar2 + 8) & DAT_403751a4;
  memw();
  memw();
  memw();
  *(uint *)(iVar2 + 0xe0) = *(uint *)(iVar2 + 0xe0) & 0xfffffffe;
  memw();
  local_40 = local_40 | DAT_40374944;
  memw();
  if (param_5 == 4) {
    memw();
    local_40 = local_40 | DAT_40375184;
    memw();
  }
  else if (param_5 < 5) {
    if (param_5 == 2) {
      memw();
      local_40 = local_40 | DAT_40374460;
      memw();
    }
    else if (param_5 == 3) {
      memw();
      local_40 = local_40 | DAT_403751a0;
      memw();
    }
    else if (param_5 == 0) {
      memw();
      local_40 = local_40 & DAT_40374b30;
      memw();
    }
  }
  else if (param_5 == 0x10) {
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    local_40 = local_40 | 0x270;
    memw();
  }
  else if (param_5 == 0x11) {
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    local_40 = local_40 | 0x270;
    memw();
    memw();
    memw();
    *(uint *)(iVar2 + 0xe0) = *(uint *)(iVar2 + 0xe0) | 1;
  }
  else {
    if (param_5 != 5) {
                    /* WARNING: Subroutine does not return */
      FUN_40381c60();
    }
    memw();
    local_40 = local_40 | DAT_40374920;
    memw();
  }
  memw();
  memw();
  *(uint *)(iVar2 + 8) = local_40;
  return 0;
}