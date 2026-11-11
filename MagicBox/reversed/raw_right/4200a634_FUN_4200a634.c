// 4200a634  FUN_4200a634  FUN_4200a634  size=86

undefined4 FUN_4200a634(undefined4 param_1,undefined4 param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  puVar1 = (uint *)FUN_42009fb8(param_1);
  puVar2 = (undefined4 *)(*(code *)PTR_FUN_420006f0)();
  if (puVar1 == (uint *)0x0) {
    *puVar2 = 2;
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = FUN_42009ed0(puVar1,param_1);
    if ((*(int *)(puVar1[1] + 0x2c) == 0) ||
       (pcVar4 = *(code **)(*(int *)(puVar1[1] + 0x2c) + 0x30), pcVar4 == (code *)0x0)) {
      *puVar2 = 0x58;
      uVar3 = 0xffffffff;
    }
    else if ((*puVar1 & 2) == 0) {
      uVar3 = (*pcVar4)(uVar3,param_2);
    }
    else {
      uVar3 = (*pcVar4)(puVar1[7],uVar3,param_2);
    }
  }
  return uVar3;
}


