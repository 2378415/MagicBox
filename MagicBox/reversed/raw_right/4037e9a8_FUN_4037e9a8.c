// 4037e9a8  FUN_4037e9a8  FUN_4037e9a8  size=37

undefined4 FUN_4037e9a8(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_4037c0c8(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if (param_2 == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    *param_2 = (int)param_1;
    param_2[1] = *param_1;
    param_2[2] = param_1[0x12];
    uVar2 = 1;
  }
  return uVar2;
}


