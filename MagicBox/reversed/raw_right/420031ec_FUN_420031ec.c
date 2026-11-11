// 420031ec  FUN_420031ec  FUN_420031ec  size=224

void FUN_420031ec(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  
  iVar2 = (*(code *)PTR_FUN_42000394)();
  if (iVar2 == 0) {
    (*(code *)PTR_FUN_420003a8)(PTR_DAT_4200046c,0xffffffff);
  }
  else {
    (*(code *)PTR_FUN_420003a8)(PTR_DAT_4200046c,0xffffffff);
  }
  uVar3 = FUN_420031dc();
  if ((uVar3 == 0) ||
     ((*PTR_DAT_42000470 != '\0' &&
      (uVar5 = DAT_42000464[5], uVar4 = FUN_420031b8(), uVar5 != uVar4)))) {
    (*DAT_42000240)(DAT_42000464,0,0x18);
  }
  *PTR_DAT_42000470 = 0;
  uVar8 = (*(code *)PTR_FUN_42000474)();
  puVar1 = DAT_42000464;
  uVar4 = (int)((ulonglong)uVar8 >> 0x20) - DAT_42000464[3];
  if ((uint)uVar8 < DAT_42000464[2]) {
    uVar4 = uVar4 - 1;
  }
  uVar5 = (uint)uVar8 - DAT_42000464[2];
  uVar6 = (uint)((ulonglong)uVar3 * (ulonglong)uVar5 >> 0x20);
  uVar7 = uVar3 * uVar4 * 0x2000;
  iVar2 = (uVar6 >> 0x13) +
          (uVar3 * uVar4 >> 0x13 | (int)((ulonglong)uVar3 * (ulonglong)uVar4 >> 0x20) << 0xd);
  uVar3 = (uVar6 << 0xd | uVar3 * uVar5 >> 0x13) + uVar7;
  if (uVar3 < uVar7) {
    iVar2 = iVar2 + 1;
  }
  uVar4 = DAT_42000464[1] + iVar2;
  if (*DAT_42000464 + uVar3 < uVar3) {
    uVar4 = uVar4 + 1;
  }
  *DAT_42000464 = *DAT_42000464 + uVar3;
  puVar1[1] = uVar4;
  *(undefined8 *)(puVar1 + 2) = uVar8;
  uVar3 = FUN_420031b8();
  puVar1[5] = uVar3;
  iVar2 = (*(code *)PTR_FUN_42000394)();
  if (iVar2 == 0) {
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_4200046c);
  }
  else {
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_4200046c);
  }
  return;
}


