// 420031d8  FUN_420031d8  FUN_420031d8  size=162

void FUN_420031d8(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = FUN_4202dd8c(0xb);
  iVar3 = DAT_42000290;
  uVar2 = DAT_42000288;
  iVar1 = DAT_42000284;
  if (iVar5 == 0) {
    memw();
    memw();
    *(uint *)(DAT_42000284 + 0x18) = *(uint *)(DAT_42000284 + 0x18) | DAT_42000288;
    memw();
    memw();
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | uVar2;
    memw();
    memw();
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & DAT_4200028c;
    memw();
    memw();
    *(uint *)(iVar3 + 0x48) = *(uint *)(iVar3 + 0x48) & DAT_42000294;
  }
  FUN_4202ddac(0xb,iVar5);
  uVar4 = DAT_4200029c;
  (*DAT_420002a4)(DAT_4200029c,2,DAT_42000298,1);
  (*DAT_42000174)(uVar4);
  (*DAT_420001f4)(uVar4,0,DAT_420002a0,1);
  (*DAT_420001f4)(uVar4,1,DAT_420002a0,3);
  (*DAT_420002a8)(uVar4);
  (*DAT_4200017c)(uVar4);
  return;
}


