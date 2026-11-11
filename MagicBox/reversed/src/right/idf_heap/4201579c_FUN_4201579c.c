undefined4 FUN_4201579c(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xc) == -1) {
    *(undefined4 *)(param_1 + 0x10) = param_2;
    uVar1 = 0;
  }
  else {
    uVar1 = DAT_420010e0;
  }
  return uVar1;
}