// 4200c98c  FUN_4200c98c  FUN_4200c98c  size=55

void FUN_4200c98c(int param_1)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  if (*(int *)(param_1 + 0x28) == 0) {
    FUN_4200c978();
  }
  else {
    FUN_4200d7d4(*(undefined4 *)(iVar2 + 0xc));
  }
  pcVar1 = *(code **)(param_1 + 0x38);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(param_1 + 0x2c) < 0) {
      (*pcVar1)(*(undefined4 *)(param_1 + 0x3c));
    }
    else {
      (*pcVar1)(*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x24));
    }
  }
  return;
}


