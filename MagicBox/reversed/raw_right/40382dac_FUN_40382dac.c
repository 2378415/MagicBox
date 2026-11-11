// 40382dac  FUN_40382dac  FUN_40382dac  size=152

int FUN_40382dac(int param_1,code *param_2,code *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint local_30 [12];
  
  if (*(int *)(param_1 + 0x10) - 4U < 2) {
    iVar1 = (*param_3)(param_1,local_30);
    if ((iVar1 == 0) && (uVar2 = local_30[0] | param_4, (~local_30[0] & param_4) != 0)) {
      (**(code **)(*(int *)(param_1 + 4) + 0x2c))(param_1,0);
      iVar1 = (*param_2)(param_1,uVar2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(*(int *)(param_1 + 4) + 0x54))
                          (param_1,**(undefined4 **)(*(int *)(param_1 + 4) + 4));
        if (iVar1 == 0x106) {
          (**(code **)(*(int *)(param_1 + 4) + 0x2c))(param_1,1);
        }
        if (((iVar1 == 0 || iVar1 == 0x106) && (iVar1 = (*param_3)(param_1,local_30), iVar1 == 0))
           && (local_30[0] != uVar2)) {
          iVar1 = 0x108;
        }
      }
      else {
        (**(code **)(*(int *)(param_1 + 4) + 0x2c))(param_1,1);
      }
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


