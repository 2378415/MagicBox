/* WARNING: Control flow encountered bad instruction data */
/* (1 unreachable decompiler blocks omitted) */

void FUN_4202206c(int param_1,char *param_2,int *param_3,int *param_4,int param_5,int param_6,
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
4202206c:  entry	a1, 64
4202206f:  l32i	a8, a1, 64
42022072:  s32i.n	a7, a1, 4
42022074:  l32i.n	a7, a8, 0
42022076:  s32i.n	a2, a1, 8
42022078:  l32i.n	a14, a1, 8
4202207a:  l32i.n	a2, a5, 0
4202207c:  s32i.n	a5, a1, 16
4202207e:  s32i.n	a6, a1, 0
42022080:  moveqz	a7, a3, a7
42022083:  j	0x42022413
L_42022086:
42022086:  addi.n	a7, a7, 1
42022088:  l8ui	a8, a7, 0
4202208b:  beqz	a8, 0x420224be
4202208e:  addi	a10, a8, -37
42022091:  bnez	a10, 0x42022086
42022094:  beqz	a8, 0x420224be
42022097:  movi.n	a8, 0
42022099:  addi.n	a10, a7, 1
4202209b:  movi.n	a5, 0
4202209d:  movi.n	a13, 0
4202209f:  movi.n	a3, -1
420220a1:  movi.n	a6, 0
420220a3:  s32i.n	a8, a1, 12
420220a5:  j	0x420220aa
420220a8:  mov.n	a10, a7
L_420220aa:
420220aa:  l32r	a9, 0x420011c4 (0x3c039ef4)
420220ad:  l8ui	a8, a10, 0
420220b0:  addi.n	a7, a10, 1
420220b2:  add.n	a11, a9, a8
420220b4:  l32i.n	a9, a1, 12
420220b6:  l8ui	a12, a11, 0
420220b9:  l32r	a11, 0x420011c8 (0x3c039e88)
420220bc:  addx8	a15, a9, a9
420220bf:  add.n	a11, a11, a15
420220c1:  add.n	a11, a11, a12
420220c3:  l8ui	a9, a11, 0
420220c6:  l32r	a11, 0x420011cc (0x3c039e1c)
420220c9:  s32i.n	a9, a1, 12
420220cb:  add.n	a11, a11, a15
420220cd:  add.n	a11, a11, a12
420220cf:  l8ui	a11, a11, 0
420220d2:  addi.n	a11, a11, -1
420220d4:  extui	a11, a11, 0, 8
420220d7:  bltui	a11, 8, 0x420220dd
420220da:  j	0x42022409
L_420220dd:
420220dd:  l32r	a12, 0x42001320 (0x3c039be0)
420220e0:  addx4	a11, a11, a12
420220e3:  l32i.n	a11, a11, 0
420220e5:  jx	a11
420220e8:  excw
420220eb:  add.n	a0, a6, a9
420220ed:  l8ui	a12, a0, 173
420220f0:  ball	a6, a0, 0x420220a0
420220f3:  addx4	a11, a2, a0
420220f6:  add.n	a11, a7, a6
420220f8:  l32i.n	a1, a3, 12
420220fa:  bltu	a11, a8, 0x42022108
420220fd:  movi.n	a11, 76
420220ff:  beq	a8, a11, 0x42022129
42022102:  movi	a11, 104
42022105:  j	0x42022120
L_42022108:
42022108:  movi	a11, 113
4202210b:  beq	a8, a11, 0x4202212e
4202210e:  movi	a11, 112
42022111:  bgeu	a11, a8, 0x42022138
42022114:  movi	a11, 116
42022117:  bne	a8, a11, 0x4202211d
4202211a:  j	0x42022409
L_4202211d:
4202211d:  movi	a11, 122
L_42022120:
42022120:  bne	a8, a11, 0x42022126
42022123:  j	0x42022409
L_42022126:
42022126:  j	0x42022138
L_42022129:
42022129:  movi.n	a8, 8
4202212b:  j	0x42022130
L_4202212e:
4202212e:  movi.n	a8, 32
L_42022130:
42022130:  or	a6, a6, a8
42022133:  j	0x42022409
42022136:  mulsh	a0, a0, a0
42022139:  add.n	a0, a1, a0
4202213b:  movi	a8, 108
4202213e:  bne	a11, a8, 0x4202214c
42022141:  movi.n	a8, 32
42022143:  or	a6, a6, a8
42022146:  addi.n	a7, a10, 2
42022148:  j	0x42022409
4202214b:  lsx	f1, a12, a0
4202214e:  j	0x42022130
42022151:  movi	a11, 97
42022154:  extui	a10, a2, 0, 5
42022157:  bne	a8, a11, 0x4202215d
4202215a:  j	0x420224f2
L_4202215d:
4202215d:  bltu	a11, a8, 0x4202219c
42022160:  addi	a8, a8, -65
42022163:  extui	a8, a8, 0, 8
42022166:  movi.n	a11, 23
42022168:  bgeu	a11, a8, 0x42022190
4202216b:  j	0x420221c9
L_4202216e:
4202216e:  movi.n	a8, 1
42022170:  ssl	a11
42022173:  sll	a8, a8
42022176:  l32r	a11, 0x420011d4 (0x120821)
42022179:  bany	a8, a11, 0x420221b0
4202217c:  movi.n	a11, 37
4202217e:  slli	a11, a11, 10
42022181:  bnone	a8, a11, 0x42022187
42022184:  j	0x420224fd
L_42022187:
42022187:  extui	a8, a8, 1, 3
4202218a:  bnez	a8, 0x420224f2
4202218d:  j	0x420221c9
L_42022190:
42022190:  l32r	a11, 0x42001324 (0x3c039c00)
42022193:  addx4	a8, a8, a11
42022196:  l32i.n	a8, a8, 0
42022198:  jx	a8
4202219b:  addx4	a11, a2, a0
4202219e:  excw
420221a1:  s32i.n	a1, a2, 32
420221a3:  l32i.n	a12, a12, 36
420221a5:  extui	a11, a8, 0, 8
420221a8:  movi.n	a8, 20
420221aa:  bgeu	a8, a11, 0x4202216e
420221ad:  j	0x420221c9
L_420221b0:
420221b0:  extui	a5, a6, 5, 1
420221b3:  add.n	a5, a5, a5
420221b5:  bbci	a6, 4, 0x420221c9
420221b8:  j	0x4202251c
420221bb:  extui	a1, a0, 28, 1
420221be:  and	a5, a6, a5
420221c1:  bnez	a5, 0x42022511
420221c4:  j	0x42022508
420221c7:  excw
420221ca:  lsi	f0, a11, 0x220
420221cd:  l32r	a1, 0x41fe4a84
420221d0:  addx4	a8, a3, a8
420221d3:  s32i.n	a5, a8, 0
420221d5:  j	0x42022409
420221d8:  addi.n	a11, a5, -1
420221da:  l32i.n	a8, a4, 8
420221dc:  addi.n	a2, a10, 1
420221de:  bltui	a11, 6, 0x420221e4
420221e1:  j	0x42022285
L_420221e4:
420221e4:  l32r	a12, 0x42001328 (0x3c039c60)
420221e7:  addx4	a11, a11, a12
420221ea:  l32i.n	a12, a11, 0
420221ec:  extui	a11, a10, 0, 16
420221ef:  jx	a12
420221f2:  l32i.n	a8, a1, 0
420221f4:  l32i.n	a11, a4, 8
420221f6:  addi.n	a2, a10, 1
420221f8:  addx8	a10, a10, a8
420221fb:  addi.n	a8, a11, 4
420221fd:  s32i.n	a8, a4, 8
420221ff:  movi.n	a12, 24
42022201:  blt	a12, a8, 0x42022209
42022204:  l32i.n	a11, a4, 4
42022206:  j	0x42022212
L_42022209:
42022209:  blt	a12, a11, 0x4202220e
4202220c:  movi.n	a8, 36
L_4202220e:
4202220e:  l32i.n	a11, a4, 0
42022210:  s32i.n	a8, a4, 8
L_42022212:
42022212:  add.n	a11, a11, a8
42022214:  addi	a11, a11, -4
42022217:  l32i.n	a8, a11, 0
42022219:  movi.n	a3, -1
4202221b:  s32i.n	a8, a10, 0
4202221d:  movi.n	a5, 1
4202221f:  j	0x42022409
42022222:  movi.n	a10, -8
42022224:  addi.n	a8, a8, 7
42022226:  and	a8, a8, a10
42022229:  l32i.n	a9, a1, 0
4202222b:  addi.n	a10, a8, 8
4202222d:  s32i.n	a10, a4, 8
4202222f:  movi.n	a12, 24
42022231:  addx8	a11, a11, a9
42022234:  blt	a12, a10, 0x4202223c
42022237:  l32i.n	a8, a4, 4
42022239:  j	0x42022245
L_4202223c:
4202223c:  blt	a12, a8, 0x42022241
4202223f:  movi.n	a10, 40
L_42022241:
42022241:  l32i.n	a8, a4, 0
42022243:  s32i.n	a10, a4, 8
L_42022245:
42022245:  add.n	a8, a8, a10
42022247:  addi	a8, a8, -8
4202224a:  l32i.n	a9, a8, 4
4202224c:  l32i.n	a8, a8, 0
4202224e:  s32i.n	a9, a11, 4
42022250:  s32i.n	a8, a11, 0
42022252:  j	0x42022409
42022255:  l32i.n	a8, a1, 0
42022257:  l32i.n	a11, a4, 8
42022259:  addi.n	a2, a10, 1
4202225b:  addx8	a10, a10, a8
4202225e:  addi.n	a8, a11, 4
42022260:  s32i.n	a8, a4, 8
42022262:  movi.n	a12, 24
42022264:  blt	a12, a8, 0x4202226c
42022267:  l32i.n	a11, a4, 4
42022269:  j	0x42022275
---- end objdump fallback ---- */
