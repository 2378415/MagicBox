// 40376d80  FUN_40376d80  FUN_40376d80  size=40

void FUN_40376d80(int *param_1)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_DAT_40374758;
  *param_1 = 0;
  FUN_4037bf44(puVar1,0xffffffff);
  if (*param_1 == 0) {
    iVar2 = FUN_4037b894(1);
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_40381c60();
    }
    *param_1 = iVar2;
  }
  FUN_4037c094(PTR_DAT_40374758);
  return;
}


