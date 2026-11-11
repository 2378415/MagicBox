/* WARNING: Control flow encountered bad instruction data */
/* (1 unreachable decompiler blocks omitted) */

void FUN_420181c0(int param_1,char *param_2,int *param_3,int *param_4,int param_5,int param_6,
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
420181c0:  entry	a1, 64
420181c3:  l32i	a8, a1, 64
420181c6:  s32i.n	a7, a1, 4
420181c8:  l32i.n	a7, a8, 0
420181ca:  s32i.n	a2, a1, 8
420181cc:  l32i.n	a14, a1, 8
420181ce:  l32i.n	a2, a5, 0
420181d0:  s32i.n	a5, a1, 16
420181d2:  s32i.n	a6, a1, 0
420181d4:  moveqz	a7, a3, a7
420181d7:  j	0x42018567
L_420181da:
420181da:  addi.n	a7, a7, 1
420181dc:  l8ui	a8, a7, 0
420181df:  beqz	a8, 0x42018612
420181e2:  addi	a10, a8, -37
420181e5:  bnez	a10, 0x420181da
420181e8:  beqz	a8, 0x42018612
420181eb:  movi.n	a8, 0
420181ed:  addi.n	a10, a7, 1
420181ef:  movi.n	a5, 0
420181f1:  movi.n	a13, 0
420181f3:  movi.n	a3, -1
420181f5:  movi.n	a6, 0
420181f7:  s32i.n	a8, a1, 12
420181f9:  j	0x420181fe
420181fc:  mov.n	a10, a7
L_420181fe:
420181fe:  l32r	a9, 0x420011c4 (0x3c039ef4)
42018201:  l8ui	a8, a10, 0
42018204:  addi.n	a7, a10, 1
42018206:  add.n	a11, a9, a8
42018208:  l32i.n	a9, a1, 12
4201820a:  l8ui	a12, a11, 0
4201820d:  l32r	a11, 0x420011c8 (0x3c039e88)
42018210:  addx8	a15, a9, a9
42018213:  add.n	a11, a11, a15
42018215:  add.n	a11, a11, a12
42018217:  l8ui	a9, a11, 0
4201821a:  l32r	a11, 0x420011cc (0x3c039e1c)
4201821d:  s32i.n	a9, a1, 12
4201821f:  add.n	a11, a11, a15
42018221:  add.n	a11, a11, a12
42018223:  l8ui	a11, a11, 0
42018226:  addi.n	a11, a11, -1
42018228:  extui	a11, a11, 0, 8
4201822b:  bltui	a11, 8, 0x42018231
4201822e:  j	0x4201855d
L_42018231:
42018231:  l32r	a12, 0x420011d0 (0x3c039404)
42018234:  addx4	a11, a11, a12
42018237:  l32i.n	a11, a11, 0
42018239:  jx	a11
4201823c:  excw
4201823f:  add.n	a0, a6, a9
42018241:  l8ui	a12, a0, 173
42018244:  ball	a6, a0, 0x420181f4
42018247:  addx4	a11, a2, a0
4201824a:  add.n	a11, a7, a6
4201824c:  l32i.n	a1, a3, 12
4201824e:  bltu	a11, a8, 0x4201825c
42018251:  movi.n	a11, 76
42018253:  beq	a8, a11, 0x4201827d
42018256:  movi	a11, 104
42018259:  j	0x42018274
L_4201825c:
4201825c:  movi	a11, 113
4201825f:  beq	a8, a11, 0x42018282
42018262:  movi	a11, 112
42018265:  bgeu	a11, a8, 0x4201828c
42018268:  movi	a11, 116
4201826b:  bne	a8, a11, 0x42018271
4201826e:  j	0x4201855d
L_42018271:
42018271:  movi	a11, 122
L_42018274:
42018274:  bne	a8, a11, 0x4201827a
42018277:  j	0x4201855d
L_4201827a:
4201827a:  j	0x4201828c
L_4201827d:
4201827d:  movi.n	a8, 8
4201827f:  j	0x42018284
L_42018282:
42018282:  movi.n	a8, 32
L_42018284:
42018284:  or	a6, a6, a8
42018287:  j	0x4201855d
4201828a:  mulsh	a0, a0, a0
4201828d:  add.n	a0, a1, a0
4201828f:  movi	a8, 108
42018292:  bne	a11, a8, 0x420182a0
42018295:  movi.n	a8, 32
42018297:  or	a6, a6, a8
4201829a:  addi.n	a7, a10, 2
4201829c:  j	0x4201855d
4201829f:  lsx	f1, a12, a0
420182a2:  j	0x42018284
420182a5:  movi	a11, 97
420182a8:  extui	a10, a2, 0, 5
420182ab:  bne	a8, a11, 0x420182b1
420182ae:  j	0x42018646
L_420182b1:
420182b1:  bltu	a11, a8, 0x420182f0
420182b4:  addi	a8, a8, -65
420182b7:  extui	a8, a8, 0, 8
420182ba:  movi.n	a11, 23
420182bc:  bgeu	a11, a8, 0x420182e4
420182bf:  j	0x4201831d
L_420182c2:
420182c2:  movi.n	a8, 1
420182c4:  ssl	a11
420182c7:  sll	a8, a8
420182ca:  l32r	a11, 0x420011d4 (0x120821)
420182cd:  bany	a8, a11, 0x42018304
420182d0:  movi.n	a11, 37
420182d2:  slli	a11, a11, 10
420182d5:  bnone	a8, a11, 0x420182db
420182d8:  j	0x42018651
L_420182db:
420182db:  extui	a8, a8, 1, 3
420182de:  bnez	a8, 0x42018646
420182e1:  j	0x4201831d
L_420182e4:
420182e4:  l32r	a11, 0x420011d8 (0x3c039424)
420182e7:  addx4	a8, a8, a11
420182ea:  l32i.n	a8, a8, 0
420182ec:  jx	a8
420182ef:  addx4	a11, a2, a0
420182f2:  excw
420182f5:  s32i.n	a1, a2, 32
420182f7:  l32i.n	a12, a12, 36
420182f9:  extui	a11, a8, 0, 8
420182fc:  movi.n	a8, 20
420182fe:  bgeu	a8, a11, 0x420182c2
42018301:  j	0x4201831d
L_42018304:
42018304:  extui	a5, a6, 5, 1
42018307:  add.n	a5, a5, a5
42018309:  bbci	a6, 4, 0x4201831d
4201830c:  j	0x42018670
4201830f:  extui	a1, a0, 28, 1
42018312:  and	a5, a6, a5
42018315:  bnez	a5, 0x42018665
42018318:  j	0x4201865c
4201831b:  excw
4201831e:  lsi	f0, a11, 0x220
42018321:  l32r	a1, 0x41fdabd8
42018324:  addx4	a8, a3, a8
42018327:  s32i.n	a5, a8, 0
42018329:  j	0x4201855d
4201832c:  addi.n	a11, a5, -1
4201832e:  l32i.n	a8, a4, 8
42018330:  addi.n	a2, a10, 1
42018332:  bltui	a11, 6, 0x42018338
42018335:  j	0x420183d9
L_42018338:
42018338:  l32r	a12, 0x420011dc (0x3c039484)
4201833b:  addx4	a11, a11, a12
4201833e:  l32i.n	a12, a11, 0
42018340:  extui	a11, a10, 0, 16
42018343:  jx	a12
42018346:  l32i.n	a8, a1, 0
42018348:  l32i.n	a11, a4, 8
4201834a:  addi.n	a2, a10, 1
4201834c:  addx8	a10, a10, a8
4201834f:  addi.n	a8, a11, 4
42018351:  s32i.n	a8, a4, 8
42018353:  movi.n	a12, 24
42018355:  blt	a12, a8, 0x4201835d
42018358:  l32i.n	a11, a4, 4
4201835a:  j	0x42018366
L_4201835d:
4201835d:  blt	a12, a11, 0x42018362
42018360:  movi.n	a8, 36
L_42018362:
42018362:  l32i.n	a11, a4, 0
42018364:  s32i.n	a8, a4, 8
L_42018366:
42018366:  add.n	a11, a11, a8
42018368:  addi	a11, a11, -4
4201836b:  l32i.n	a8, a11, 0
4201836d:  movi.n	a3, -1
4201836f:  s32i.n	a8, a10, 0
42018371:  movi.n	a5, 1
42018373:  j	0x4201855d
42018376:  movi.n	a10, -8
42018378:  addi.n	a8, a8, 7
4201837a:  and	a8, a8, a10
4201837d:  l32i.n	a9, a1, 0
4201837f:  addi.n	a10, a8, 8
42018381:  s32i.n	a10, a4, 8
42018383:  movi.n	a12, 24
42018385:  addx8	a11, a11, a9
42018388:  blt	a12, a10, 0x42018390
4201838b:  l32i.n	a8, a4, 4
4201838d:  j	0x42018399
L_42018390:
42018390:  blt	a12, a8, 0x42018395
42018393:  movi.n	a10, 40
L_42018395:
42018395:  l32i.n	a8, a4, 0
42018397:  s32i.n	a10, a4, 8
L_42018399:
42018399:  add.n	a8, a8, a10
4201839b:  addi	a8, a8, -8
4201839e:  l32i.n	a9, a8, 4
420183a0:  l32i.n	a8, a8, 0
420183a2:  s32i.n	a9, a11, 4
420183a4:  s32i.n	a8, a11, 0
420183a6:  j	0x4201855d
420183a9:  l32i.n	a8, a1, 0
420183ab:  l32i.n	a11, a4, 8
420183ad:  addi.n	a2, a10, 1
420183af:  addx8	a10, a10, a8
420183b2:  addi.n	a8, a11, 4
420183b4:  s32i.n	a8, a4, 8
420183b6:  movi.n	a12, 24
420183b8:  blt	a12, a8, 0x420183c0
420183bb:  l32i.n	a11, a4, 4
420183bd:  j	0x420183c9
---- end objdump fallback ---- */
