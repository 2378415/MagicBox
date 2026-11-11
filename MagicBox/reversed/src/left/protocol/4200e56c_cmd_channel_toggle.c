/* WARNING: Control flow encountered bad instruction data */

void cmd_channel_toggle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ---- objdump fallback (Ghidra stopped on excw / literal pool) ----
4200e56c:  entry	a1, 48
4200e56f:  movi.n	a8, 2
4200e571:  excw
4200e574:  addi.n	a8, a8, -1
4200e576:  neg	a8, a8
4200e579:  extui	a8, a8, 0, 8
4200e57c:  mov.n	a11, a7
4200e57e:  bnez.n	a8, 0x4200e58e
4200e580:  movi.n	a7, 1
4200e582:  moveqz	a8, a7, a4
4200e585:  mov.n	a5, a8
4200e587:  bnez.n	a8, 0x4200e58e
4200e589:  l32i	a8, a4, 0x214
4200e58c:  bnez.n	a8, 0x4200e59e
L_4200e58e:
4200e58e:  movi	a12, 0
4200e591:  or	a11, a3, a3
4200e594:  or	a10, a2, a2
4200e597:  call8	0x420143e8   ; uart0_reply
4200e59a:  retw.n
4200e59c:  neg	a0, a0
4200e59f:  blti	a0, 2, 0x4200e555
4200e5a2:  l32r	a6, 0x41fd79a4
4200e5a5:  addi.n	a15, a15, 14
4200e5a7:  movi	a8, 255
4200e5aa:  bltu	a8, a10, 0x4200e58e
4200e5ad:  l32i	a14, a4, 0x214
4200e5b0:  movi	a8, 0x369
4200e5b3:  add	a14, a14, a10
4200e5b6:  add.n	a8, a14, a8
4200e5b8:  l8ui	a8, a8, 0
4200e5bb:  beqz	a8, 0x4200e58e
4200e5be:  l32i.n	a11, a1, 0
4200e5c0:  mov.n	a9, a7
4200e5c2:  mov.n	a8, a5
4200e5c4:  movi.n	a10, 44
4200e5c6:  movnez	a9, a11, a11
4200e5c9:  loop	a9, 0x4200e5d6
4200e5cc:  add.n	a12, a6, a8
4200e5ce:  l8ui	a13, a12, 0
4200e5d1:  beq	a13, a10, 0x4200e5d9
4200e5d4:  addi.n	a8, a8, 1
L_4200e5d6:
4200e5d6:  j	0x4200e58e
L_4200e5d9:
4200e5d9:  beqz	a8, 0x4200e58e
4200e5dc:  addi	a11, a11, -2
4200e5df:  bgeu	a8, a11, 0x4200e58e
4200e5e2:  l8ui	a8, a12, 1
4200e5e5:  movi	a10, 0x269
4200e5e8:  add.n	a14, a14, a10
4200e5ea:  addi	a11, a8, -49
4200e5ed:  movi.n	a9, 0
4200e5ef:  movi.n	a10, 1
4200e5f1:  movnez	a10, a9, a11
4200e5f4:  s8i	a10, a14, 0
4200e5f7:  memw
4200e5fa:  movi.n	a10, 49
4200e5fc:  bne	a8, a10, 0x4200e610
4200e5ff:  l32r	a8, 0x42000db4 (0x3fc99fa3)
4200e602:  memw
4200e605:  s8i	a9, a8, 0
4200e608:  memw
4200e60b:  j	0x4200e58e
4200e60e:  src	a0, a0, a0
4200e611:  s32i.n	a14, a9, 48
4200e613:  movi.n	a9, 1
4200e615:  memw
4200e618:  s8i	a9, a8, 0
4200e61b:  memw
4200e61e:  j	0x4200e58e
4200e621:  ill
---- end objdump fallback ---- */
