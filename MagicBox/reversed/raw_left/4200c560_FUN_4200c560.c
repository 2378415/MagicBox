// 4200c560  FUN_4200c560  FUN_4200c560  size=78

undefined4 FUN_4200c560(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  puVar1 = (uint *)FUN_4200c0d8(param_2);
  if (puVar1 == (uint *)0x0) {
    *param_1 = 2;
  }
  else {
    uVar2 = FUN_4200bf38(puVar1,param_2);
    if ((*(undefined4 **)(puVar1[1] + 0x2c) != (undefined4 *)0x0) &&
       (pcVar3 = (code *)**(undefined4 **)(puVar1[1] + 0x2c), pcVar3 != (code *)0x0)) {
      if ((*puVar1 & 2) == 0) {
        uVar2 = (*pcVar3)(uVar2,param_3);
        return uVar2;
      }
      uVar2 = (*pcVar3)(puVar1[7],uVar2,param_3);
      return uVar2;
    }
    *param_1 = 0x58;
  }
  return 0xffffffff;
}


