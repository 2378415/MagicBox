undefined4 FUN_4200c6fc(undefined4 param_1,undefined4 param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  puVar1 = (uint *)FUN_4200c0d8(param_1);
  puVar2 = (undefined4 *)(*(code *)PTR_FUN_420008c8)();
  if (puVar1 == (uint *)0x0) {
    *puVar2 = 2;
  }
  else {
    uVar3 = FUN_4200bf38(puVar1,param_1);
    if ((*(int *)(puVar1[1] + 0x2c) != 0) &&
       (pcVar4 = *(code **)(*(int *)(puVar1[1] + 0x2c) + 0x30), pcVar4 != (code *)0x0)) {
      if ((*puVar1 & 2) == 0) {
        uVar3 = (*pcVar4)(uVar3,param_2);
        return uVar3;
      }
      uVar3 = (*pcVar4)(puVar1[7],uVar3,param_2);
      return uVar3;
    }
    *puVar2 = 0x58;
  }
  return 0xffffffff;
}