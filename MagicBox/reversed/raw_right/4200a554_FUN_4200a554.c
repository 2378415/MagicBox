// 4200a554  FUN_4200a554  FUN_4200a554  size=84

undefined4 FUN_4200a554(undefined4 *param_1,undefined4 param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  code *pcVar4;
  
  puVar1 = (uint *)FUN_42009fb8(param_2);
  if (puVar1 == (uint *)0x0) {
    *param_1 = 2;
    uVar2 = 0xffffffff;
  }
  else {
    uVar3 = *puVar1;
    if ((uVar3 & 4) == 0) {
      uVar2 = FUN_42009ed0(puVar1,param_2);
      if ((*(int *)(puVar1[1] + 0x2c) == 0) ||
         (pcVar4 = *(code **)(*(int *)(puVar1[1] + 0x2c) + 8), pcVar4 == (code *)0x0)) {
        *param_1 = 0x58;
        uVar2 = 0xffffffff;
      }
      else if ((uVar3 & 2) == 0) {
        uVar2 = (*pcVar4)();
      }
      else {
        uVar2 = (*pcVar4)(puVar1[7],uVar2);
      }
    }
    else {
      *param_1 = 0x1e;
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}


