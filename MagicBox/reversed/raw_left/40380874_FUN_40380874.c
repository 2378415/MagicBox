// 40380874  FUN_40380874  FUN_40380874  size=56

void FUN_40380874(undefined4 *param_1,int param_2,int param_3,char param_4)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = (uint *)*param_1;
  memw();
  uVar3 = *puVar2;
  uVar1 = 1 << 0x20 - (0x20 - ((param_2 + -0xe) * -2 - param_3 & 0x1fU));
  if (param_4 == '\0') {
    memw();
    *puVar2 = uVar1 & uVar3 ^ uVar3;
  }
  else {
    memw();
    *puVar2 = uVar1 | uVar3;
  }
  return;
}


