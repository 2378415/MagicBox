// 420042b4  FUN_420042b4  FUN_420042b4  size=316
// strings: block < ETS_EFUSE_BLOCK_MAX

void FUN_420042b4(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = DAT_420004f4;
  iVar1 = DAT_420004f0;
  memw();
  memw();
  *(uint *)(DAT_420004f0 + 0x1e8) = *(uint *)(DAT_420004f0 + 0x1e8) | DAT_420004f4;
  uVar3 = DAT_420004f8;
  memw();
  memw();
  *(uint *)(iVar1 + 0x1e8) = *(uint *)(iVar1 + 0x1e8) & 0xffffff00 | 0x28;
  uVar4 = DAT_420004fc;
  memw();
  memw();
  *(uint *)(iVar1 + 500) = *(uint *)(iVar1 + 500) & uVar3 | DAT_420004fc;
  memw();
  memw();
  *(uint *)(iVar1 + 0x1f8) = *(uint *)(iVar1 + 0x1f8) & 0xffff0000 | 400;
  memw();
  memw();
  *(uint *)(iVar1 + 0x1cc) = *(uint *)(iVar1 + 0x1cc) & 0xffff0000 | DAT_42000508;
  if (10 < param_1) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s__IDF_components_hal_esp32s3_incl_42000514,0x91,PTR_DAT_42000510,
               PTR_s_block_<_ETS_EFUSE_BLOCK_MAX_4200050c);
  }
  memw();
  *(uint *)(iVar1 + 0x1d4) = param_1 << 2 | 2;
  do {
    memw();
  } while ((*(uint *)(iVar1 + 0x1d4) & 2) != 0);
  (*DAT_42000504)();
  memw();
  memw();
  *(uint *)(iVar1 + 0x1e8) = *(uint *)(iVar1 + 0x1e8) | uVar2;
  memw();
  memw();
  *(uint *)(iVar1 + 0x1e8) = *(uint *)(iVar1 + 0x1e8) & 0xffffff00 | 0x28;
  memw();
  memw();
  *(uint *)(iVar1 + 500) = *(uint *)(iVar1 + 500) & uVar3 | uVar4;
  memw();
  memw();
  *(uint *)(iVar1 + 0x1f8) = *(uint *)(iVar1 + 0x1f8) & 0xffff0000 | 400;
  memw();
  memw();
  *(uint *)(iVar1 + 0x1cc) = *(uint *)(iVar1 + 0x1cc) & 0xffff0000 | DAT_42000500;
  memw();
  memw();
  *(uint *)(iVar1 + 0x1d4) = *(uint *)(iVar1 + 0x1d4) | 1;
  do {
    memw();
  } while ((*(uint *)(iVar1 + 0x1d4) & 1) != 0);
  do {
    memw();
  } while ((*(uint *)(iVar1 + 0x1d4) & 1) != 0);
  return;
}


