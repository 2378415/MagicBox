// 42002238  FUN_42002238  FUN_42002238  size=104
// strings: Pm7@L

int FUN_42002238(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  (*(code *)PTR_FUN_420000b8)(DAT_420000ac);
  piVar1 = DAT_420000b0;
  if ((param_2 == 0 || param_3 == 0) || (param_1 == 0)) {
    iVar2 = 0x102;
  }
  else {
    if (*DAT_420000b0 == 0) {
      FUN_42002550();
    }
    iVar2 = FUN_420023d0(param_1,param_2,param_3,PTR_LAB_420000b4);
    if (*piVar1 == 0) {
      if ((iVar2 == 0) && (iVar2 = FUN_42002b00(), iVar2 == 0)) {
        iVar2 = FUN_42002594();
      }
      FUN_42002550();
    }
  }
  (*(code *)PTR_FUN_420000bc)(DAT_420000ac);
  return iVar2;
}


