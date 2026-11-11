// 4201dc70  FUN_4201dc70  FUN_4201dc70  size=19

undefined4 FUN_4201dc70(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = DAT_42001a94;
  if (*(int *)(param_1 + 0xc) == -1) {
    *(undefined4 *)(param_1 + 0x10) = param_2;
    uVar1 = 0;
  }
  return uVar1;
}


