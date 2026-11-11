int FUN_40378340(int param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 local_40 [4];
  int aiStack_30 [12];
  
  puVar1 = PTR_PTR_403748f8;
  aiStack_30[0] = param_1;
  iVar2 = (**(code **)(*(int *)PTR_PTR_403748f8 + 8))(aiStack_30);
  if (iVar2 == 0) {
    if (*(int *)(*(int *)(aiStack_30[0] + 4) + 0x10) == 0) {
      iVar2 = DAT_40374914;
    }
    else if (param_2 == (undefined4 *)0x0) {
      iVar2 = 0x102;
    }
    else {
      iVar2 = (*(code *)**(undefined4 **)puVar1)();
      if (iVar2 == 0) {
        iVar2 = (**(code **)(*(int *)(aiStack_30[0] + 4) + 0x10))(aiStack_30[0],local_40);
        if (iVar2 == 0) {
          if (*(int *)(aiStack_30[0] + 0x14) == 0) {
            *(undefined4 *)(aiStack_30[0] + 0x14) = local_40[0];
          }
          *param_2 = local_40[0];
        }
        iVar2 = (**(code **)(*(int *)puVar1 + 4))();
      }
    }
  }
  return iVar2;
}