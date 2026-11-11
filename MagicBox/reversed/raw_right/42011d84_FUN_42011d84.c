// 42011d84  FUN_42011d84  FUN_42011d84  size=36

undefined4 * FUN_42011d84(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)PTR_FUN_420006e0)(0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[3] = *DAT_42000e10;
    puVar1[4] = 0;
  }
  return puVar1;
}


