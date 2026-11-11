/* WARNING: Control flow encountered bad instruction data */

void cmd_silent(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}

/* ---- objdump fallback (Ghidra stopped on excw / literal pool) ----
4200e1b0:  entry	a1, 96
4200e1b3:  s32i.n	a7, a1, 20
4200e1b5:  mov.n	a8, a4
4200e1b7:  mov.n	a14, a2
4200e1b9:  mov.n	a13, a3
4200e1bb:  mov.n	a5, a6
4200e1bd:  movi.n	a9, 1
4200e1bf:  beqz	a4, 0x4200e355
4200e1c2:  movi.n	a10, 2
4200e1c4:  excw
4200e1c7:  addi.n	a10, a10, -1
4200e1c9:  neg	a10, a10
4200e1cc:  extui	a10, a10, 0, 8
4200e1cf:  bnez	a10, 0x4200e355
4200e1d2:  mov.n	a6, a10
4200e1d4:  s32i.n	a10, a1, 0
4200e1d6:  mov.n	a3, a5
4200e1d8:  mov.n	a4, a10
4200e1da:  mov.n	a11, a10
4200e1dc:  s32i.n	a10, a1, 16
4200e1de:  movi.n	a2, 9
4200e1e0:  mov.n	a7, a10
4200e1e2:  s32i.n	a14, a1, 44
4200e1e4:  s32i.n	a13, a1, 48
4200e1e6:  s32i	a8, a1, 52
L_4200e1e9:
4200e1e9:  l32i.n	a8, a1, 20
4200e1eb:  addi.n	a7, a7, 1
4200e1ed:  beq	a8, a6, 0x4200e208
4200e1f0:  l8ui	a12, a3, 0
4200e1f3:  mov.n	a8, a10
4200e1f5:  addi	a13, a12, -44
4200e1f8:  moveqz	a8, a9, a13
4200e1fb:  bnez.n	a8, 0x4200e208
4200e1fd:  addi	a12, a12, -41
4200e200:  moveqz	a8, a9, a12
4200e203:  mov.n	a12, a9
4200e205:  beqz	a8, 0x4200e31a
L_4200e208:
4200e208:  l32i.n	a8, a1, 16
4200e20a:  addi.n	a4, a8, 1
4200e20c:  mov.n	a8, a10
4200e20e:  bltu	a11, a6, 0x4200e214
4200e211:  j	0x4200e306
L_4200e214:
4200e214:  sub	a14, a6, a11
4200e217:  s32i.n	a4, a1, 24
4200e219:  j	0x4200e229
L_4200e21c:
4200e21c:  addi.n	a11, a11, 1
4200e21e:  addi.n	a14, a14, -1
4200e220:  bnez.n	a14, 0x4200e229
4200e222:  l32i.n	a4, a1, 24
4200e224:  mov.n	a8, a10
4200e226:  j	0x4200e306
L_4200e229:
4200e229:  add.n	a8, a5, a11
4200e22b:  l8ui	a12, a8, 0
4200e22e:  mov.n	a13, a10
4200e230:  addi	a15, a12, -32
4200e233:  moveqz	a13, a9, a15
4200e236:  addi	a4, a12, -9
4200e239:  mov.n	a15, a10
4200e23b:  moveqz	a15, a9, a4
4200e23e:  or	a13, a13, a15
4200e241:  bnez	a13, 0x4200e21c
4200e244:  l32i.n	a4, a1, 24
4200e246:  bltu	a11, a6, 0x4200e24c
4200e249:  j	0x4200e304
L_4200e24c:
4200e24c:  movi.n	a14, 45
4200e24e:  bne	a12, a14, 0x4200e258
4200e251:  addi.n	a11, a11, 1
4200e253:  movi.n	a13, 1
4200e255:  j	0x4200e271
L_4200e258:
4200e258:  movi.n	a14, 43
4200e25a:  bne	a12, a14, 0x4200e286
4200e25d:  addi.n	a11, a11, 1
4200e25f:  j	0x4200e271
L_4200e262:
4200e262:  addi.n	a11, a11, 1
4200e264:  beq	a11, a6, 0x4200e26c
4200e267:  add.n	a8, a5, a11
4200e269:  j	0x4200e286
L_4200e26c:
4200e26c:  mov.n	a8, a10
4200e26e:  j	0x4200e306
L_4200e271:
4200e271:  add.n	a8, a5, a11
4200e273:  bltu	a11, a6, 0x4200e286
L_4200e276:
4200e276:  movi.n	a8, 0
4200e278:  j	0x4200e306
L_4200e27b:
4200e27b:  mov.n	a14, a10
4200e27d:  sub	a15, a3, a8
4200e280:  bltu	a11, a6, 0x4200e2a2
4200e283:  j	0x4200e276
L_4200e286:
4200e286:  l8ui	a12, a8, 0
4200e289:  addi	a14, a12, -32
4200e28c:  addi	a15, a12, -9
4200e28f:  mov.n	a12, a10
4200e291:  moveqz	a12, a9, a14
4200e294:  mov.n	a14, a10
4200e296:  moveqz	a14, a9, a15
4200e299:  or	a12, a12, a14
4200e29c:  bnez	a12, 0x4200e262
4200e29f:  j	0x4200e27b
L_4200e2a2:
4200e2a2:  s32i.n	a4, a1, 24
4200e2a4:  s32i.n	a13, a1, 28
4200e2a6:  s32i.n	a3, a1, 32
4200e2a8:  s32i.n	a6, a1, 36
4200e2aa:  s32i	a7, a1, 40
4200e2ad:  loop	a15, 0x4200e2de
4200e2b0:  l8ui	a11, a8, 0
4200e2b3:  mov.n	a4, a10
4200e2b5:  addi	a13, a11, -48
4200e2b8:  addi	a6, a11, -32
4200e2bb:  extui	a7, a13, 0, 8
4200e2be:  addx4	a3, a14, a14
4200e2c1:  movnez	a4, a9, a6
4200e2c4:  bltu	a2, a7, 0x4200e2d0
4200e2c7:  addx2	a14, a3, a13
4200e2ca:  mov.n	a12, a9
4200e2cc:  j	0x4200e2dc
4200e2cf:  movf.s	f11, f2, b0
4200e2d2:  bbs	a13, a15, 0x4200e2e0
4200e2d5:  movnez	a13, a9, a11
4200e2d8:  beqz.n	a4, 0x4200e2dc
4200e2da:  bnez.n	a13, 0x4200e2de
L_4200e2dc:
4200e2dc:  addi.n	a8, a8, 1
L_4200e2de:
4200e2de:  l32i.n	a4, a1, 24
L_4200e2e0:
4200e2e0:  l32i.n	a13, a1, 28
4200e2e2:  l32i.n	a3, a1, 32
4200e2e4:  l32i.n	a6, a1, 36
4200e2e6:  l32i.n	a7, a1, 40
4200e2e8:  mov.n	a8, a10
4200e2ea:  beqz.n	a12, 0x4200e306
4200e2ec:  neg	a8, a14
4200e2ef:  movnez	a14, a8, a13
4200e2f2:  l32r	a8, 0x42000db0 (0xffff8000)
4200e2f5:  max	a14, a14, a8
4200e2f8:  l32r	a8, 0x42000a38 (0x7fff)
4200e2fb:  min	a14, a14, a8
4200e2fe:  sext	a8, a14, 15
4200e301:  j	0x4200e306
L_4200e304:
4200e304:  mov.n	a8, a13
L_4200e306:
4200e306:  l32i.n	a11, a1, 16
4200e308:  s32i.n	a4, a1, 16
4200e30a:  addx2	a12, a11, a1
4200e30d:  s16i	a8, a12, 0
4200e310:  addi	a11, a4, -2
4200e313:  mov.n	a12, a10
4200e315:  movnez	a12, a9, a11
4200e318:  mov.n	a11, a7
L_4200e31a:
4200e31a:  l32i	a8, a1, 20
4200e31d:  addi	a6, a6, 1
4200e320:  excw
4200e323:  addi.n	a8, a8, -1
4200e325:  neg	a8, a8
4200e328:  extui	a8, a8, 0, 8
4200e32b:  addi.n	a3, a3, 1
4200e32d:  beqz.n	a8, 0x4200e332
4200e32f:  bnez	a12, 0x4200e1e9
L_4200e332:
4200e332:  l32i.n	a9, a1, 16
4200e334:  l32i.n	a14, a1, 44
4200e336:  l32i.n	a13, a1, 48
4200e338:  l32i.n	a8, a1, 52
4200e33a:  bnei	a9, 2, 0x4200e355
4200e33d:  l16si	a12, a1, 2
4200e340:  l16si	a11, a1, 0
4200e343:  mov.n	a10, a8
4200e345:  s32i.n	a13, a1, 20
4200e347:  s32i.n	a14, a1, 16
4200e349:  call8	0x42010d3c   ; FUN_42010d3c
4200e34c:  l32i.n	a11, a1, 20
4200e34e:  l32i.n	a10, a1, 16
4200e350:  movi.n	a12, 0
4200e352:  call8	0x420143e8   ; uart0_reply
L_4200e355:
4200e355:  retw.n
---- end objdump fallback ---- */
