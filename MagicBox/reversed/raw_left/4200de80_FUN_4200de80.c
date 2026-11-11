// 4200de80  FUN_4200de80  FUN_4200de80  size=74

void FUN_4200de80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 char *param_5,uint param_6)

{
  int iVar1;
  undefined1 auStack_60 [96];
  
  if ((((param_6 != 0) && (2 < param_6)) && (*param_5 == '\'')) && (param_5[param_6 - 1] == '\'')) {
    param_6 = param_6 - 2;
    iVar1 = (param_6 < 0x3f) * param_6 + (uint)(param_6 >= 0x3f) * 0x3f;
    (*DAT_42000064)(auStack_60,param_5 + 1,iVar1);
    auStack_60[iVar1] = 0;
    FUN_42010fdc(param_3,auStack_60,iVar1);
    FUN_420143e8(param_1,param_2,0);
  }
  return;
}


