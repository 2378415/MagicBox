// 4200d790  FUN_4200d790  FUN_4200d790  size=68

undefined4 FUN_4200d790(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == -1) {
    iVar1 = (*(code *)PTR_FUN_42000350)(param_1,0xffffffff);
    if (iVar1 == 1) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0xfffffff2;
    }
  }
  else {
    iVar1 = (*(code *)PTR_FUN_42000350)
                      (param_1,(uint)((ulonglong)(uint)(param_2 * 1000) * (ulonglong)DAT_420001a4 >>
                                     0x26));
    if (iVar1 == 1) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0xfffffff2;
    }
  }
  return uVar2;
}


