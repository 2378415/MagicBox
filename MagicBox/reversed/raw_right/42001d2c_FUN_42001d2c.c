// 42001d2c  FUN_42001d2c  FUN_42001d2c  size=46

void FUN_42001d2c(undefined1 param_1)

{
  undefined4 local_40 [4];
  undefined1 auStack_30 [48];
  
  local_40[0] = 0;
  do {
    memw();
  } while ((*(uint *)(*(int *)PTR_DAT_42000188 + 0x1c) >> 0x10 & 0x3ff) == 0x80);
  auStack_30[0] = param_1;
  FUN_420244e0(PTR_DAT_42000188,auStack_30,1,local_40);
  return;
}


