// 420153bc  FUN_420153bc  FUN_420153bc  size=128

undefined4 FUN_420153bc(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  
  iVar1 = FUN_42015278(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = DAT_420010a0;
  }
  else {
    for (iVar4 = *(int *)(param_1 + 4); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
      if (*(int *)(iVar4 + 0xc) == iVar1) {
        *(undefined1 *)(iVar4 + 0x12) = 0;
        FUN_42024df0(param_1 + 4);
      }
    }
    FUN_42024e14(param_1 + 0x10,iVar1);
    FUN_42014808(iVar1);
    (*(code *)PTR_FUN_420004c0)(iVar1);
    for (piVar3 = *(int **)(param_1 + 0x1c); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[2]) {
      uVar2 = (**(code **)(*piVar3 + 8))(piVar3);
      iVar1 = (*DAT_420007e8)(uVar2,param_2);
      if (iVar1 == 0) {
        FUN_42024da8(param_1 + 0x1c,piVar3);
        (**(code **)(*piVar3 + 4))(piVar3);
        break;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


