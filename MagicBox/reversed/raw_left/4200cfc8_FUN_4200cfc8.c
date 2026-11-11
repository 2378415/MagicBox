// 4200cfc8  FUN_4200cfc8  FUN_4200cfc8  size=176

void FUN_4200cfc8(int *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_40 [4];
  int *piStack_30;
  
  local_40[0] = 0;
  uVar1 = FUN_4202d058();
  piVar3 = param_1 + 10;
  if ((char)param_1[9] != '\0') {
    iVar2 = FUN_4200ce40(*DAT_42000cc0 + *param_1,param_1 + 1,0x20);
    if (iVar2 != 0) {
      return;
    }
    piStack_30 = param_1 + 10;
    FUN_4200d708(piStack_30,param_1 + 1,0x20);
    *(undefined1 *)(param_1 + 9) = 0;
    *param_1 = *param_1 + 0x20;
    piVar3 = piStack_30;
  }
  FUN_4202d070(piVar3,local_40);
  if (uVar1 < 0x20) {
    piVar3 = param_1 + 1;
    (*DAT_42000064)(piVar3,local_40[0],uVar1);
    (*DAT_42000094)((int)piVar3 + uVar1,0,-(uVar1 - 0x20));
    iVar2 = FUN_4200ce40(*DAT_42000cc0 + *param_1,piVar3,0x20);
  }
  else {
    if ((uVar1 & 0xf) != 0) {
      (*(code *)PTR_FUN_42000330)();
    }
    iVar2 = FUN_4200ce40(*DAT_42000cc0 + *param_1,local_40[0],uVar1);
  }
  if (iVar2 == 0) {
    *param_1 = *param_1 + uVar1;
  }
  return;
}


