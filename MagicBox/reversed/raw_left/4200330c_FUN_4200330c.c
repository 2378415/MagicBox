// 4200330c  FUN_4200330c  FUN_4200330c  size=66

void FUN_4200330c(char *param_1)

{
  char cVar1;
  undefined *puVar2;
  undefined4 local_30;
  char acStack_2c [44];
  
  puVar2 = PTR_DAT_420002bc;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    param_1 = param_1 + 1;
    local_30 = 0;
    do {
      memw();
    } while ((*(uint *)(*(int *)puVar2 + 0x1c) >> 0x10 & 0x3ff) == 0x80);
    acStack_2c[0] = cVar1;
    FUN_4202cec4(puVar2,acStack_2c,1,&local_30);
    FUN_420032b0(cVar1);
    cVar1 = *param_1;
  }
  return;
}


