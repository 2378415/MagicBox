int FUN_40377e30(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int local_30;
  uint auStack_2c [11];
  
  if (param_1 == (int *)0x0) {
    iVar1 = 0x102;
  }
  else {
    piVar5 = (int *)*param_1;
    if (piVar5 == (int *)0x0) {
      iVar1 = 0x102;
    }
    else if (*piVar5 == 0) {
      iVar1 = 0x102;
    }
    else if (piVar5[1] == 0) {
      iVar1 = 0x102;
    }
    else {
      uVar4 = param_1[4];
      local_30 = 0;
      if (uVar4 < 0x10) {
        iVar1 = 10;
        while ((iVar3 = (*(code *)PTR_FUN_40374894)(param_1,&local_30), iVar3 == DAT_40374880 &&
               (0 < iVar1))) {
          iVar1 = iVar1 + -1;
        }
        if (iVar3 != 0) {
          return iVar3;
        }
      }
      else {
        local_30 = *(int *)*DAT_403747dc;
      }
      param_1[6] = local_30;
      iVar1 = FUN_403788ec(param_1);
      if (((iVar1 != 0) || (iVar1 = FUN_40377ce8(param_1), iVar1 == 0)) &&
         (iVar1 = FUN_40377dc0(param_1,auStack_2c), iVar1 == 0)) {
        if (((*(code **)(param_1[1] + 0x74) != (code *)0x0) &&
            (uVar2 = (**(code **)(param_1[1] + 0x74))(param_1), (uVar2 & 2) == 0)) &&
           (DAT_40374890 < auStack_2c[0])) {
          auStack_2c[0] = DAT_40374890;
        }
        iVar1 = (*(code *)**(undefined4 **)PTR_PTR_4037487c)(param_1);
        if (iVar1 == 0) {
          iVar1 = 0;
          if (uVar4 < 0x10) {
            iVar3 = (**(code **)(param_1[1] + 0x58))(param_1);
            if (iVar3 == 0x108) {
              if (param_1[4] - 4U < 2) {
                iVar1 = iVar3;
              }
            }
            else {
              iVar1 = iVar3;
            }
          }
          iVar1 = (**(code **)(*(int *)PTR_PTR_4037487c + 4))(param_1,iVar1);
        }
      }
    }
  }
  return iVar1;
}