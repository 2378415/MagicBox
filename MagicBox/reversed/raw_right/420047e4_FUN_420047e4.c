// 420047e4  FUN_420047e4  FUN_420047e4  size=188
// strings: pf7@

int FUN_420047e4(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  (*(code *)PTR_FUN_42000140)(0x19);
  if (param_1 == 2) {
    if (param_2 == 0) {
      uVar2 = 0x56;
      uVar3 = 0;
    }
    else if (param_2 == 1) {
      uVar2 = 0x5a;
      uVar3 = 0;
    }
    else {
      uVar2 = 99;
      uVar3 = 7;
    }
    iVar1 = FUN_42005ab0(uVar3);
    if (iVar1 != 0) {
      return iVar1;
    }
    (*DAT_4200005c)(param_2,uVar2,0x19);
  }
  else if (param_1 == 4) {
    if (param_2 == 0) {
      uVar2 = 0x57;
      uVar3 = 0;
    }
    else if (param_2 == 1) {
      uVar2 = 0x5b;
      uVar3 = 0;
    }
    else {
      uVar2 = 99;
      uVar3 = 7;
    }
    iVar1 = FUN_42005ab0(uVar3);
    if (iVar1 != 0) {
      return iVar1;
    }
    (*DAT_4200005c)(param_2,uVar2,0x19);
  }
  else {
    if (param_1 != 1) {
      return DAT_420005b4;
    }
    if (param_2 == 0) {
      uVar2 = 0x55;
      uVar3 = 0;
    }
    else if (param_2 == 1) {
      uVar2 = 0x59;
      uVar3 = 0;
    }
    else {
      uVar2 = 99;
      uVar3 = 0xffffffff;
    }
    iVar1 = FUN_42005ab0(uVar3);
    if (iVar1 != 0) {
      return iVar1;
    }
    (*DAT_4200005c)(param_2,uVar2,0x19);
  }
  (*(code *)PTR_FUN_42000144)(0x19);
  return 0;
}


