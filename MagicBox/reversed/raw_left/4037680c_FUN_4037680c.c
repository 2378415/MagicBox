// 4037680c  FUN_4037680c  FUN_4037680c  size=128

undefined4 FUN_4037680c(undefined4 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  ushort *puVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined1 in_PRID;
  
  if (param_1 == (undefined4 *)0x0) {
LAB_4037686b:
    uVar1 = 0x102;
  }
  else {
    FUN_4037bf20();
    FUN_4037bf44(PTR_DAT_40374708,0xffffffff);
    puVar3 = (ushort *)param_1[1];
    puVar4 = (uint *)*param_1;
    if (puVar3 == (ushort *)0x0) {
      uVar7 = *puVar4;
      iVar6 = uVar7 << 2;
    }
    else {
      *puVar3 = *puVar3 & 0xfffe;
      uVar7 = *puVar4;
      iVar6 = *(int *)puVar3 << 0x17;
    }
    uVar5 = uVar7 >> 0x10 & 1;
    if (iVar6 >> 0x18 < 0) {
      uVar2 = rsr(in_PRID);
      if ((uVar2 >> 0xd & 1) != uVar5) {
        FUN_4037bf20();
        FUN_4037c094(PTR_DAT_40374708);
        goto LAB_4037686b;
      }
      FUN_40383be4(1 << 0x20 - (0x20 - (uVar7 >> 0x11 & 0x1f)));
    }
    else {
      (*DAT_4037443c)(uVar5,iVar6 >> 0x18,uVar7 >> 0x11 & 0x1f);
    }
    FUN_4037bf20();
    FUN_4037c094(PTR_DAT_40374708);
    uVar1 = 0;
  }
  return uVar1;
}


