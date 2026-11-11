undefined4 FUN_42013324(int param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    uVar1 = FUN_42013300(param_1);
    uVar2 = FUN_420132b8(uVar1);
  }
  else {
    uVar1 = FUN_42013300(param_1);
    uVar2 = FUN_42013288(uVar1);
  }
  return uVar2;
}