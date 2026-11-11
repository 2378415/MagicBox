// 420154f4  FUN_420154f4  FUN_420154f4  size=1018

uint FUN_420154f4(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  uint local_30;
  uint uStack_2c;
  uint uStack_28;
  
  uVar3 = param_1 & 0xff;
  (*DAT_42000094)(DAT_420013f8 + (param_1 & 0xff) * 0x100,0,0x100);
  FUN_42016998(uVar3);
  iVar9 = DAT_420013e0;
  iVar4 = uVar3 * 8 + DAT_420013e0;
  iVar6 = *(int *)(iVar4 + 4);
  memw();
  memw();
  uVar7 = *(uint *)(iVar6 + 0x48);
  memw();
  memw();
  if ((*(uint *)(iVar6 + 0x48) >> 10 & 0xf) + 1 < 7) {
    (*DAT_42000060)(PTR_DAT_420013fc);
    (*DAT_42000060)(PTR_s_dwc2_has_less_endpoints_than_con_42001400);
    (*DAT_42000060)(PTR_DAT_42001404);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  memw();
  memw();
  *(uint *)(iVar6 + 0x804) = *(uint *)(iVar6 + 0x804) | 2;
  memw();
  memw();
  *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) & 0xfffffffe;
  uVar5 = FUN_4202d634(iVar6);
  iVar4 = *(int *)(iVar4 + 4);
  memw();
  *(undefined4 *)(iVar6 + 0x38) = uVar5;
  memw();
  memw();
  *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) | 0x40;
  uVar2 = DAT_42001408;
  memw();
  uStack_28 = 0;
  do {
    memw();
    uStack_28 = uStack_28 + 1;
    memw();
    if (DAT_42001408 < uStack_28) goto LAB_420155ff;
    memw();
  } while (-1 < *(int *)(iVar4 + 0x10));
  memw();
  uStack_28 = 0;
  memw();
  memw();
  *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) | 1;
  do {
    memw();
    uStack_28 = uStack_28 + 1;
    memw();
    if (uVar2 < uStack_28) break;
    memw();
  } while ((*(uint *)(iVar4 + 0x10) & 1) != 0);
  memw();
  memw();
  *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) & 0xfffffffe;
