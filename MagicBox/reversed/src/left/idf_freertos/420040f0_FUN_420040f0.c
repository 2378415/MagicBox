undefined4 FUN_420040f0(undefined4 param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 in_PRID;
  
  uVar3 = rsr(in_PRID);
  uVar3 = uVar3 >> 0xd & 1;
  uVar2 = 0x102;
  if (uVar3 < 2) {
    (*(code *)PTR_FUN_420004dc)(PTR_DAT_420004d8,0xffffffff);
    puVar1 = PTR_DAT_420004d8;
    if (*(int *)(DAT_420004e4 + uVar3 * 0x20) == 0) {
      *(undefined4 *)(uVar3 * 0x20 + DAT_420004e4) = param_1;
      (*(code *)PTR_FUN_420004e0)(puVar1);
      uVar2 = 0;
    }
    else {
      (*(code *)PTR_FUN_420004e0)(PTR_DAT_420004d8);
      uVar2 = 0x101;
    }
  }
  return uVar2;
}