void FUN_42011c14(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint local_b0;
  undefined4 uStack_ac;
  undefined1 auStack_a8 [16];
  undefined1 auStack_98 [88];
  ushort uStack_40;
  byte bStack_3e;
  byte bStack_3d;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined1 auStack_34 [16];
  uint uStack_24;
  
  (*DAT_42000e1c)(auStack_98);
  iVar2 = FUN_4201283c(0,DAT_4200077c,0,&local_b0,&uStack_ac);
  puVar8 = (undefined4 *)0x0;
  if (iVar2 != 0) {
    return;
  }
  uVar5 = local_b0 + DAT_42000e0c;
  uVar7 = local_b0 + DAT_42000160;
  puVar6 = (undefined4 *)0x0;
  local_b0 = uVar7;
  for (; iVar2 = 0, uVar7 < uVar5; uVar7 = uVar7 + 0x20) {
    (*DAT_420002fc)(&uStack_40,uVar7,0x20);
    if (uStack_40 == DAT_42000e18) goto LAB_42011cfe;
    if (uStack_40 != DAT_42000e14) {
      uVar7 = 0;
      goto LAB_42011cfe;
    }
    (*DAT_42000e20)(auStack_98,&uStack_40,0x20);
    puVar3 = (undefined4 *)(*(code *)PTR_FUN_42000738)(1,0x34);
    if (puVar3 == (undefined4 *)0x0) {
      iVar2 = 0x101;
      uVar7 = 0;
      goto LAB_42011cfe;
    }
    *puVar3 = *DAT_420009fc;
    puVar3[3] = uStack_3c;
    puVar3[4] = uStack_38;
    puVar3[5] = DAT_4200077c;
    puVar3[1] = (uint)bStack_3e;
    puVar3[2] = (uint)bStack_3d;
    uVar1 = FUN_42011bcc(uStack_24 & 1);
    *(undefined1 *)((int)puVar3 + 0x29) = uVar1;
    *(byte *)((int)puVar3 + 0x2a) = (byte)(uStack_24 >> 1) & 1;
    *(undefined1 *)(puVar3 + 0xb) = 0;
    (*DAT_42000cfc)(puVar3 + 6,auStack_34,0x10);
    if (puVar6 == (undefined4 *)0x0) {
      puVar3[0xc] = puVar8;
      puVar8 = puVar3;
    }
    else {
      puVar3[0xc] = puVar6[0xc];
      puVar6[0xc] = puVar3;
    }
    puVar6 = puVar3;
  }
  uVar7 = 0;
LAB_42011cfe:
  if (uVar7 != 0) {
    (*DAT_42000e24)(auStack_a8,auStack_98);
    iVar4 = (*DAT_420009a4)(auStack_a8,uVar7 + 0x10,0x10);
    if ((iVar4 == 0) && (iVar2 == 0)) {
      *DAT_42000e10 = (int)puVar8;
      goto LAB_42011d48;
    }
  }
  while (puVar8 != (undefined4 *)0x0) {
    puVar8 = (undefined4 *)puVar8[0xc];
    (*(code *)PTR_FUN_420004c0)();
  }
LAB_42011d48:
  FUN_420128d0(uStack_ac);
  return;
}