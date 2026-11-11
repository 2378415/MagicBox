undefined4 FUN_4200c628(undefined4 *param_1,undefined4 param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  code *pcVar4;
  
  puVar1 = (uint *)FUN_4200c0d8(param_2);
  if (puVar1 == (uint *)0x0) {
    *param_1 = 2;
  }
  else {
    uVar3 = *puVar1;
    if ((uVar3 & 4) == 0) {
      uVar2 = FUN_4200bf38(puVar1,param_2);
      if ((*(int *)(puVar1[1] + 0x2c) != 0) &&
         (pcVar4 = *(code **)(*(int *)(puVar1[1] + 0x2c) + 8), pcVar4 != (code *)0x0)) {
        if ((uVar3 & 2) == 0) {
          uVar2 = (*pcVar4)(uVar2,uVar2);
          return uVar2;
        }
        uVar2 = (*pcVar4)(puVar1[7]);
        return uVar2;
      }
      *param_1 = 0x58;
    }
    else {
      *param_1 = 0x1e;
    }
  }
  return 0xffffffff;
}