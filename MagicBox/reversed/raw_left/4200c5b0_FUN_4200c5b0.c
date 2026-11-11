// 4200c5b0  FUN_4200c5b0  FUN_4200c5b0  size=116

undefined4 FUN_4200c5b0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  
  puVar1 = (uint *)FUN_4200c0d8(param_2);
  if (puVar1 == (uint *)0x0) {
    *param_1 = 2;
  }
  else {
    puVar2 = (uint *)FUN_4200c0d8(param_3);
    if (puVar1 == puVar2) {
      if ((*puVar1 & 4) == 0) {
        uVar3 = FUN_4200bf38(puVar1,param_2);
        uVar4 = FUN_4200bf38(puVar1,param_3);
        if ((*(int *)(puVar1[1] + 0x2c) != 0) &&
           (pcVar5 = *(code **)(*(int *)(puVar1[1] + 0x2c) + 4), pcVar5 != (code *)0x0)) {
          if ((*puVar1 & 2) == 0) {
            uVar3 = (*pcVar5)(uVar3);
            return uVar3;
          }
          uVar3 = (*pcVar5)(puVar1[7],uVar3,uVar4);
          return uVar3;
        }
        *param_1 = 0x58;
      }
      else {
        *param_1 = 0x1e;
      }
    }
    else {
      *param_1 = 0x12;
    }
  }
  return 0xffffffff;
}


