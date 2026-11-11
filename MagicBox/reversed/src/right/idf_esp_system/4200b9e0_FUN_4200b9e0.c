undefined4 FUN_4200b9e0(int *param_1,uint param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  uint uVar10;
  
  iVar7 = DAT_42000a70;
  if (param_2 < 0x70) {
    uVar5 = 0xffffffff;
  }
  else {
    iVar6 = *param_1;
    if (iVar6 == DAT_42000a6c) {
      *(int *)(DAT_42000a70 + 8) = param_1[0x14];
      *(undefined4 *)(iVar7 + 4) = 0xe8;
      *(int *)(iVar7 + 0x10) = param_1[0x15];
      *(undefined4 *)(iVar7 + 0xc) = 0xee;
      FUN_42024718(DAT_42000a74);
      FUN_420246d0();
    }
    else {
      param_1[0x14] = DAT_42000a78;
      param_1[0x15] = 0;
    }
    if (iVar6 == 0) {
      iVar6 = param_1[1];
      *param_3 = (char)iVar6;
      uVar1 = (undefined1)((uint)iVar6 >> 8);
      param_3[1] = uVar1;
      uVar2 = (undefined1)((uint)iVar6 >> 0x10);
      param_3[2] = uVar2;
      bVar4 = (byte)((uint)iVar6 >> 0x18);
      param_3[3] = bVar4;
      iVar7 = param_1[2];
      param_3[4] = (char)iVar7;
      param_3[5] = (char)((uint)iVar7 >> 8);
      param_3[6] = (char)((uint)iVar7 >> 0x10);
      param_3[7] = (char)((uint)iVar7 >> 0x18);
      for (iVar7 = 0; iVar7 < 4; iVar7 = iVar7 + 1) {
        iVar9 = param_1[iVar7 + 4];
        puVar8 = param_3 + (iVar7 + 0x40) * 4;
        *puVar8 = (char)iVar9;
        puVar8[1] = (char)((uint)iVar9 >> 8);
        puVar8[2] = (char)((uint)iVar9 >> 0x10);
        puVar8[3] = (char)((uint)iVar9 >> 0x18);
      }
      if (iVar6 < 0) {
        *param_3 = (char)iVar6;
        param_3[1] = uVar1;
        param_3[2] = uVar2;
        param_3[3] = bVar4 & 0x3f;
      }
      uVar5 = *(undefined4 *)(param_3 + 0x100);
      if ((int)((uint)(byte)param_3[0x103] << 0x18) < 0) {
        param_3[0x100] = (char)uVar5;
        param_3[0x101] = (char)((uint)uVar5 >> 8);
        param_3[0x102] = (char)((uint)uVar5 >> 0x10);
        param_3[0x103] = (byte)((uint)uVar5 >> 0x18) & 0x3f;
        uVar5 = 0;
      }
      else {
        uVar5 = 0;
      }
    }
    else {
      iVar7 = param_1[1];
      *param_3 = (char)iVar7;
      param_3[1] = (char)((uint)iVar7 >> 8);
      param_3[2] = (char)((uint)iVar7 >> 0x10);
      param_3[3] = (char)((uint)iVar7 >> 0x18);
      uVar10 = param_1[2];
      param_3[4] = (byte)uVar10;
      uVar1 = (undefined1)(uVar10 >> 8);
      param_3[5] = uVar1;
      uVar2 = (undefined1)(uVar10 >> 0x10);
      param_3[6] = uVar2;
      uVar3 = (undefined1)(uVar10 >> 0x18);
      param_3[7] = uVar3;
      for (iVar7 = 0; iVar7 < 0x10; iVar7 = iVar7 + 1) {
        iVar6 = param_1[iVar7 + 3];
        puVar8 = param_3 + (iVar7 + 0x40) * 4;
        *puVar8 = (char)iVar6;
        puVar8[1] = (char)((uint)iVar6 >> 8);
        puVar8[2] = (char)((uint)iVar6 >> 0x10);
        puVar8[3] = (char)((uint)iVar6 >> 0x18);
      }
      iVar7 = param_1[0x13];
      param_3[0x14] = (char)iVar7;
      param_3[0x15] = (char)((uint)iVar7 >> 8);
      param_3[0x16] = (char)((uint)iVar7 >> 0x10);
      param_3[0x17] = (char)((uint)iVar7 >> 0x18);
      iVar7 = param_1[0x16];
      param_3[8] = (char)iVar7;
      param_3[9] = (char)((uint)iVar7 >> 8);
      param_3[10] = (char)((uint)iVar7 >> 0x10);
      param_3[0xb] = (char)((uint)iVar7 >> 0x18);
      iVar7 = param_1[0x17];
      param_3[0xc] = (char)iVar7;
      param_3[0xd] = (char)((uint)iVar7 >> 8);
      param_3[0xe] = (char)((uint)iVar7 >> 0x10);
      param_3[0xf] = (char)((uint)iVar7 >> 0x18);
      iVar7 = param_1[0x18];
      param_3[0x10] = (char)iVar7;
      param_3[0x11] = (char)((uint)iVar7 >> 8);
      param_3[0x12] = (char)((uint)iVar7 >> 0x10);
      param_3[0x13] = (char)((uint)iVar7 >> 0x18);
      if ((uVar10 & 0x20) == 0) {
        uVar5 = 0;
      }
      else {
        param_3[4] = (byte)uVar10 & 0xef;
        param_3[5] = uVar1;
        param_3[6] = uVar2;
        param_3[7] = uVar3;
        uVar5 = 0;
      }
    }
  }
  return uVar5;
}