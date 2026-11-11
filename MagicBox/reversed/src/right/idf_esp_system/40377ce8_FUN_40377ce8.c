// strings: H.8@

int FUN_40377ce8(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  uVar3 = *(undefined4 *)(param_1 + 0x18);
  piVar4 = *(int **)PTR_PTR_40374888;
  do {
    iVar1 = *piVar4;
    if ((iVar1 == 0) || (iVar2 = FUN_403788ec(param_1), iVar2 != 0)) {
      iVar1 = FUN_403788ec(param_1);
      if (iVar1 == 0) {
        return 0x105;
      }
      return 0;
    }
    *(int *)(param_1 + 4) = iVar1;
    iVar1 = (*(code *)**(undefined4 **)PTR_PTR_4037487c)(param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*(int *)(param_1 + 4) + 8))(param_1,uVar3);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 4) = 0;
    }
    piVar4 = piVar4 + 1;
    iVar1 = (**(code **)(*(int *)PTR_PTR_4037487c + 4))(param_1,0);
  } while (iVar1 == 0);
  return iVar1;
}