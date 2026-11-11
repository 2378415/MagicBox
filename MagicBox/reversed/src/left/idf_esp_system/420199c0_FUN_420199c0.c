// strings: $}7@4>

void FUN_420199c0(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar1 = 0;
  uVar4 = 0;
  uVar5 = 0;
LAB_420199d0:
  do {
    iVar2 = (*(code *)PTR_FUN_420006fc)();
    if (iVar2 == 0) {
      if (4 < iVar1 - 6U) {
        uVar3 = FUN_42019948(iVar1);
        uVar7 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
        if ((uVar3 & 0x20) == 0) {
          uVar6 = uVar7;
          uVar7 = 0;
        }
        else {
          uVar6 = 0;
        }
        if (uVar3 < 0x40) {
          uVar4 = uVar4 | uVar6;
          uVar5 = uVar5 | uVar7;
        }
        iVar1 = iVar1 + 1;
        goto LAB_420199d0;
      }
    }
    else {
      uVar3 = FUN_42019948(iVar1);
      uVar7 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
      if ((uVar3 & 0x20) == 0) {
        uVar6 = uVar7;
        uVar7 = 0;
      }
      else {
        uVar6 = 0;
      }
      if (uVar3 < 0x40) {
        uVar4 = uVar4 | uVar6;
        uVar5 = uVar5 | uVar7;
      }
    }
    iVar1 = iVar1 + 1;
    if (iVar1 == 0xb) {
      FUN_4201ac2c(uVar4,uVar5);
      return;
    }
  } while( true );
}