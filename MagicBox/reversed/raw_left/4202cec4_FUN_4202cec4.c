// 4202cec4  FUN_4202cec4  FUN_4202cec4  size=68

void FUN_4202cec4(undefined4 *param_1,byte *param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = (uint *)*param_1;
  memw();
  uVar2 = -((puVar3[7] >> 0x10 & 0x3ff) - 0x80);
  uVar1 = uVar2 & 0xffff;
  if (param_3 < uVar1) {
    uVar1 = param_3;
    uVar2 = param_3;
  }
  *param_4 = uVar1;
  if ((uVar2 & 0xffff) != 0) {
    memw();
    *puVar3 = (uint)*param_2;
  }
  return;
}


