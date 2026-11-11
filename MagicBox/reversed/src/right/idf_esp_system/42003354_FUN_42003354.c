uint * FUN_42003354(uint param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)FUN_42003330(param_1,param_2);
  if ((puVar1 == (uint *)0x0) &&
     (puVar1 = (uint *)(*(code *)PTR_FUN_42000484)(0xc,DAT_42000424), puVar1 != (uint *)0x0)) {
    (*DAT_42000240)(puVar1,0,0xc);
    uVar2 = *puVar1 & DAT_4200047c | (param_1 & 0x1f) << 0x11;
    *puVar1 = uVar2;
    *puVar1 = uVar2 & DAT_42000480 | (param_2 & 1) << 0x10;
    FUN_420032e0(puVar1);
  }
  return puVar1;
}