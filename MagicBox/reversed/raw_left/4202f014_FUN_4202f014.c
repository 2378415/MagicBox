// 4202f014  FUN_4202f014  FUN_4202f014  size=60
// strings: lr7@< | lr7@

undefined * FUN_4202f014(uint param_1,undefined *param_2,int param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined1 in_PRID;
  
  puVar1 = PTR_FUN_42001fc4;
  if ((param_1 < 0x20) && ((byte)PTR_DAT_42001fc8[param_1] < 4)) {
    uVar4 = rsr(in_PRID);
    iVar5 = (uVar4 >> 0xd & 1) + param_1 * 2;
    puVar3 = (undefined4 *)(PTR_PTR_42001fc0 + iVar5 * 8);
    if (param_2 == (undefined *)0x0) {
      param_3 = iVar5;
    }
    puVar2 = (undefined *)*puVar3;
    if (param_2 == (undefined *)0x0) {
      param_2 = PTR_FUN_42001fc4;
    }
    puVar3[1] = param_3;
    *puVar3 = param_2;
    if (puVar2 != puVar1) {
      return puVar2;
    }
  }
  return (undefined *)0x0;
}


