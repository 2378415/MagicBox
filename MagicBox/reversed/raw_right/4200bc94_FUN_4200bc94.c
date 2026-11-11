// 4200bc94  FUN_4200bc94  FUN_4200bc94  size=155

undefined4 FUN_4200bc94(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((DAT_42000a88 < (uint)(param_1 + DAT_4200058c)) ||
     (DAT_42000a88 < (uint)(param_1 + param_2 + DAT_42000a90))) {
    if ((DAT_42000234 < (uint)(param_1 + DAT_42000a94)) ||
       (DAT_42000234 < (uint)(param_1 + param_2 + DAT_42000a98))) {
      if ((DAT_42000234 < (uint)(param_1 + DAT_42000230)) ||
         (DAT_42000234 < (uint)(param_1 + param_2 + DAT_42000a9c))) {
        iVar1 = (*(code *)PTR_FUN_42000aa4)(param_1);
        if ((iVar1 == 0) ||
           (iVar1 = (*(code *)PTR_FUN_42000aa4)(param_1 + param_2 + -1), iVar1 == 0)) {
          if (DAT_42000224 < (uint)(param_1 + DAT_42000220)) {
            uVar2 = 0;
          }
          else if (DAT_42000224 < (uint)(param_1 + param_2 + DAT_42000aa0)) {
            uVar2 = 0;
          }
          else {
            uVar2 = 1;
          }
        }
        else {
          uVar2 = 1;
        }
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


