void FUN_4201ac44(uint param_1)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_420019d4,0xffffffff);
  iVar2 = DAT_420019d8;
  uVar3 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
  if ((param_1 & 0x20) != 0) {
    uVar3 = 0;
  }
  uVar3 = uVar3 & *(uint *)(DAT_420019d8 + 0x18) ^ *(uint *)(DAT_420019d8 + 0x18);
  *(undefined1 *)(DAT_420019d8 + param_1) = 0;
  *(uint *)(iVar2 + 0x18) = uVar3;
  puVar1 = PTR_DAT_4200167c;
  if (uVar3 == 0) {
    (*(code *)PTR_FUN_420004dc)(PTR_DAT_4200167c,0xffffffff);
    memw();
    memw();
    *(uint *)(DAT_420019dc + 0x104) = *(uint *)(DAT_420019dc + 0x104) & 0x7fffffff;
    (*(code *)PTR_FUN_420004e0)(puVar1);
  }
  (*(code *)PTR_FUN_420004e0)(PTR_DAT_420019d4);
  return;
}