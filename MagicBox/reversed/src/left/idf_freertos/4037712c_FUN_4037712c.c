void FUN_4037712c(int param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint in_SCOMPARE1;
  int local_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined1 uStack_34;
  int iStack_30;
  
  puVar5 = DAT_403747dc;
  piVar4 = DAT_403747d8;
  if (((*DAT_403747cc == '\x01') && (param_1 != 0)) && (*DAT_403747d8 != 0)) {
    uVar7 = (uint)DAT_403747dc & 3;
    uStack_34 = 0;
    puVar11 = (uint *)((uint)DAT_403747dc & 0xfffffffc);
    memw();
    uVar10 = 0xff << 0x20 - (((uint)DAT_403747dc & 3) * -8 + 0x20) ^ 0xffffffff;
    uVar3 = (uint)DAT_403747dc & 3;
    uVar8 = uVar10 & *puVar11;
    do {
      wsr((char)in_SCOMPARE1,uVar8);
      uVar2 = *puVar11;
      if (uVar2 == in_SCOMPARE1) {
        *puVar11 = 1 << 0x20 - (uVar3 * -8 + 0x20) | uVar8;
      }
      uVar9 = uVar2 & uVar10;
    } while ((uVar2 != uVar8) && (bVar1 = uVar8 != uVar9, uVar8 = uVar9, bVar1));
    uStack_38 = uVar2 >> (uVar7 << 3) & 0xff;
    if (uStack_38 == 0) {
      local_40 = param_1;
      uStack_3c = param_2;
      iVar6 = FUN_4037bf20();
      if (iVar6 == 0) {
        iStack_30 = FUN_4037b768(*piVar4,&local_40,0,0);
      }
      else {
        iStack_30 = FUN_4037b988(*piVar4,&local_40,&uStack_38,0);
        if (uStack_38 == 1) {
          FUN_4037c210();
        }
      }
      if (iStack_30 != 1) {
        memw();
        memw();
        *puVar5 = 0;
        memw();
      }
    }
  }
  return;
}