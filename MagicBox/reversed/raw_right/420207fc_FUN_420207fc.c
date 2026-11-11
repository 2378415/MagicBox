// 420207fc  FUN_420207fc  FUN_420207fc  size=95

undefined8 FUN_420207fc(int param_1,uint param_2,int *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = CONCAT44(param_2,param_1);
  *param_3 = 0;
  uVar1 = param_2 & 0x7fffffff;
  if ((uVar1 <= DAT_42001210) && (uVar1 != 0 || param_1 != 0)) {
    if ((param_2 >> 0x14 & 0x7ff) == 0) {
      uVar2 = (*DAT_42001220)(param_1,param_2,0,0x43500000);
      uVar1 = (uint)((ulonglong)uVar2 >> 0x20) & 0x7fffffff;
      *param_3 = -0x36;
    }
    param_1 = (int)uVar2;
    *param_3 = *param_3 + ((int)uVar1 >> 0x14) + -0x3fe;
    param_2 = (uint)((ulonglong)uVar2 >> 0x20) & DAT_420012a4 | 0x3fe00000;
  }
  return CONCAT44(param_2,param_1);
}


