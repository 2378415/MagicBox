// 4200c67c  FUN_4200c67c  FUN_4200c67c  size=123

undefined4 FUN_4200c67c(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  code *pcVar6;
  
  puVar1 = (uint *)FUN_4200c0d8(param_2);
  if (puVar1 == (uint *)0x0) {
    *param_1 = 2;
    return 0xffffffff;
  }
  uVar5 = *puVar1;
  if ((uVar5 & 4) == 0) {
    puVar2 = (uint *)FUN_4200c0d8(param_3);
    if (puVar1 != puVar2) {
      *param_1 = 0x12;
      return 0xffffffff;
    }
    if ((*puVar1 & 4) == 0) {
      uVar3 = FUN_4200bf38(puVar1,param_2);
      uVar4 = FUN_4200bf38(puVar1,param_3);
      if ((*(int *)(puVar1[1] + 0x2c) == 0) ||
         (pcVar6 = *(code **)(*(int *)(puVar1[1] + 0x2c) + 0xc), pcVar6 == (code *)0x0)) {
        *param_1 = 0x58;
        return 0xffffffff;
      }
      if ((uVar5 & 2) == 0) {
        uVar3 = (*pcVar6)(uVar3);
        return uVar3;
      }
      uVar3 = (*pcVar6)(puVar1[7],uVar3,uVar4);
      return uVar3;
    }
  }
  *param_1 = 0x1e;
  return 0xffffffff;
}


