// 42001e58  FUN_42001e58  FUN_42001e58  size=41

void FUN_42001e58(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  for (iVar2 = 0; iVar2 < 8; iVar2 = iVar2 + 1) {
    uVar1 = param_1 >> 0x1c;
    if (uVar1 < 10) {
      FUN_42001e18(uVar1 + 0x30);
    }
    else {
      FUN_42001e18(uVar1 + 0x57);
    }
    param_1 = param_1 << 4;
  }
  return;
}


