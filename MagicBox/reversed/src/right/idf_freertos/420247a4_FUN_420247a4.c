uint FUN_420247a4(int param_1,char param_2,uint param_3,int *param_4)

{
  uint uVar1;
  
  uVar1 = ((param_3 + param_1) - 1) / param_3 & 0xffff;
  if (0x100 < uVar1) {
    uVar1 = 0x100;
  }
  if (param_1 == 0) {
    uVar1 = 1;
  }
  if (param_2 < '\0') {
    param_1 = uVar1 * param_3;
  }
  *param_4 = param_1;
  return uVar1 & 0xff;
}