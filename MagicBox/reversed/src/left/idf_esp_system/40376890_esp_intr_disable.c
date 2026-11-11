// strings: svd != NULL | esp_intr_disable

undefined4 FUN_40376890(undefined4 *param_1)

{
  uint *puVar1;
  uint uVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  ushort *in_t0;
  undefined1 in_PRID;
  undefined8 uVar8;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0x102;
  }
  FUN_4037bf20();
  FUN_4037bf44(PTR_DAT_40374708,0xffffffff);
  puVar1 = (uint *)param_1[1];
  puVar7 = (uint *)*param_1;
  if (puVar1 == (uint *)0x0) {
    uVar6 = *puVar7;
    iVar4 = (int)(uVar6 << 2) >> 0x18;
    if (-1 < (int)(uVar6 << 2)) goto LAB_403768f9;
  }
  else {
    *(ushort *)puVar1 = (ushort)*puVar1 | 1;
    puVar3 = (ushort *)puVar7[1];
    iVar4 = (int)(char)(*puVar1 >> 1);
    uVar8 = CONCAT44(iVar4,iVar4);
    if (puVar3 == (ushort *)0x0) {
      puVar7 = (uint *)PTR_s_esp_intr_disable_40374710;
      puVar3 = in_t0;
      uVar8 = FUN_40381ce4(PTR_s_intr_alloc_c_3c033c58_0x20_40374714,0x37c,
                           PTR_s_esp_intr_disable_40374710,PTR_s_svd____NULL_4037470c);
    }
    do {
      iVar4 = (int)((ulonglong)uVar8 >> 0x20);
      iVar5 = (int)uVar8;
      if (((*(int *)puVar3 << 0x17) >> 0x18 == iVar5) && ((*puVar3 & 1) == 0)) {
        if (iVar5 < 0) goto LAB_4037694e;
        goto LAB_40376935;
      }
      puVar3 = *(ushort **)(puVar3 + 10);
    } while (puVar3 != (ushort *)0x0);
    if (-1 < iVar5) {
      uVar6 = *puVar7;
LAB_403768f9:
      (*DAT_4037443c)(uVar6 >> 0x10 & 1,iVar4,6);
      goto LAB_40376935;
    }
LAB_4037694e:
    uVar6 = *puVar7;
  }
  uVar2 = rsr(in_PRID);
  if ((uVar6 >> 0x10 & 1) != (uVar2 >> 0xd & 1)) {
    FUN_4037bf20();
    FUN_4037c094(PTR_DAT_40374708);
    return 0x102;
  }
  FUN_40383bfc(1 << 0x20 - (0x20 - (uVar6 >> 0x11 & 0x1f)));
LAB_40376935:
  FUN_4037bf20();
  FUN_4037c094(PTR_DAT_40374708);
  return 0;
}