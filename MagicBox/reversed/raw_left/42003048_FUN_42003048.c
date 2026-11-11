// 42003048  FUN_42003048  size=154

/* WARNING: Control flow encountered bad instruction data */

void FUN_42003048(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_4200302c();
  uVar2 = (*DAT_420001c4)(0);
  if (uVar2 == 8) {
    uVar3 = 5;
    goto LAB_420030f4;
  }
  if (uVar2 < 9) {
    if (uVar2 == 5) {
      uVar3 = 8;
      goto LAB_420030f4;
    }
    if (uVar2 < 6) {
      if (uVar2 == 1) {
        uVar3 = 1;
        goto LAB_420030f4;
      }
      if (uVar2 == 3) {
        halt_baddata();
      }
    }
    else if (uVar2 == 7) {
      uVar3 = 6;
      goto LAB_420030f4;
    }
LAB_420030ec:
    uVar3 = 0;
  }
  else {
    if (uVar2 == 0xf) {
      uVar3 = 9;
      goto LAB_420030f4;
    }
    if (uVar2 < 0x10) {
      if (uVar2 == 0xc) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if (uVar2 < 0xd) {
        uVar3 = 0;
        if ((uVar2 & 0xfffffffd) != 9) goto LAB_420030f4;
      }
      else if (uVar2 != 0xd) goto LAB_420030ec;
    }
    else if (0x12 < uVar2) {
      uVar3 = 0xb;
      if (uVar2 - 0x15 < 2) goto LAB_420030f4;
      goto LAB_420030ec;
    }
    uVar3 = 7;
  }
LAB_420030f4:
  *DAT_42000248 = uVar3;
  if (iVar1 != 0) {
    memw();
    *DAT_42000244 = 0;
  }
  return;
}


