// 42010fdc  FUN_42010fdc  FUN_42010fdc  size=47

void FUN_42010fdc(undefined4 param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (param_3 != 0) {
    puVar2 = param_2 + param_3;
    do {
      iVar1 = FUN_4202d2a0(*param_2);
      if (iVar1 != 0) {
        FUN_42010e70(param_1,iVar1);
        (*(code *)PTR_FUN_42000098)(0x32);
        FUN_42010f00(param_1,iVar1);
      }
      param_2 = param_2 + 1;
    } while (param_2 != puVar2);
  }
  return;
}


