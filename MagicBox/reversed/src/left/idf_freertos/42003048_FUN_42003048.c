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

/* ---- objdump fallback (Ghidra stopped on excw / literal pool) ----
42003048:  entry	a1, 32
4200304b:  call8	0x4200302c   ; FUN_4200302c
4200304e:  mov.n	a7, a10
42003050:  movi.n	a10, 0
42003052:  l32r	a8, 0x420001c4 (0x4000057c)
42003055:  callx8	a8
42003058:  bnei	a10, 8, 0x4200305e
4200305b:  j	0x420030dc
L_4200305e:
4200305e:  movi.n	a8, 8
42003060:  bltu	a8, a10, 0x4200307d
42003063:  beqi	a10, 5, 0x420030e1
42003066:  bgeui	a10, 6, 0x42003075
42003069:  bnei	a10, 1, 0x4200306f
4200306c:  j	0x420030f4
L_4200306f:
4200306f:  beqi	a10, 3, 0x420030b4
42003072:  j	0x420030ec
L_42003075:
42003075:  bnei	a10, 7, 0x420030ec
42003078:  movi.n	a10, 6
4200307a:  j	0x420030f4
L_4200307d:
4200307d:  movi.n	a8, 15
4200307f:  beq	a10, a8, 0x420030e6
42003082:  bltu	a8, a10, 0x420030a4
42003085:  beqi	a10, 12, 0x420030b4
42003088:  movi.n	a8, 12
4200308a:  bltu	a8, a10, 0x4200309c
4200308d:  movi.n	a8, -3
4200308f:  and	a8, a10, a8
42003092:  movi.n	a9, 9
42003094:  movi.n	a10, 0
42003096:  bne	a8, a9, 0x420030f4
42003099:  j	0x420030f2
L_4200309c:
4200309c:  movi.n	a8, 13
4200309e:  bne	a10, a8, 0x420030ec
420030a1:  j	0x420030f2
L_420030a4:
420030a4:  movi.n	a8, 18
420030a6:  bgeu	a8, a10, 0x420030f2
420030a9:  addi	a8, a10, -21
420030ac:  movi.n	a10, 11
420030ae:  bltui	a8, 2, 0x420030f4
420030b1:  j	0x420030ec
L_420030b4:
420030b4:  addi	a9, a7, -4
420030b7:  movi.n	a8, 2
420030b9:  excw
420030bc:  addi.n	a8, a8, -1
420030be:  neg	a8, a8
420030c1:  extui	a8, a8, 0, 8
420030c4:  bnez.n	a8, 0x420030d4
420030c6:  addi	a10, a7, -9
420030c9:  movi	a9, 1
420030cc:  moveqz	a8, a9, a10
420030cf:  movi	a10, 3
420030d2:  beqz.n	a8, 0x420030f4
L_420030d4:
420030d4:  l32r	a8, 0x42000248 (0x3fc96eb8)
420030d7:  s32i.n	a7, a8, 0
420030d9:  j	0x420030fb
L_420030dc:
420030dc:  movi.n	a10, 5
420030de:  j	0x420030f4
L_420030e1:
420030e1:  mov.n	a10, a8
420030e3:  j	0x420030f4
L_420030e6:
420030e6:  movi.n	a10, 9
420030e8:  j	0x420030f4
420030eb:  add.s	f0, f12, f0
420030ee:  j	0x420030f4
420030f1:  excw
L_420030f4:
420030f4:  l32r	a8, 0x42000248 (0x3fc96eb8)
420030f7:  s32i.n	a10, a8, 0
420030f9:  beqz.n	a7, 0x42003105
L_420030fb:
420030fb:  l32r	a8, 0x42000244 (0x600080c8)
420030fe:  movi.n	a9, 0
42003100:  memw
42003103:  s32i.n	a9, a8, 0
L_42003105:
42003105:  retw.n
---- end objdump fallback ---- */
