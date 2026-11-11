// strings:  n7@

undefined4 FUN_4201fc4c(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == 0) {
LAB_4201fc8a:
    uVar1 = 0;
  }
  else {
    if ((param_1 != 0) && (*(int *)(param_1 + 0x28) == 0)) {
      FUN_420200c4(param_1);
    }
    if ((*(uint *)(param_2 + 100) & 1) == 0) {
      if ((*(ushort *)(param_2 + 0xc) & 0x200) == 0) {
        (*(code *)PTR_FUN_42001c30)(*(undefined4 *)(param_2 + 0x58));
        goto LAB_4201fc76;
      }
    }
    else {
LAB_4201fc76:
      if (*(short *)(param_2 + 0xc) == 0) {
        if ((*(uint *)(param_2 + 100) & 1) == 0) {
          (*(code *)PTR_FUN_42001c34)(*(undefined4 *)(param_2 + 0x58));
        }
        goto LAB_4201fc8a;
      }
    }
    uVar1 = FUN_4201fd28(param_1,param_2);
    if ((*(code **)(param_2 + 0x30) != (code *)0x0) &&
       (iVar2 = (**(code **)(param_2 + 0x30))(param_1,*(undefined4 *)(param_2 + 0x20)), iVar2 < 0))
    {
      uVar1 = 0xffffffff;
    }
    if ((*(ushort *)(param_2 + 0xc) & 0x80) != 0) {
      (*(code *)PTR_FUN_42001c38)(param_1,*(undefined4 *)(param_2 + 0x10));
    }
    if (*(int *)(param_2 + 0x34) != 0) {
      if (*(int *)(param_2 + 0x34) != param_2 + 0x44) {
        (*(code *)PTR_FUN_42001c38)(param_1);
      }
      *(undefined4 *)(param_2 + 0x34) = 0;
    }
    if (*(int *)(param_2 + 0x48) != 0) {
      (*(code *)PTR_FUN_42001c38)(param_1);
      *(undefined4 *)(param_2 + 0x48) = 0;
    }
    FUN_4201fffc();
    *(undefined2 *)(param_2 + 0xc) = 0;
    if ((*(uint *)(param_2 + 100) & 1) == 0) {
      (*(code *)PTR_FUN_42001c34)(*(undefined4 *)(param_2 + 0x58));
    }
    (*(code *)PTR_FUN_42001c3c)(*(undefined4 *)(param_2 + 0x58));
    FUN_4202000c();
  }
  return uVar1;
}