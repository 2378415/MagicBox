// 4201721c  FUN_4201721c  FUN_4201721c  size=196
// strings: Hl7@

undefined4 FUN_4201721c(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == 0) {
LAB_4201725a:
    uVar1 = 0;
  }
  else {
    if ((param_1 != 0) && (*(int *)(param_1 + 0x28) == 0)) {
      FUN_42017694(param_1);
    }
    if ((*(uint *)(param_2 + 100) & 1) == 0) {
      if ((*(ushort *)(param_2 + 0xc) & 0x200) == 0) {
        (*(code *)PTR_FUN_42001154)(*(undefined4 *)(param_2 + 0x58));
        goto LAB_42017246;
      }
    }
    else {
LAB_42017246:
      if (*(short *)(param_2 + 0xc) == 0) {
        if ((*(uint *)(param_2 + 100) & 1) == 0) {
          (*(code *)PTR_FUN_42001158)(*(undefined4 *)(param_2 + 0x58));
        }
        goto LAB_4201725a;
      }
    }
    uVar1 = FUN_420172f8(param_1,param_2);
    if ((*(code **)(param_2 + 0x30) != (code *)0x0) &&
       (iVar2 = (**(code **)(param_2 + 0x30))(param_1,*(undefined4 *)(param_2 + 0x20)), iVar2 < 0))
    {
      uVar1 = 0xffffffff;
    }
    if ((*(ushort *)(param_2 + 0xc) & 0x80) != 0) {
      (*(code *)PTR_FUN_4200115c)(param_1,*(undefined4 *)(param_2 + 0x10));
    }
    if (*(int *)(param_2 + 0x34) != 0) {
      if (*(int *)(param_2 + 0x34) != param_2 + 0x44) {
        (*(code *)PTR_FUN_4200115c)(param_1);
      }
      *(undefined4 *)(param_2 + 0x34) = 0;
    }
    if (*(int *)(param_2 + 0x48) != 0) {
      (*(code *)PTR_FUN_4200115c)(param_1);
      *(undefined4 *)(param_2 + 0x48) = 0;
    }
    FUN_420175cc();
    *(undefined2 *)(param_2 + 0xc) = 0;
    if ((*(uint *)(param_2 + 100) & 1) == 0) {
      (*(code *)PTR_FUN_42001158)(*(undefined4 *)(param_2 + 0x58));
    }
    (*(code *)PTR_FUN_42001160)(*(undefined4 *)(param_2 + 0x58));
    FUN_420175dc();
  }
  return uVar1;
}


