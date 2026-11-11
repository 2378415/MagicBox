// 42004b48  FUN_42004b48  FUN_42004b48  size=343

int FUN_42004b48(uint param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_2 >> 1 & 1;
  uVar2 = param_2 >> 2 & 1;
  if (param_1 == 0x40) {
    FUN_420045dc(param_2 & 1,uVar3);
    iVar1 = 0;
  }
  else if (param_1 < 0x41) {
    if (param_1 == 8) {
      FUN_42003f68(param_2 & 1,uVar3,uVar2);
      iVar1 = 0;
    }
    else if (param_1 < 9) {
      if (param_1 == 2) {
        FUN_42003ee8(param_2 & 1,uVar3,uVar2);
        iVar1 = 0;
      }
      else if (param_1 == 4) {
        FUN_42003f28(param_2 & 1,uVar3,uVar2);
        iVar1 = 0;
      }
      else if (param_1 == 1) {
        FUN_42003eb0(param_2 & 1,uVar3,uVar2);
        iVar1 = 0;
      }
      else {
        iVar1 = 0x106;
      }
    }
    else if (param_1 == 0x10) {
      FUN_42004570(param_2 & 1,uVar3);
      iVar1 = 0;
    }
    else if (param_1 == 0x20) {
      FUN_420045a4(param_2 & 1,uVar3);
      iVar1 = 0;
    }
    else {
      iVar1 = 0x106;
    }
  }
  else if (param_1 == 0x200) {
    iVar1 = FUN_42004798(param_3);
    if (iVar1 == 0) {
      FUN_420041ac(param_3,param_2 & 1,uVar3,uVar2,1,2);
      iVar1 = FUN_42005ab0();
    }
  }
  else if (param_1 < 0x201) {
    if (param_1 == 0x80) {
      FUN_42004614(param_2 & 1,uVar3);
      iVar1 = 0;
    }
    else if (param_1 == 0x100) {
      iVar1 = FUN_42004798(param_3);
      if (iVar1 == 0) {
        FUN_420041ac(param_3,param_2 & 1,uVar3,uVar2,1);
        iVar1 = FUN_42005ab0();
      }
    }
    else {
      iVar1 = 0x106;
    }
  }
  else if (param_1 == 0x400) {
    FUN_42003d68(param_2 & 1,uVar3,uVar2);
    iVar1 = 0;
  }
  else if (param_1 == DAT_420004fc) {
    FUN_42003da8(param_2 & 1,uVar3,uVar2);
    iVar1 = 0;
  }
  else {
    iVar1 = 0x106;
  }
  return iVar1;
}


