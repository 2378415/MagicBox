// 4200218c  FUN_4200218c  FUN_4200218c  size=94

void FUN_4200218c(void)

{
  int iVar1;
  byte local_30;
  
  FUN_4200177c();
  FUN_42002140(1);
  memw();
  local_30 = 0;
  while (memw(), local_30 == 0) {
    memw();
    local_30 = 1;
    for (iVar1 = 0; iVar1 < 2; iVar1 = iVar1 + 1) {
      memw();
      memw();
      local_30 = local_30 & *(byte *)(DAT_42000200 + iVar1);
      memw();
    }
    (*DAT_42000078)(100);
  }
  return;
}


