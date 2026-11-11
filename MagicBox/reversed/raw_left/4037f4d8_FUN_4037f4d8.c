// 4037f4d8  FUN_4037f4d8  FUN_4037f4d8  size=604

undefined4 FUN_4037f4d8(int param_1,uint param_2,int param_3,int param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint local_40;
  uint uStack_3c;
  
  iVar2 = *(int *)(param_1 + 4);
  memw();
  memw();
  *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) & 0xfffffff7 | (param_5 >> 0x1f) << 3;
  memw();
  memw();
  *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) | DAT_40374870;
  memw();
  memw();
  *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) | DAT_40374a20;
  uVar3 = param_5 & 0xffff;
  if (param_2 < 0x100) {
    memw();
    memw();
    *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) | DAT_40374550;
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar2 + 0x18) = param_2 & 0xffff | DAT_40374858;
  }
  else {
    memw();
    memw();
    *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) | DAT_40374550;
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar2 + 0x18) = param_2 & 0xff | DAT_40375194;
  }
  memw();
  memw();
  *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0x7ffffff | (param_3 + -1) * 0x8000000;
  memw();
  memw();
  *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) & DAT_4037485c | (uint)(param_3 != 0) << 0x1e;
  memw();
  param_4 = (uint)*(byte *)(param_1 + 0xc) + param_4;
  memw();
  *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) & DAT_40374864 | (uint)(param_4 != 0) << 0x1d;
  uVar1 = DAT_4037486c;
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xffffff00 | param_4 - 1U & 0xff;
  memw();
  memw();
  *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) & uVar1;
  memw();
  memw();
  *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) & DAT_40374868;
  memw();
  memw();
  memw();
  memw();
  memw();
  uStack_3c = *(uint *)(iVar2 + 8) & DAT_40375198;
  memw();
  memw();
  local_40 = *(uint *)(iVar2 + 0x10) & DAT_4037519c;
  memw();
  if (uVar3 == 3) {
    memw();
    uStack_3c = uStack_3c | DAT_40374460;
    memw();
    memw();
    uVar3 = 0x20;
  }
  else {
    if ((param_5 >> 2 & 0x3fff) != 0) {
      if (uVar3 == 4) {
        memw();
        uVar3 = DAT_40374464;
      }
      else {
        if (uVar3 != 5) {
                    /* WARNING: Subroutine does not return */
          FUN_40381c60();
        }
        memw();
        uStack_3c = uStack_3c | DAT_40374464;
        memw();
        memw();
        uVar3 = 0x40;
      }
      uStack_3c = uStack_3c | uVar3;
      memw();
      memw();
      local_40 = local_40 | DAT_40374944;
      memw();
      goto LAB_4037f71f;
    }
    if (uVar3 != 2) goto LAB_4037f71f;
    memw();
    uVar3 = DAT_40374460;
  }
  uStack_3c = uStack_3c | uVar3;
  memw();
  memw();
  local_40 = local_40 | DAT_40374698;
  memw();
LAB_4037f71f:
  memw();
  memw();
  *(uint *)(iVar2 + 8) = uStack_3c;
  memw();
  memw();
  *(uint *)(iVar2 + 0x10) = local_40;
  return 0;
}


