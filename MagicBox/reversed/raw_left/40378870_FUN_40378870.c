// 40378870  FUN_40378870  size=128

/* WARNING: Control flow encountered bad instruction data */

int FUN_40378870(undefined4 *param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *apuStack_40 [16];
  
  apuStack_40[0] = param_1;
  iVar1 = (**(code **)(*(int *)PTR_PTR_403748f8 + 8))(apuStack_40);
  if (iVar1 == 0) {
    if (*(int *)(apuStack_40[0][1] + 0x44) == 0) {
      iVar1 = DAT_40374914;
    }
    else {
      if (*(code **)(apuStack_40[0][2] + 8) != (code *)0x0) {
        iVar2 = (**(code **)(apuStack_40[0][2] + 8))(apuStack_40[0][3],param_3,param_4);
        if (iVar2 == 0x10d) {
          return 0x10d;
        }
        if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_40381c60();
        }
      }
      if (((param_2 == 0) || ((uint)apuStack_40[0][5] < param_3)) ||
         ((uint)apuStack_40[0][5] < param_3 + param_4)) {
        iVar1 = 0x102;
      }
      else if (param_4 != 0) {
        (**(code **)(*(int *)*apuStack_40[0] + 0x24))((int *)*apuStack_40[0],param_2);
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
  }
  return iVar1;
}


