// 403823f8  FUN_403823f8  FUN_403823f8  size=85

int FUN_403823f8(undefined4 *param_1)

{
  int iVar1;
  undefined1 auStack_40 [20];
  undefined2 uStack_2c;
  
  (*DAT_4037448c)(auStack_40,0,0x1c);
  uStack_2c = 0x66;
  iVar1 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,auStack_40);
  if (iVar1 == 0) {
    (*DAT_4037448c)(auStack_40,0,0x1c);
    uStack_2c = 0x99;
    iVar1 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,auStack_40);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(param_1[1] + 0x54))(param_1,**(undefined4 **)(param_1[1] + 4));
    }
  }
  return iVar1;
}


