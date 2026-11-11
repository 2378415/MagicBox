// 40382f5c  FUN_40382f5c  FUN_40382f5c  size=114

int FUN_40382f5c(undefined4 *param_1,char param_2)

{
  int iVar1;
  undefined1 auStack_40 [20];
  undefined2 uStack_2c;
  char acStack_24 [36];
  
  iVar1 = (**(code **)(param_1[1] + 0x54))(param_1,**(undefined4 **)(param_1[1] + 4));
  (*DAT_4037448c)(auStack_40,0,0x1c);
  if (iVar1 == 0 || iVar1 == 0x106) {
    if (param_2 == '\0') {
      uStack_2c = 0xf906;
    }
    else {
      uStack_2c = 0xfb04;
    }
    (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,auStack_40);
  }
  iVar1 = (**(code **)(param_1[1] + 0x28))(param_1,acStack_24);
  if ((iVar1 == 0) && (acStack_24[0] != param_2)) {
    iVar1 = 0x105;
  }
  return iVar1;
}


