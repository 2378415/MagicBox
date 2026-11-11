// 40381e70  FUN_40381e70  FUN_40381e70  size=55

void FUN_40381e70(uint *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  FUN_4037bf20();
  FUN_4037bf44(PTR_DAT_403752c8,0xffffffff);
  memw();
  memw();
  memw();
  *param_1 = *param_1 | param_3;
  memw();
  param_1[1] = param_1[1] | param_4;
  FUN_4037bf20();
  FUN_4037c094(PTR_DAT_403752c8);
  return;
}


