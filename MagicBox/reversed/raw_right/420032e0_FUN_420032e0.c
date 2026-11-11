// 420032e0  FUN_420032e0  FUN_420032e0  size=79

void FUN_420032e0(uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar1 = (uint *)*DAT_42000478;
  puVar3 = (uint *)0x0;
  while (((puVar2 = puVar1, puVar2 != (uint *)0x0 &&
          ((*puVar2 >> 0x10 & 1) <= (*param_1 >> 0x10 & 1))) &&
         ((((*puVar2 ^ *param_1) & 0x10000) != 0 ||
          ((*puVar2 >> 0x11 & 0x1f) < (*param_1 >> 0x11 & 0x1f)))))) {
    puVar3 = puVar2;
    puVar1 = (uint *)puVar2[2];
  }
  if (((uint *)*DAT_42000478 == (uint *)0x0) || (puVar3 == (uint *)0x0)) {
    param_1[2] = (uint)puVar2;
    *DAT_42000478 = (uint)param_1;
  }
  else {
    puVar3[2] = (uint)param_1;
    param_1[2] = (uint)puVar2;
  }
  return;
}


