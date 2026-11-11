undefined4 FUN_42015cf8(uint param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  
  uVar1 = param_2 & 0x7f;
  iVar3 = *(int *)((param_1 & 0xff) * 8 + DAT_420013e0 + 4);
  if ((param_2 & 0x80) == 0) {
    puVar2 = (uint *)(iVar3 + 0xb00 + uVar1 * 0x20);
    memw();
    if (-1 < (int)*puVar2) {
      if (uVar1 != 0) {
LAB_42015d44:
        memw();
        memw();
        *puVar2 = *puVar2 & DAT_420001bc;
        memw();
        memw();
        *puVar2 = *puVar2 | DAT_42000b54;
        return 0;
      }
      memw();
      memw();
      *puVar2 = *puVar2 | DAT_42000b54;
      goto LAB_42015d93;
    }
  }
  else {
    puVar2 = (uint *)(iVar3 + 0x900 + uVar1 * 0x20);
    memw();
    if (-1 < (int)*puVar2) {
      if (uVar1 != 0) goto LAB_42015d44;
      memw();
      memw();
      *puVar2 = *puVar2 | DAT_42000b54;
      goto LAB_42015d93;
    }
  }
  memw();
  memw();
  *puVar2 = *puVar2 | DAT_42000b54;
  if (uVar1 != 0) {
    return 0;
  }
LAB_42015d93:
  memw();
  *(undefined4 *)(iVar3 + 0xb10) = 0;
  memw();
  memw();
  *(uint *)(iVar3 + 0xb10) = *(uint *)(iVar3 + 0xb10) | DAT_42000a7c;
  memw();
  memw();
  *(uint *)(iVar3 + 0xb10) = *(uint *)(iVar3 + 0xb10) | 0x18;
  memw();
  memw();
  *(uint *)(iVar3 + 0xb10) = *(uint *)(iVar3 + 0xb10) | DAT_42001430;
  uVar1 = DAT_42001434;
  memw();
  *(uint *)(iVar3 + 0xb14) = (param_1 & 0xff) * 0x100 + DAT_420013f8;
  memw();
  memw();
  *(uint *)(iVar3 + 0xb00) = *(uint *)(iVar3 + 0xb00) | uVar1;
  return 0;
}