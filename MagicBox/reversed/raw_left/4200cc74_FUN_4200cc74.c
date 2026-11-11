// 4200cc74  FUN_4200cc74  FUN_4200cc74  size=162

int FUN_4200cc74(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 in_PRID;
  undefined4 local_30;
  int iStack_2c;
  int iStack_28;
  
  local_30 = 0;
  iStack_2c = 0;
  iStack_28 = 0;
  if (param_3 != (int *)0x0) {
    param_3[1] = 0;
  }
  (*(code *)PTR_FUN_42000c8c)(param_1,&local_30);
  *param_2 = param_1;
  param_2[1] = iStack_2c;
  param_2[2] = iStack_28;
  iVar1 = (*(code *)PTR_FUN_42000434)();
  if ((iVar1 == 0) || (*DAT_42000c84 != '\0')) {
    uVar4 = rsr(in_PRID);
    iVar1 = (*(code *)PTR_FUN_42000c90)(uVar4 >> 0xd & 1);
    if (param_1 == iVar1) {
      param_2[1] = *DAT_42000c88;
    }
  }
  iVar1 = FUN_4200d8d4(param_2);
  if (iVar1 != 0) {
    uVar4 = rsr(in_PRID);
    iVar2 = (*(code *)PTR_FUN_42000c90)(uVar4 >> 0xd & 1);
    if (param_1 == iVar2) {
      FUN_4200da84(param_1);
      iVar2 = (*(code *)PTR_FUN_42000434)();
      if ((iVar2 != 0) && (*DAT_42000c84 == '\0')) {
        if (param_3 != (int *)0x0) {
          iVar2 = param_2[2];
          iVar3 = param_2[1];
          *param_3 = iVar3;
          param_3[1] = (iVar2 + 3) - iVar3 & 0xfffffffc;
        }
        param_2[1] = *DAT_42000c88;
        iVar2 = FUN_4200d764();
        param_2[2] = iVar2;
      }
    }
  }
  return iVar1;
}


