// 4200ea4c  FUN_4200ea4c  FUN_4200ea4c  size=65

undefined4 FUN_4200ea4c(int param_1,ushort param_2,ushort param_3)

{
  undefined4 uVar1;
  undefined1 local_30;
  undefined1 uStack_2f;
  ushort uStack_2e;
  ushort uStack_2c;
  undefined2 uStack_2a;
  
  uStack_2c = param_2 & 0xff;
  uStack_2e = param_3 & 0xff;
  if (*(char *)(param_1 + 1) == '\0') {
    uVar1 = FUN_4200e4e8(param_1);
  }
  else {
    local_30 = 0x23;
    uStack_2f = 3;
    uStack_2a = 0;
    uVar1 = FUN_4200d104(*(undefined4 *)(param_1 + 0x2af4),&local_30,0);
  }
  return uVar1;
}


