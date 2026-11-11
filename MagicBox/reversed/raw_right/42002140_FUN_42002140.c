// 42002140  FUN_42002140  FUN_42002140  size=63

void FUN_42002140(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined1 in_PRID;
  
  uVar2 = rsr(in_PRID);
  uVar2 = uVar2 >> 0xd & 1;
  for (puVar3 = (undefined4 *)PTR_PTR_420001f8; puVar3 < DAT_420001fc; puVar3 = puVar3 + 2) {
    if (((*(ushort *)((int)puVar3 + 6) == param_1) &&
        (((uint)*(ushort *)(puVar3 + 1) & 1 << (sbyte)uVar2) != 0)) &&
       (iVar1 = (*(code *)*puVar3)(), iVar1 != 0)) {
      (*(code *)PTR_FUN_4200006c)();
    }
  }
  memw();
  *(undefined1 *)(DAT_42000200 + uVar2) = 1;
  return;
}


