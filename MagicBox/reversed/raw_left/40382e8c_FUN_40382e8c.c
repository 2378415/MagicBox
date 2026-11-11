// 40382e8c  FUN_40382e8c  FUN_40382e8c  size=106

int FUN_40382e8c(undefined4 *param_1,char param_2)

{
  int iVar1;
  undefined4 local_40 [5];
  undefined2 uStack_2c;
  char acStack_24 [36];
  
  iVar1 = (**(code **)(param_1[1] + 0x54))(param_1,**(undefined4 **)(param_1[1] + 4));
  local_40[0] = 0;
  if ((iVar1 == 0) || (iVar1 == 0x106 || iVar1 == 0)) {
    uStack_2c = (short)DAT_40375358;
    if (param_2 == '\0') {
      uStack_2c = (short)DAT_4037535c;
    }
    (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,local_40);
  }
  iVar1 = (**(code **)(param_1[1] + 0x28))(param_1,acStack_24);
  if ((iVar1 == 0) && (acStack_24[0] != param_2)) {
    iVar1 = 0x105;
  }
  return iVar1;
}


