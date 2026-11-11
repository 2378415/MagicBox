// 42015a20  FUN_42015a20  FUN_42015a20  size=436
// strings: Ep addr %02x overflow | Ep addr %02x fifo overflow

undefined4 FUN_42015a20(uint param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint local_30;
  
  bVar1 = *(byte *)(param_2 + 2);
  param_1 = param_1 & 0xff;
  uVar9 = bVar1 & 0x7f;
  if (uVar9 < 7) {
    iVar8 = *(int *)(param_1 * 8 + DAT_420013e0 + 4);
    uVar7 = *(ushort *)(param_2 + 4) & 0x7ff;
    if ((char)bVar1 < '\0') {
      if ((bVar1 & 0x7f) == 0) {
        memw();
        uVar6 = *(uint *)(iVar8 + 0x28);
      }
      else {
        memw();
        uVar6 = *(uint *)(uVar9 * 4 + iVar8 + 0x100);
      }
      if ((uVar6 >> 0x10) << 2 < uVar7) {
        (*DAT_42000060)(PTR_DAT_420013fc);
        (*DAT_42000060)(PTR_s_Ep_addr__02x_fifo_overflow_42001428,*(undefined1 *)(param_2 + 2));
        (*DAT_42000060)(PTR_DAT_42001404);
        return 0xfffffffe;
      }
      iVar4 = DAT_420013f8 + (param_1 * 0x10 + uVar9) * 0x10;
      *(short *)(iVar4 + 8) = (short)uVar7;
      bVar2 = *(byte *)(param_2 + 3);
      *(byte *)(iVar4 + 10) = bVar2 & 3;
      memw();
      memw();
      *(uint *)(iVar8 + 0x81c) = 1 << 0x20 - (0x20 - (bVar1 & 0x1f)) | *(uint *)(iVar8 + 0x81c);
      puVar5 = (uint *)(uVar9 * 0x20 + iVar8 + 0x900);
      memw();
      if ((*puVar5 & 0x8000) == 0) {
        memw();
        memw();
        *puVar5 = (bVar2 & 3) << 0x12 | uVar7 | *puVar5 | uVar9 << 0x16 | DAT_42001424;
      }
      uVar7 = DAT_42001408;
      memw();
      local_30 = 0;
      do {
        memw();
        local_30 = local_30 + 1;
        memw();
        if (DAT_42001408 < local_30) goto LAB_42015bd4;
        memw();
      } while (-1 < *(int *)(iVar8 + 0x10));
      memw();
      local_30 = 0;
      memw();
      *(uint *)(iVar8 + 0x10) = uVar9 << 6 | 0x20;
      do {
        memw();
        local_30 = local_30 + 1;
        memw();
        if (uVar7 < local_30) break;
        memw();
      } while ((*(uint *)(iVar8 + 0x10) & 0x20) != 0);
    }
    else {
      iVar4 = DAT_420013f8 + (param_1 * 0x10 + uVar9 + 7) * 0x10;
      *(short *)(iVar4 + 8) = (short)uVar7;
      bVar1 = *(byte *)(param_2 + 3);
      *(byte *)(iVar4 + 10) = bVar1 & 3;
      memw();
      memw();
      *(uint *)(iVar8 + 0x81c) =
           1 << 0x20 - (0x20 - (uVar9 + 0x10 & 0x1f)) | *(uint *)(iVar8 + 0x81c);
      puVar5 = (uint *)(uVar9 * 0x20 + iVar8 + 0xb00);
      memw();
      if ((*puVar5 & 0x8000) == 0) {
        memw();
        memw();
        *puVar5 = (bVar1 & 3) << 0x12 | uVar7 | *puVar5 | DAT_42001424;
      }
    }
LAB_42015bd4:
    uVar3 = 0;
  }
  else {
    (*DAT_42000060)(PTR_DAT_420013fc);
    (*DAT_42000060)(PTR_s_Ep_addr__02x_overflow_42001420,*(undefined1 *)(param_2 + 2));
    (*DAT_42000060)(PTR_DAT_42001404);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