LAB_420155ff:
  uVar1 = DAT_4200034c;
  memw();
  memw();
  *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) & DAT_4200140c;
  memw();
  memw();
  *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) | uVar1;
  FUN_42016a30(0x32);
  iVar9 = *(int *)(iVar9 + uVar3 * 8 + 4);
  memw();
  *(undefined4 *)(iVar9 + 0x104) = 0;
  memw();
  *(undefined4 *)(iVar9 + 0xe00) = 0;
  puVar8 = (uint *)(iVar9 + 0x800);
  memw();
  memw();
  *puVar8 = *puVar8 & 0xfffffffc;
  memw();
  if ((uVar7 >> 6 & 3) == 0) {
    memw();
    *puVar8 = *puVar8 | 3;
  }
  else {
    memw();
    *puVar8 = *puVar8 | 1;
  }
  memw();
  *(undefined4 *)(iVar9 + 0x810) = 0;
  memw();
  *(undefined4 *)(iVar9 + 0x814) = 0;
  memw();
  *(undefined4 *)(iVar9 + 0x81c) = 0;
  uVar5 = DAT_420001bc;
  memw();
  *(undefined4 *)(iVar9 + 0x18) = 0;
  memw();
  *(undefined4 *)(iVar9 + 0x14) = uVar5;
  memw();
  *(undefined4 *)(iVar9 + 0x18) = DAT_42001410;
  memw();
  if ((*(uint *)(iVar9 + 0x48) >> 3 & 3) != 2) {
    (*DAT_42000060)(PTR_DAT_420013fc);
    (*DAT_42000060)(PTR_s_This_dwc2_version_does_not_suppo_42001414);
    (*DAT_42000060)(PTR_DAT_42001404);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  memw();
  memw();
  *puVar8 = *puVar8 & DAT_42000aa0;
  memw();
  memw();
  *(uint *)(iVar9 + 8) = *(uint *)(iVar9 + 8) & 0xffffffe1;
  memw();
  memw();
  *(uint *)(iVar9 + 8) = *(uint *)(iVar9 + 8) | 0x2e;
  memw();
  *(undefined4 *)(iVar9 + 0x24) = 0x50;
  uVar3 = DAT_42000b50;
  memw();
  memw();
  *(uint *)(iVar9 + 0x28) = *(uint *)(iVar9 + 0x24) | DAT_42000b50;
  memw();
  memw();
  memw();
  *(uint *)(iVar9 + 0x104) = (*(uint *)(iVar9 + 0x28) >> 0x10) + *(int *)(iVar9 + 0x24) | uVar3;
  memw();
  memw();
  memw();
  memw();
  *(uint *)(iVar9 + 0x108) =
       (*(uint *)(iVar9 + 0x28) >> 0x10) + (*(uint *)(iVar9 + 0x104) >> 0x10) +
       *(int *)(iVar9 + 0x24) | uVar3;
  memw();
  memw();
  memw();
  memw();
  memw();
  *(uint *)(iVar9 + 0x10c) =
       (*(uint *)(iVar9 + 0x108) >> 0x10) +
       (*(uint *)(iVar9 + 0x28) >> 0x10) + (*(uint *)(iVar9 + 0x104) >> 0x10) +
       *(int *)(iVar9 + 0x24) | uVar3;
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  *(uint *)(iVar9 + 0x110) =
       (*(uint *)(iVar9 + 0x10c) >> 0x10) +
       (*(uint *)(iVar9 + 0x108) >> 0x10) +
       (*(uint *)(iVar9 + 0x28) >> 0x10) + (*(uint *)(iVar9 + 0x104) >> 0x10) +
       *(int *)(iVar9 + 0x24) | uVar3;
  memw();
  memw();
  memw();
  memw();
  *(uint *)(iVar9 + 0x114) =
       (*(uint *)(iVar9 + 0x28) >> 0x10) + *(int *)(iVar9 + 0x24) +
       (*(uint *)(iVar9 + 0x104) >> 0x10) | uVar3;
  memw();
  memw();
  memw();
  memw();
  *(uint *)(iVar9 + 0x118) =
       (*(uint *)(iVar9 + 0x28) >> 0x10) + *(int *)(iVar9 + 0x24) +
       (*(uint *)(iVar9 + 0x104) >> 0x10) | uVar3;
  memw();
  if (*(uint *)(iVar9 + 0x4c) >> 0x10 < 0xc0) {
    (*DAT_42000060)(PTR_DAT_420013fc,iVar9,uVar3,1);
    (*DAT_42000060)(PTR_s_Your_fifo_config_is_overflow__pl_42001418);
    (*DAT_42000060)(PTR_DAT_42001404);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  memw();
  local_30 = 0;
  do {
    memw();
    local_30 = local_30 + 1;
    memw();
    if (uVar2 < local_30) goto LAB_42015881;
    memw();
  } while (-1 < *(int *)(iVar9 + 0x10));
  memw();
  local_30 = 0;
  memw();
  *(undefined4 *)(iVar9 + 0x10) = 0x420;
  do {
    memw();
    local_30 = local_30 + 1;
    memw();
    if (uVar2 < local_30) break;
    memw();
  } while ((*(uint *)(iVar9 + 0x10) & 0x20) != 0);
LAB_42015881:
  memw();
  uStack_2c = 0;
  do {
    memw();
    uStack_2c = uStack_2c + 1;
    memw();
    if (uVar2 < uStack_2c) goto LAB_420158cc;
    memw();
  } while (-1 < *(int *)(iVar9 + 0x10));
  memw();
  uStack_2c = 0;
  memw();
  *(undefined4 *)(iVar9 + 0x10) = 0x10;
  do {
    memw();
    uStack_2c = uStack_2c + 1;
    memw();
    if (uVar2 < uStack_2c) goto LAB_420158cc;
    memw();
    uVar3 = *(uint *)(iVar9 + 0x10) & 0x10;
  } while ((*(uint *)(iVar9 + 0x10) & 0x10) != 0);
LAB_420158ce:
  memw();
  memw();
  *(uint *)(iVar9 + 8) = *(uint *)(iVar9 + 8) | 1;
  memw();
  memw();
  *(uint *)(iVar9 + 0x804) = *(uint *)(iVar9 + 0x804) & 0xfffffffd;
  return uVar3;
LAB_420158cc:
  uVar3 = 0xffffffff;
  goto LAB_420158ce;
}


