// 420033bc  FUN_420033bc  FUN_420033bc  size=171
// strings: gfff

void FUN_420033bc(int param_1)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  int local_30;
  undefined1 auStack_2c [44];
  
  puVar2 = PTR_DAT_420002bc;
  local_30 = (int)((longlong)param_1 * (longlong)DAT_420002c4 >> 0x22) - (param_1 >> 0x1f);
  iVar1 = local_30 * -10;
  if (local_30 == 0) {
    auStack_2c[0] = 0x20;
    do {
      memw();
    } while ((*(uint *)(*(int *)PTR_DAT_420002bc + 0x1c) >> 0x10 & 0x3ff) == 0x80);
    FUN_4202cec4(PTR_DAT_420002bc,auStack_2c,1,&local_30);
    FUN_420032b0(0x20);
  }
  else {
    uVar3 = local_30 + 0x30;
    auStack_2c[0] = (undefined1)uVar3;
    local_30 = 0;
    do {
      memw();
    } while ((*(uint *)(*(int *)PTR_DAT_420002bc + 0x1c) >> 0x10 & 0x3ff) == 0x80);
    FUN_4202cec4(PTR_DAT_420002bc,auStack_2c,1,&local_30);
    FUN_420032b0(uVar3 & 0xff);
  }
  uVar3 = param_1 + iVar1 + 0x30;
  auStack_2c[0] = (undefined1)uVar3;
  local_30 = 0;
  do {
    memw();
  } while ((*(uint *)(*(int *)puVar2 + 0x1c) >> 0x10 & 0x3ff) == 0x80);
  FUN_4202cec4(puVar2,auStack_2c,1,&local_30);
  FUN_420032b0(uVar3 & 0xff);
  return;
}


