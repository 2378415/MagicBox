// 42013f04  FUN_42013f04  FUN_42013f04  size=68

undefined4 FUN_42013f04(char *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*DAT_4200099c)(param_1 + 8,param_2 + 8,0xf);
  if (iVar1 == 0) {
    if (*param_1 == *(char *)(param_2 + 0x18)) {
      if ((uint)(byte)param_1[3] < (uint)*(byte *)(param_2 + 0x1a)) {
        uVar2 = 0;
      }
      else if ((uint)(byte)param_1[3] <
               (uint)*(byte *)(param_2 + 0x1a) + (uint)*(byte *)(param_2 + 0x19)) {
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


