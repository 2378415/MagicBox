/* WARNING: Control flow encountered bad instruction data */
/* (1 unreachable decompiler blocks omitted) */

void FUN_4201e3b8(int param_1,char *param_2,int *param_3,int *param_4,int param_5,int param_6,
                 undefined4 *param_7)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  
  iVar1 = *param_4;
  pcVar2 = (char *)*param_7;
  if ((char *)*param_7 == (char *)0x0) {
    pcVar2 = param_2;
  }
  if (*pcVar2 != '\0') {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  puVar6 = (undefined4 *)(iVar1 * 8 + param_5);
  while (iVar1 <= param_1) {
    iVar7 = iVar1 * 4;
    iVar1 = iVar1 + 1;
    iVar3 = param_3[2];
    switch(*(undefined4 *)(iVar7 + param_6)) {
    default:
      iVar7 = iVar3 + 4;
      param_3[2] = iVar7;
      if (iVar7 < 0x19) {
        iVar3 = param_3[1];
      }
      else {
        if (iVar3 < 0x19) {
          iVar7 = 0x24;
        }
        iVar3 = *param_3;
        param_3[2] = iVar7;
      }
      *puVar6 = *(undefined4 *)(iVar3 + iVar7 + -4);
      break;
    case 2:
      uVar4 = iVar3 + 7U & 0xfffffff8;
      iVar7 = uVar4 + 8;
      param_3[2] = iVar7;
      if (iVar7 < 0x19) {
        iVar3 = param_3[1];
      }
      else {
        if ((int)uVar4 < 0x19) {
          iVar7 = 0x28;
        }
        iVar3 = *param_3;
        param_3[2] = iVar7;
      }
      uVar5 = *(undefined4 *)(iVar3 + iVar7 + -8);
      puVar6[1] = *(undefined4 *)(iVar3 + iVar7 + -4);
      *puVar6 = uVar5;
      break;
    case 4:
    case 5:
      uVar4 = iVar3 + 7U & 0xfffffff8;
      iVar7 = uVar4 + 8;
      param_3[2] = iVar7;
      if (iVar7 < 0x19) {
        iVar3 = param_3[1];
      }
      else {
        if ((int)uVar4 < 0x19) {
          iVar7 = 0x28;
        }
        iVar3 = *param_3;
        param_3[2] = iVar7;
      }
      uVar5 = *(undefined4 *)(iVar3 + iVar7 + -8);
      puVar6[1] = *(undefined4 *)(iVar3 + iVar7 + -4);
      *puVar6 = uVar5;
    }
    puVar6 = puVar6 + 2;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

/* ---- objdump fallback (Ghidra stopped on excw / literal pool) ----
4201e3b8:  entry	a1, 64
4201e3bb:  l32i	a8, a1, 64
4201e3be:  s32i.n	a7, a1, 4
4201e3c0:  l32i.n	a7, a8, 0
4201e3c2:  s32i.n	a2, a1, 8
4201e3c4:  l32i.n	a14, a1, 8
4201e3c6:  l32i.n	a2, a5, 0
4201e3c8:  s32i.n	a5, a1, 16
4201e3ca:  s32i.n	a6, a1, 0
4201e3cc:  moveqz	a7, a3, a7
4201e3cf:  j	0x4201e75f
L_4201e3d2:
4201e3d2:  addi.n	a7, a7, 1
4201e3d4:  l8ui	a8, a7, 0
4201e3d7:  beqz	a8, 0x4201e80a
4201e3da:  addi	a10, a8, -37
4201e3dd:  bnez	a10, 0x4201e3d2
4201e3e0:  beqz	a8, 0x4201e80a
4201e3e3:  movi.n	a8, 0
4201e3e5:  addi.n	a10, a7, 1
4201e3e7:  movi.n	a5, 0
4201e3e9:  movi.n	a13, 0
4201e3eb:  movi.n	a3, -1
4201e3ed:  movi.n	a6, 0
4201e3ef:  s32i.n	a8, a1, 12
4201e3f1:  j	0x4201e3f6
4201e3f4:  mov.n	a10, a7
L_4201e3f6:
4201e3f6:  l32r	a9, 0x420011c4 (0x3c039ef4)
4201e3f9:  l8ui	a8, a10, 0
4201e3fc:  addi.n	a7, a10, 1
4201e3fe:  add.n	a11, a9, a8
4201e400:  l32i.n	a9, a1, 12
4201e402:  l8ui	a12, a11, 0
4201e405:  l32r	a11, 0x420011c8 (0x3c039e88)
4201e408:  addx8	a15, a9, a9
4201e40b:  add.n	a11, a11, a15
4201e40d:  add.n	a11, a11, a12
4201e40f:  l8ui	a9, a11, 0
4201e412:  l32r	a11, 0x420011cc (0x3c039e1c)
4201e415:  s32i.n	a9, a1, 12
4201e417:  add.n	a11, a11, a15
4201e419:  add.n	a11, a11, a12
4201e41b:  l8ui	a11, a11, 0
4201e41e:  addi.n	a11, a11, -1
4201e420:  extui	a11, a11, 0, 8
4201e423:  bltui	a11, 8, 0x4201e429
4201e426:  j	0x4201e755
L_4201e429:
4201e429:  l32r	a12, 0x42001278 (0x3c03987c)
4201e42c:  addx4	a11, a11, a12
4201e42f:  l32i.n	a11, a11, 0
4201e431:  jx	a11
4201e434:  excw
4201e437:  add.n	a0, a6, a9
4201e439:  l8ui	a12, a0, 173
4201e43c:  ball	a6, a0, 0x4201e3ec
4201e43f:  addx4	a11, a2, a0
4201e442:  add.n	a11, a7, a6
4201e444:  l32i.n	a1, a3, 12
4201e446:  bltu	a11, a8, 0x4201e454
4201e449:  movi.n	a11, 76
4201e44b:  beq	a8, a11, 0x4201e475
4201e44e:  movi	a11, 104
4201e451:  j	0x4201e46c
L_4201e454:
4201e454:  movi	a11, 113
4201e457:  beq	a8, a11, 0x4201e47a
4201e45a:  movi	a11, 112
4201e45d:  bgeu	a11, a8, 0x4201e484
4201e460:  movi	a11, 116
4201e463:  bne	a8, a11, 0x4201e469
4201e466:  j	0x4201e755
L_4201e469:
4201e469:  movi	a11, 122
L_4201e46c:
4201e46c:  bne	a8, a11, 0x4201e472
4201e46f:  j	0x4201e755
L_4201e472:
4201e472:  j	0x4201e484
L_4201e475:
4201e475:  movi.n	a8, 8
4201e477:  j	0x4201e47c
L_4201e47a:
4201e47a:  movi.n	a8, 32
L_4201e47c:
4201e47c:  or	a6, a6, a8
4201e47f:  j	0x4201e755
4201e482:  mulsh	a0, a0, a0
4201e485:  add.n	a0, a1, a0
4201e487:  movi	a8, 108
4201e48a:  bne	a11, a8, 0x4201e498
4201e48d:  movi.n	a8, 32
4201e48f:  or	a6, a6, a8
4201e492:  addi.n	a7, a10, 2
4201e494:  j	0x4201e755
4201e497:  lsx	f1, a12, a0
4201e49a:  j	0x4201e47c
4201e49d:  movi	a11, 97
4201e4a0:  extui	a10, a2, 0, 5
4201e4a3:  bne	a8, a11, 0x4201e4a9
4201e4a6:  j	0x4201e83e
L_4201e4a9:
4201e4a9:  bltu	a11, a8, 0x4201e4e8
4201e4ac:  addi	a8, a8, -65
4201e4af:  extui	a8, a8, 0, 8
4201e4b2:  movi.n	a11, 23
4201e4b4:  bgeu	a11, a8, 0x4201e4dc
4201e4b7:  j	0x4201e515
L_4201e4ba:
4201e4ba:  movi.n	a8, 1
4201e4bc:  ssl	a11
4201e4bf:  sll	a8, a8
4201e4c2:  l32r	a11, 0x420011d4 (0x120821)
4201e4c5:  bany	a8, a11, 0x4201e4fc
4201e4c8:  movi.n	a11, 37
4201e4ca:  slli	a11, a11, 10
4201e4cd:  bnone	a8, a11, 0x4201e4d3
4201e4d0:  j	0x4201e849
L_4201e4d3:
4201e4d3:  extui	a8, a8, 1, 3
4201e4d6:  bnez	a8, 0x4201e83e
4201e4d9:  j	0x4201e515
L_4201e4dc:
4201e4dc:  l32r	a11, 0x4200127c (0x3c03989c)
4201e4df:  addx4	a8, a8, a11
4201e4e2:  l32i.n	a8, a8, 0
4201e4e4:  jx	a8
4201e4e7:  addx4	a11, a2, a0
4201e4ea:  excw
4201e4ed:  s32i.n	a1, a2, 32
4201e4ef:  l32i.n	a12, a12, 36
4201e4f1:  extui	a11, a8, 0, 8
4201e4f4:  movi.n	a8, 20
4201e4f6:  bgeu	a8, a11, 0x4201e4ba
4201e4f9:  j	0x4201e515
L_4201e4fc:
4201e4fc:  extui	a5, a6, 5, 1
4201e4ff:  add.n	a5, a5, a5
4201e501:  bbci	a6, 4, 0x4201e515
4201e504:  j	0x4201e868
4201e507:  extui	a1, a0, 28, 1
4201e50a:  and	a5, a6, a5
4201e50d:  bnez	a5, 0x4201e85d
4201e510:  j	0x4201e854
4201e513:  excw
4201e516:  lsi	f0, a11, 0x220
4201e519:  l32r	a1, 0x41fe0dd0
4201e51c:  addx4	a8, a3, a8
4201e51f:  s32i.n	a5, a8, 0
4201e521:  j	0x4201e755
4201e524:  addi.n	a11, a5, -1
4201e526:  l32i.n	a8, a4, 8
4201e528:  addi.n	a2, a10, 1
4201e52a:  bltui	a11, 6, 0x4201e530
4201e52d:  j	0x4201e5d1
L_4201e530:
4201e530:  l32r	a12, 0x42001280 (0x3c0398fc)
4201e533:  addx4	a11, a11, a12
4201e536:  l32i.n	a12, a11, 0
4201e538:  extui	a11, a10, 0, 16
4201e53b:  jx	a12
4201e53e:  l32i.n	a8, a1, 0
4201e540:  l32i.n	a11, a4, 8
4201e542:  addi.n	a2, a10, 1
4201e544:  addx8	a10, a10, a8
4201e547:  addi.n	a8, a11, 4
4201e549:  s32i.n	a8, a4, 8
4201e54b:  movi.n	a12, 24
4201e54d:  blt	a12, a8, 0x4201e555
4201e550:  l32i.n	a11, a4, 4
4201e552:  j	0x4201e55e
L_4201e555:
4201e555:  blt	a12, a11, 0x4201e55a
4201e558:  movi.n	a8, 36
L_4201e55a:
4201e55a:  l32i.n	a11, a4, 0
4201e55c:  s32i.n	a8, a4, 8
L_4201e55e:
4201e55e:  add.n	a11, a11, a8
4201e560:  addi	a11, a11, -4
4201e563:  l32i.n	a8, a11, 0
4201e565:  movi.n	a3, -1
4201e567:  s32i.n	a8, a10, 0
4201e569:  movi.n	a5, 1
4201e56b:  j	0x4201e755
4201e56e:  movi.n	a10, -8
4201e570:  addi.n	a8, a8, 7
4201e572:  and	a8, a8, a10
4201e575:  l32i.n	a9, a1, 0
4201e577:  addi.n	a10, a8, 8
4201e579:  s32i.n	a10, a4, 8
4201e57b:  movi.n	a12, 24
4201e57d:  addx8	a11, a11, a9
4201e580:  blt	a12, a10, 0x4201e588
4201e583:  l32i.n	a8, a4, 4
4201e585:  j	0x4201e591
L_4201e588:
4201e588:  blt	a12, a8, 0x4201e58d
4201e58b:  movi.n	a10, 40
L_4201e58d:
4201e58d:  l32i.n	a8, a4, 0
4201e58f:  s32i.n	a10, a4, 8
L_4201e591:
4201e591:  add.n	a8, a8, a10
4201e593:  addi	a8, a8, -8
4201e596:  l32i.n	a9, a8, 4
4201e598:  l32i.n	a8, a8, 0
4201e59a:  s32i.n	a9, a11, 4
4201e59c:  s32i.n	a8, a11, 0
4201e59e:  j	0x4201e755
4201e5a1:  l32i.n	a8, a1, 0
4201e5a3:  l32i.n	a11, a4, 8
4201e5a5:  addi.n	a2, a10, 1
4201e5a7:  addx8	a10, a10, a8
4201e5aa:  addi.n	a8, a11, 4
4201e5ac:  s32i.n	a8, a4, 8
4201e5ae:  movi.n	a12, 24
4201e5b0:  blt	a12, a8, 0x4201e5b8
4201e5b3:  l32i.n	a11, a4, 4
4201e5b5:  j	0x4201e5c1
---- end objdump fallback ---- */
