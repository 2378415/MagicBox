// 4200a4d8  FUN_4200a4d8  FUN_4200a4d8  size=122

undefined4 FUN_4200a4d8(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  uint *puVar3;
  undefined4 uVar4;
  code *pcVar5;
  
  puVar1 = (uint *)FUN_42009fb8(param_2);
  if (puVar1 == (uint *)0x0) {
    *param_1 = 2;
    uVar2 = 0xffffffff;
  }
  else {
    puVar3 = (uint *)FUN_42009fb8(param_3);
    if (puVar1 == puVar3) {
      if ((*puVar3 & 4) == 0) {
        uVar2 = FUN_42009ed0(puVar1,param_2);
        uVar4 = FUN_42009ed0(puVar1,param_3);
        if ((*(int *)(puVar1[1] + 0x2c) == 0) ||
           (pcVar5 = *(code **)(*(int *)(puVar1[1] + 0x2c) + 4), pcVar5 == (code *)0x0)) {
          *param_1 = 0x58;
          uVar2 = 0xffffffff;
        }
        else if ((*puVar1 & 2) == 0) {
          uVar2 = (*pcVar5)(uVar2,uVar4);
        }
        else {
          uVar2 = (*pcVar5)(puVar1[7],uVar2,uVar4);
        }
      }
      else {
        *param_1 = 0x1e;
        uVar2 = 0xffffffff;
      }
    }
    else {
      *param_1 = 0x12;
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}


