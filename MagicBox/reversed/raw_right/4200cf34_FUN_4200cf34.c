// 4200cf34  FUN_4200cf34  FUN_4200cf34  size=456

undefined4 FUN_4200cf34(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  
  (*DAT_42000240)((uint)*(byte *)(param_1 + 0xc) * 0xc4 + DAT_42000af8,0,0xc4);
  for (uVar3 = 0; uVar3 < 8; uVar3 = uVar3 + 1 & 0xff) {
    bVar1 = *(byte *)(param_1 + 0xc);
    uVar2 = FUN_4200d77c(0);
    *(undefined4 *)(DAT_42000af8 + uVar3 * 0x18 + (uint)bVar1 * 0xc4 + 0x10) = uVar2;
  }
  FUN_4200d6c8(param_1);
  iVar5 = *(int *)(param_1 + 8);
  memw();
  if ((*(uint *)(iVar5 + 0x48) >> 3 & 3) != 2) {
    (*DAT_42000634)(PTR_DAT_42000b00);
    (*DAT_42000634)(PTR_s_This_dwc2_version_does_not_suppo_42000b18);
    (*DAT_42000634)(PTR_DAT_42000b08);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  memw();
  if (*(uint *)(iVar5 + 0x4c) >> 0x10 < 200) {
    (*DAT_42000634)(PTR_DAT_42000b00);
    (*DAT_42000634)(PTR_s_Your_fifo_config_is_overflow__pl_42000b1c);
    (*DAT_42000634)(PTR_DAT_42000b08);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  memw();
  memw();
  *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) & 0xfffffffe;
  iVar5 = *(int *)(param_1 + 8);
  uVar2 = FUN_420247d0(iVar5);
  memw();
  *(undefined4 *)(iVar5 + 0x38) = uVar2;
  FUN_4200c0ac(param_1);
  FUN_4200c85c(param_1,1);
  FUN_4200da94(0x32);
  uVar3 = 0;
  memw();
  *(undefined4 *)(*(int *)(param_1 + 8) + 0xe00) = 0;
  puVar4 = (uint *)(*(int *)(param_1 + 8) + 0x400);
  memw();
  memw();
  *puVar4 = *puVar4 & 0xfffffffb;
  for (; uVar3 < 8; uVar3 = uVar3 + 1 & 0xff) {
    memw();
    *(undefined4 *)(*(int *)(param_1 + 8) + uVar3 * 0x20 + 0x508) = 0xffffffff;
    memw();
    *(undefined4 *)(uVar3 * 0x20 + *(int *)(param_1 + 8) + 0x50c) = 0;
  }
  memw();
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x18) = 0;
  memw();
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x14) = 0xffffffff;
  memw();
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x24) = 0x50;
  memw();
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x28) = DAT_42000b20;
  memw();
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x100) = DAT_42000b24;
  FUN_4200c130(param_1,0x10);
  uVar2 = FUN_4200c0cc(param_1);
  memw();
  memw();
  *(uint *)(*(int *)(param_1 + 8) + 8) = *(uint *)(*(int *)(param_1 + 8) + 8) & 0xffffffe1;
  memw();
  memw();
  *(uint *)(*(int *)(param_1 + 8) + 8) = *(uint *)(*(int *)(param_1 + 8) + 8) | 0xe;
  memw();
  memw();
  *(uint *)(*(int *)(param_1 + 8) + 8) = *(uint *)(*(int *)(param_1 + 8) + 8) | 0x20;
  memw();
  memw();
  *(uint *)(*(int *)(param_1 + 8) + 0x18) = *(uint *)(*(int *)(param_1 + 8) + 0x18) | DAT_42000b28;
  FUN_4200c198(param_1,1);
  FUN_4200da94(200);
  memw();
  memw();
  *(uint *)(*(int *)(param_1 + 8) + 8) = *(uint *)(*(int *)(param_1 + 8) + 8) | 1;
  return uVar2;
}


