/* WARNING: Control flow encountered bad instruction data */
/* (1 unreachable decompiler blocks omitted) */

void FUN_4201b200(int param_1,char *param_2,int *param_3,int *param_4,int param_5,int param_6,
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
4201b200:  entry	a1, 64
4201b203:  l32i	a8, a1, 64
4201b206:  s32i.n	a7, a1, 4
4201b208:  l32i.n	a7, a8, 0
4201b20a:  s32i.n	a2, a1, 8
4201b20c:  l32i.n	a14, a1, 8
4201b20e:  l32i.n	a2, a5, 0
4201b210:  s32i.n	a5, a1, 16
4201b212:  s32i.n	a6, a1, 0
4201b214:  moveqz	a7, a3, a7
4201b217:  j	0x4201b5a7
L_4201b21a:
4201b21a:  addi.n	a7, a7, 1
4201b21c:  l8ui	a8, a7, 0
4201b21f:  beqz	a8, 0x4201b652
4201b222:  addi	a10, a8, -37
4201b225:  bnez	a10, 0x4201b21a
4201b228:  beqz	a8, 0x4201b652
4201b22b:  movi.n	a8, 0
4201b22d:  addi.n	a10, a7, 1
4201b22f:  movi.n	a5, 0
4201b231:  movi.n	a13, 0
4201b233:  movi.n	a3, -1
4201b235:  movi.n	a6, 0
4201b237:  s32i.n	a8, a1, 12
4201b239:  j	0x4201b23e
4201b23c:  mov.n	a10, a7
L_4201b23e:
4201b23e:  l32r	a9, 0x420011c4 (0x3c039ef4)
4201b241:  l8ui	a8, a10, 0
4201b244:  addi.n	a7, a10, 1
4201b246:  add.n	a11, a9, a8
4201b248:  l32i.n	a9, a1, 12
4201b24a:  l8ui	a12, a11, 0
4201b24d:  l32r	a11, 0x420011c8 (0x3c039e88)
4201b250:  addx8	a15, a9, a9
4201b253:  add.n	a11, a11, a15
4201b255:  add.n	a11, a11, a12
4201b257:  l8ui	a9, a11, 0
4201b25a:  l32r	a11, 0x420011cc (0x3c039e1c)
4201b25d:  s32i.n	a9, a1, 12
4201b25f:  add.n	a11, a11, a15
4201b261:  add.n	a11, a11, a12
4201b263:  l8ui	a11, a11, 0
4201b266:  addi.n	a11, a11, -1
4201b268:  extui	a11, a11, 0, 8
4201b26b:  bltui	a11, 8, 0x4201b271
4201b26e:  j	0x4201b59d
L_4201b271:
4201b271:  l32r	a12, 0x42001240 (0x3c039640)
4201b274:  addx4	a11, a11, a12
4201b277:  l32i.n	a11, a11, 0
4201b279:  jx	a11
4201b27c:  excw
4201b27f:  add.n	a0, a6, a9
4201b281:  l8ui	a12, a0, 173
4201b284:  ball	a6, a0, 0x4201b234
4201b287:  addx4	a11, a2, a0
4201b28a:  add.n	a11, a7, a6
4201b28c:  l32i.n	a1, a3, 12
4201b28e:  bltu	a11, a8, 0x4201b29c
4201b291:  movi.n	a11, 76
4201b293:  beq	a8, a11, 0x4201b2bd
4201b296:  movi	a11, 104
4201b299:  j	0x4201b2b4
L_4201b29c:
4201b29c:  movi	a11, 113
4201b29f:  beq	a8, a11, 0x4201b2c2
4201b2a2:  movi	a11, 112
4201b2a5:  bgeu	a11, a8, 0x4201b2cc
4201b2a8:  movi	a11, 116
4201b2ab:  bne	a8, a11, 0x4201b2b1
4201b2ae:  j	0x4201b59d
L_4201b2b1:
4201b2b1:  movi	a11, 122
L_4201b2b4:
4201b2b4:  bne	a8, a11, 0x4201b2ba
4201b2b7:  j	0x4201b59d
L_4201b2ba:
4201b2ba:  j	0x4201b2cc
L_4201b2bd:
4201b2bd:  movi.n	a8, 8
4201b2bf:  j	0x4201b2c4
L_4201b2c2:
4201b2c2:  movi.n	a8, 32
L_4201b2c4:
4201b2c4:  or	a6, a6, a8
4201b2c7:  j	0x4201b59d
4201b2ca:  mulsh	a0, a0, a0
4201b2cd:  add.n	a0, a1, a0
4201b2cf:  movi	a8, 108
4201b2d2:  bne	a11, a8, 0x4201b2e0
4201b2d5:  movi.n	a8, 32
4201b2d7:  or	a6, a6, a8
4201b2da:  addi.n	a7, a10, 2
4201b2dc:  j	0x4201b59d
4201b2df:  lsx	f1, a12, a0
4201b2e2:  j	0x4201b2c4
4201b2e5:  movi	a11, 97
4201b2e8:  extui	a10, a2, 0, 5
4201b2eb:  bne	a8, a11, 0x4201b2f1
4201b2ee:  j	0x4201b686
L_4201b2f1:
4201b2f1:  bltu	a11, a8, 0x4201b330
4201b2f4:  addi	a8, a8, -65
4201b2f7:  extui	a8, a8, 0, 8
4201b2fa:  movi.n	a11, 23
4201b2fc:  bgeu	a11, a8, 0x4201b324
4201b2ff:  j	0x4201b35d
L_4201b302:
4201b302:  movi.n	a8, 1
4201b304:  ssl	a11
4201b307:  sll	a8, a8
4201b30a:  l32r	a11, 0x420011d4 (0x120821)
4201b30d:  bany	a8, a11, 0x4201b344
4201b310:  movi.n	a11, 37
4201b312:  slli	a11, a11, 10
4201b315:  bnone	a8, a11, 0x4201b31b
4201b318:  j	0x4201b691
L_4201b31b:
4201b31b:  extui	a8, a8, 1, 3
4201b31e:  bnez	a8, 0x4201b686
4201b321:  j	0x4201b35d
L_4201b324:
4201b324:  l32r	a11, 0x42001244 (0x3c039660)
4201b327:  addx4	a8, a8, a11
4201b32a:  l32i.n	a8, a8, 0
4201b32c:  jx	a8
4201b32f:  addx4	a11, a2, a0
4201b332:  excw
4201b335:  s32i.n	a1, a2, 32
4201b337:  l32i.n	a12, a12, 36
4201b339:  extui	a11, a8, 0, 8
4201b33c:  movi.n	a8, 20
4201b33e:  bgeu	a8, a11, 0x4201b302
4201b341:  j	0x4201b35d
L_4201b344:
4201b344:  extui	a5, a6, 5, 1
4201b347:  add.n	a5, a5, a5
4201b349:  bbci	a6, 4, 0x4201b35d
4201b34c:  j	0x4201b6b0
4201b34f:  extui	a1, a0, 28, 1
4201b352:  and	a5, a6, a5
4201b355:  bnez	a5, 0x4201b6a5
4201b358:  j	0x4201b69c
4201b35b:  excw
4201b35e:  lsi	f0, a11, 0x220
4201b361:  l32r	a1, 0x41fddc18
4201b364:  addx4	a8, a3, a8
4201b367:  s32i.n	a5, a8, 0
4201b369:  j	0x4201b59d
4201b36c:  addi.n	a11, a5, -1
4201b36e:  l32i.n	a8, a4, 8
4201b370:  addi.n	a2, a10, 1
4201b372:  bltui	a11, 6, 0x4201b378
4201b375:  j	0x4201b419
L_4201b378:
4201b378:  l32r	a12, 0x42001248 (0x3c0396c0)
4201b37b:  addx4	a11, a11, a12
4201b37e:  l32i.n	a12, a11, 0
4201b380:  extui	a11, a10, 0, 16
4201b383:  jx	a12
4201b386:  l32i.n	a8, a1, 0
4201b388:  l32i.n	a11, a4, 8
4201b38a:  addi.n	a2, a10, 1
4201b38c:  addx8	a10, a10, a8
4201b38f:  addi.n	a8, a11, 4
4201b391:  s32i.n	a8, a4, 8
4201b393:  movi.n	a12, 24
4201b395:  blt	a12, a8, 0x4201b39d
4201b398:  l32i.n	a11, a4, 4
4201b39a:  j	0x4201b3a6
L_4201b39d:
4201b39d:  blt	a12, a11, 0x4201b3a2
4201b3a0:  movi.n	a8, 36
L_4201b3a2:
4201b3a2:  l32i.n	a11, a4, 0
4201b3a4:  s32i.n	a8, a4, 8
L_4201b3a6:
4201b3a6:  add.n	a11, a11, a8
4201b3a8:  addi	a11, a11, -4
4201b3ab:  l32i.n	a8, a11, 0
4201b3ad:  movi.n	a3, -1
4201b3af:  s32i.n	a8, a10, 0
4201b3b1:  movi.n	a5, 1
4201b3b3:  j	0x4201b59d
4201b3b6:  movi.n	a10, -8
4201b3b8:  addi.n	a8, a8, 7
4201b3ba:  and	a8, a8, a10
4201b3bd:  l32i.n	a9, a1, 0
4201b3bf:  addi.n	a10, a8, 8
4201b3c1:  s32i.n	a10, a4, 8
4201b3c3:  movi.n	a12, 24
4201b3c5:  addx8	a11, a11, a9
4201b3c8:  blt	a12, a10, 0x4201b3d0
4201b3cb:  l32i.n	a8, a4, 4
4201b3cd:  j	0x4201b3d9
L_4201b3d0:
4201b3d0:  blt	a12, a8, 0x4201b3d5
4201b3d3:  movi.n	a10, 40
L_4201b3d5:
4201b3d5:  l32i.n	a8, a4, 0
4201b3d7:  s32i.n	a10, a4, 8
L_4201b3d9:
4201b3d9:  add.n	a8, a8, a10
4201b3db:  addi	a8, a8, -8
4201b3de:  l32i.n	a9, a8, 4
4201b3e0:  l32i.n	a8, a8, 0
4201b3e2:  s32i.n	a9, a11, 4
4201b3e4:  s32i.n	a8, a11, 0
4201b3e6:  j	0x4201b59d
4201b3e9:  l32i.n	a8, a1, 0
4201b3eb:  l32i.n	a11, a4, 8
4201b3ed:  addi.n	a2, a10, 1
4201b3ef:  addx8	a10, a10, a8
4201b3f2:  addi.n	a8, a11, 4
4201b3f4:  s32i.n	a8, a4, 8
4201b3f6:  movi.n	a12, 24
4201b3f8:  blt	a12, a8, 0x4201b400
4201b3fb:  l32i.n	a11, a4, 4
4201b3fd:  j	0x4201b409
---- end objdump fallback ---- */
