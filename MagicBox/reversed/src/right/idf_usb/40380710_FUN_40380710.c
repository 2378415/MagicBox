void FUN_40380710(undefined4 *param_1,int param_2,int param_3,char param_4)

{
  uint *puVar1;
  
  puVar1 = (uint *)*param_1;
  if (param_4 == '\0') {
    memw();
    memw();
    *puVar1 = 1 << 0x20 - (0x20 - ((param_2 + -0xe) * -2 - param_3 & 0x1fU)) & *puVar1 ^ *puVar1;
  }
  else {
    memw();
    memw();
    *puVar1 = *puVar1 | 1 << 0x20 - (0x20 - ((param_2 + -0xe) * -2 - param_3 & 0x1fU));
  }
  return;
}