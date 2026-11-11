undefined4 FUN_4200e59c(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 local_30;
  undefined1 uStack_2f;
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  
  if (*(char *)(param_1 + 1) == '\0') {
    uVar1 = FUN_4200e560(param_1,param_2);
  }
  else {
    local_30 = 0x20;
    uStack_2f = 0xc;
    uStack_2e = (undefined2)param_2;
    uStack_2c = 0;
    uStack_2a = 0;
    uVar1 = FUN_4200d104(*(undefined4 *)(param_1 + 0x2af4),&local_30,0);
  }
  return uVar1;
}