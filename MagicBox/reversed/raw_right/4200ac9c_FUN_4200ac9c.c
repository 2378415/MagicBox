// 4200ac9c  FUN_4200ac9c  FUN_4200ac9c  size=122

int FUN_4200ac9c(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 in_PRID;
  undefined1 auStack_30 [4];
  int iStack_2c;
  int iStack_28;
  
  (*DAT_42000240)(auStack_30,0,0xc);
  if (param_3 != 0) {
    *(undefined4 *)(param_3 + 4) = 0;
  }
  (*(code *)PTR_FUN_420009d8)(param_1,auStack_30);
  *param_2 = param_1;
  param_2[1] = iStack_2c;
  param_2[2] = iStack_28;
  iVar1 = FUN_4200ac78();
  if (iVar1 == 0) {
    uVar3 = rsr(in_PRID);
    iVar1 = (*(code *)PTR_FUN_420009dc)(uVar3 >> 0xd & 1);
    if (param_1 == iVar1) {
      param_2[1] = *DAT_420009c0;
    }
  }
  iVar1 = FUN_4200bd80(param_2);
  if (iVar1 != 0) {
    uVar3 = rsr(in_PRID);
    iVar2 = (*(code *)PTR_FUN_420009dc)(uVar3 >> 0xd & 1);
    if (param_1 == iVar2) {
      FUN_4200be00(param_1);
      iVar2 = FUN_4200ac78();
      if (iVar2 != 0) {
        FUN_4200abfc(param_2,param_3);
        iVar1 = iVar2;
      }
    }
  }
  return iVar1;
}


