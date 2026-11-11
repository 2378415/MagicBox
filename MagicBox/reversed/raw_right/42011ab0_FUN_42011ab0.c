// 42011ab0  FUN_42011ab0  FUN_42011ab0  size=56

undefined4 * FUN_42011ab0(int param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined4 *)(PTR_DAT_42000520 + param_1 * 0x38);
  memw();
  uVar2 = *(uint *)*puVar1;
  memw();
  *(uint *)*puVar1 =
       3 << 0x20 - (0x20 - (puVar1[2] & 0x1f)) & uVar2 ^ uVar2 |
       (param_2 & 3) << 0x20 - (0x20 - (puVar1[2] & 0x1f));
  return puVar1;
}


