// 4201dc44  FUN_4201dc44  FUN_4201dc44  size=41

undefined4 FUN_4201dc44(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xc) == -0x10) {
    uVar1 = DAT_42001a70;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x10);
    uVar1 = 0;
  }
  return uVar1;
}


