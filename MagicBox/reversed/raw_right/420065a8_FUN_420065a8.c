// 420065a8  FUN_420065a8  FUN_420065a8  size=134

void FUN_420065a8(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  
  uVar1 = FUN_42009400();
  (*(code *)PTR_FUN_420003a8)(uVar1,0xffffffff);
  FUN_4200653c(param_1);
  uVar3 = 0;
  do {
    if (2 < (int)uVar3) {
LAB_4200661d:
      FUN_42009400();
      (*(code *)PTR_FUN_420003ac)();
      if (param_1 != 0) {
        (*(code *)PTR_FUN_420004c0)(param_1);
      }
      return;
    }
    if (uVar3 < 0x40) {
      uVar5 = uVar3 + 0x1f;
      if (-1 < (int)uVar3) {
        uVar5 = uVar3;
      }
      iVar2 = (int)uVar5 >> 5;
      uVar5 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
      if ((((*(uint *)((iVar2 + 4) * 4 + param_1 + 4) & uVar5) != 0) ||
          ((uVar5 & *(uint *)((iVar2 + 4) * 4 + param_1 + 0xc)) != 0)) ||
         ((uVar5 & *(uint *)((iVar2 + 8) * 4 + param_1 + 4)) != 0)) {
        piVar4 = (int *)(uVar3 * 4 + DAT_42000788);
        iVar2 = *piVar4 + -1;
        *piVar4 = iVar2;
        if (iVar2 == 0) {
          FUN_420093e8(uVar3,0);
        }
        goto LAB_4200661d;
      }
    }
    uVar3 = uVar3 + 1;
  } while( true );
}


