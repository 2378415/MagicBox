// 4202d108  FUN_4202d108  FUN_4202d108  size=72

undefined4 FUN_4202d108(int param_1,uint param_2,int param_3,int *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = param_3 * 8 + *param_4;
  uVar2 = 0;
  if ((uVar1 < (param_2 & 0xffff) << 3) &&
     (((int)(uint)*(byte *)(param_1 + (uVar1 >> 3 & 0xff)) >> (uVar1 & 7) & 1U) != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}


