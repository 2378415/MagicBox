undefined4 FUN_42016a8c(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == -1) {
    iVar1 = (*(code *)PTR_FUN_42000480)(param_1,0xffffffff);
  }
  else {
    iVar1 = (*(code *)PTR_FUN_42000480)
                      (param_1,(uint)((ulonglong)(uint)(param_2 * 1000) * (ulonglong)DAT_420002d0 >>
                                     0x26));
  }
  if (iVar1 == 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffff2;
  }
  return uVar2;
}