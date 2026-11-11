undefined4 FUN_4037c0c8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = -(DAT_403745dc + -1) & 0xff;
  if (((-(DAT_40374d80 + -1) & 0xffU) == 0 && (-(param_1 + DAT_40374d84 + -1) & 0xffU) == 0) &&
     (uVar3 == 0)) {
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_403789f4(param_1,uVar3,param_1 + DAT_403745d8);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}