// 4200e7e4  FUN_4200e7e4  FUN_4200e7e4  size=64

undefined4 FUN_4200e7e4(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 local_30;
  undefined1 uStack_2f;
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  
  if (*(char *)(param_1 + 1) == '\0') {
    uVar1 = FUN_4200e778(param_1,param_2,param_3);
  }
  else {
    local_30 = 0xa3;
    uStack_2f = 0;
    uStack_2e = 0;
    uStack_2c = (undefined2)param_2;
    uStack_2a = 4;
    uVar1 = FUN_4200d104(*(undefined4 *)(param_1 + 0x2af4),&local_30);
  }
  return uVar1;
}


