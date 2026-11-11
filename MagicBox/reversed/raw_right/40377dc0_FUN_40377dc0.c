// 40377dc0  FUN_40377dc0  FUN_40377dc0  size=108

int FUN_40377dc0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_40 [4];
  int aiStack_30 [12];
  
  aiStack_30[0] = param_1;
  iVar1 = (**(code **)(*(int *)PTR_PTR_4037487c + 8))(aiStack_30);
  if (iVar1 == 0) {
    if (*(int *)(*(int *)(aiStack_30[0] + 4) + 0x10) == 0) {
      iVar1 = DAT_4037488c;
    }
    else if (param_2 == (undefined4 *)0x0) {
      iVar1 = 0x102;
    }
    else {
      iVar1 = (*(code *)**(undefined4 **)PTR_PTR_4037487c)();
      if (iVar1 == 0) {
        iVar1 = (**(code **)(*(int *)(aiStack_30[0] + 4) + 0x10))(aiStack_30[0],local_40);
        if (iVar1 == 0) {
          if (*(int *)(aiStack_30[0] + 0x14) == 0) {
            *(undefined4 *)(aiStack_30[0] + 0x14) = local_40[0];
          }
          *param_2 = local_40[0];
        }
        iVar1 = (**(code **)(*(int *)PTR_PTR_4037487c + 4))(aiStack_30[0],iVar1);
      }
    }
  }
  return iVar1;
}


