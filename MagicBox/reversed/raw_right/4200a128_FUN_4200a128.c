// 4200a128  FUN_4200a128  FUN_4200a128  size=108

undefined4 FUN_4200a128(undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  code *pcVar3;
  uint uVar4;
  
  puVar1 = (uint *)FUN_42009f90(param_2);
  if (puVar1 == (uint *)0x0) {
    uVar4 = 0xffffffff;
  }
  else if (param_2 < 0x40) {
    uVar4 = (uint)(byte)PTR_DAT_420009a0[param_2 * 3 + 2];
  }
  else {
    uVar4 = 0xffffffff;
  }
  if (puVar1 == (uint *)0x0 || (int)uVar4 < 0) {
    *param_1 = 9;
    uVar2 = 0xffffffff;
  }
  else {
    pcVar3 = *(code **)puVar1[1];
    if (pcVar3 == (code *)0x0) {
      *param_1 = 0x58;
      uVar2 = 0xffffffff;
    }
    else if ((*puVar1 & 2) == 0) {
      uVar2 = (*pcVar3)(uVar4,param_3,param_4);
    }
    else {
      uVar2 = (*pcVar3)(puVar1[7],uVar4,param_3,param_4);
    }
  }
  return uVar2;
}


