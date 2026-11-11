// 4200d0b0  FUN_4200d0b0  FUN_4200d0b0  size=43

void FUN_4200d0b0(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = (*DAT_4200030c)(param_2);
  param_1[1] = param_1[1] + iVar1;
  if (((char)param_1[2] == '\0') && (iVar1 = FUN_4200ceb4(iVar2 + 0x54,param_2,iVar1), iVar1 != 0))
  {
    param_1[1] = 0;
  }
  return;
}


