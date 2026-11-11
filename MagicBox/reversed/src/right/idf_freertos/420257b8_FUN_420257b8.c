void FUN_420257b8(undefined4 param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = (uint *)FUN_420256e4(param_1);
  memw();
  uVar3 = *puVar1;
  uVar2 = FUN_42025224(param_1);
  memw();
  *puVar1 = uVar3 | uVar2;
  puVar1 = (uint *)FUN_42025750(param_1);
  memw();
  uVar3 = *puVar1;
  uVar2 = FUN_420254a8(param_1,1);
  memw();
  *puVar1 = uVar2 & uVar3 ^ uVar3;
  return;
}