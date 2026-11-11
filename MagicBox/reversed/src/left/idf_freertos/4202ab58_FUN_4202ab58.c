/* WARNING: Control flow encountered bad instruction data */
/* (1 unreachable decompiler blocks omitted) */

void FUN_4202ab58(int param_1,char *param_2,int *param_3,int *param_4,int param_5,int param_6,
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
4202ab58:  entry	a1, 64
4202ab5b:  l32i	a8, a1, 64
4202ab5e:  s32i.n	a7, a1, 4
4202ab60:  l32i.n	a7, a8, 0
4202ab62:  s32i.n	a2, a1, 8
4202ab64:  l32i.n	a14, a1, 8
4202ab66:  l32i.n	a2, a5, 0
4202ab68:  s32i.n	a5, a1, 16
4202ab6a:  s32i.n	a6, a1, 0
4202ab6c:  moveqz	a7, a3, a7
4202ab6f:  j	0x4202aeff
L_4202ab72:
4202ab72:  addi.n	a7, a7, 1
4202ab74:  l8ui	a8, a7, 0
4202ab77:  beqz	a8, 0x4202afaa
4202ab7a:  addi	a10, a8, -37
4202ab7d:  bnez	a10, 0x4202ab72
4202ab80:  beqz	a8, 0x4202afaa
4202ab83:  movi.n	a8, 0
4202ab85:  addi.n	a10, a7, 1
4202ab87:  movi.n	a5, 0
4202ab89:  movi.n	a13, 0
4202ab8b:  movi.n	a3, -1
4202ab8d:  movi.n	a6, 0
4202ab8f:  s32i.n	a8, a1, 12
4202ab91:  j	0x4202ab96
4202ab94:  mov.n	a10, a7
L_4202ab96:
4202ab96:  l32r	a9, 0x42001ca0 (0x3c040964)
4202ab99:  l8ui	a8, a10, 0
4202ab9c:  addi.n	a7, a10, 1
4202ab9e:  add.n	a11, a9, a8
4202aba0:  l32i.n	a9, a1, 12
4202aba2:  l8ui	a12, a11, 0
4202aba5:  l32r	a11, 0x42001ca4 (0x3c0408f8)
4202aba8:  addx8	a15, a9, a9
4202abab:  add.n	a11, a11, a15
4202abad:  add.n	a11, a11, a12
4202abaf:  l8ui	a9, a11, 0
4202abb2:  l32r	a11, 0x42001ca8 (0x3c04088c)
4202abb5:  s32i.n	a9, a1, 12
4202abb7:  add.n	a11, a11, a15
4202abb9:  add.n	a11, a11, a12
4202abbb:  l8ui	a11, a11, 0
4202abbe:  addi.n	a11, a11, -1
4202abc0:  extui	a11, a11, 0, 8
4202abc3:  bltui	a11, 8, 0x4202abc9
4202abc6:  j	0x4202aef5
L_4202abc9:
4202abc9:  l32r	a12, 0x42001dcc (0x3c040650)
4202abcc:  addx4	a11, a11, a12
4202abcf:  l32i.n	a11, a11, 0
4202abd1:  jx	a11
4202abd4:  excw
4202abd7:  add.n	a0, a6, a9
4202abd9:  l8ui	a12, a0, 173
4202abdc:  ball	a6, a0, 0x4202ab8c
4202abdf:  addx4	a11, a2, a0
4202abe2:  add.n	a11, a7, a6
4202abe4:  l32i.n	a1, a3, 12
4202abe6:  bltu	a11, a8, 0x4202abf4
4202abe9:  movi.n	a11, 76
4202abeb:  beq	a8, a11, 0x4202ac15
4202abee:  movi	a11, 104
4202abf1:  j	0x4202ac0c
L_4202abf4:
4202abf4:  movi	a11, 113
4202abf7:  beq	a8, a11, 0x4202ac1a
4202abfa:  movi	a11, 112
4202abfd:  bgeu	a11, a8, 0x4202ac24
4202ac00:  movi	a11, 116
4202ac03:  bne	a8, a11, 0x4202ac09
4202ac06:  j	0x4202aef5
L_4202ac09:
4202ac09:  movi	a11, 122
L_4202ac0c:
4202ac0c:  bne	a8, a11, 0x4202ac12
4202ac0f:  j	0x4202aef5
L_4202ac12:
4202ac12:  j	0x4202ac24
L_4202ac15:
4202ac15:  movi.n	a8, 8
4202ac17:  j	0x4202ac1c
L_4202ac1a:
4202ac1a:  movi.n	a8, 32
L_4202ac1c:
4202ac1c:  or	a6, a6, a8
4202ac1f:  j	0x4202aef5
4202ac22:  mulsh	a0, a0, a0
4202ac25:  add.n	a0, a1, a0
4202ac27:  movi	a8, 108
4202ac2a:  bne	a11, a8, 0x4202ac38
4202ac2d:  movi.n	a8, 32
4202ac2f:  or	a6, a6, a8
4202ac32:  addi.n	a7, a10, 2
4202ac34:  j	0x4202aef5
4202ac37:  lsx	f1, a12, a0
4202ac3a:  j	0x4202ac1c
4202ac3d:  movi	a11, 97
4202ac40:  extui	a10, a2, 0, 5
4202ac43:  bne	a8, a11, 0x4202ac49
4202ac46:  j	0x4202afde
L_4202ac49:
4202ac49:  bltu	a11, a8, 0x4202ac88
4202ac4c:  addi	a8, a8, -65
4202ac4f:  extui	a8, a8, 0, 8
4202ac52:  movi.n	a11, 23
4202ac54:  bgeu	a11, a8, 0x4202ac7c
4202ac57:  j	0x4202acb5
L_4202ac5a:
4202ac5a:  movi.n	a8, 1
4202ac5c:  ssl	a11
4202ac5f:  sll	a8, a8
4202ac62:  l32r	a11, 0x42001cb0 (0x120821)
4202ac65:  bany	a8, a11, 0x4202ac9c
4202ac68:  movi.n	a11, 37
4202ac6a:  slli	a11, a11, 10
4202ac6d:  bnone	a8, a11, 0x4202ac73
4202ac70:  j	0x4202afe9
L_4202ac73:
4202ac73:  extui	a8, a8, 1, 3
4202ac76:  bnez	a8, 0x4202afde
4202ac79:  j	0x4202acb5
L_4202ac7c:
4202ac7c:  l32r	a11, 0x42001dd0 (0x3c040670)
4202ac7f:  addx4	a8, a8, a11
4202ac82:  l32i.n	a8, a8, 0
4202ac84:  jx	a8
4202ac87:  addx4	a11, a2, a0
4202ac8a:  excw
4202ac8d:  s32i.n	a1, a2, 32
4202ac8f:  l32i.n	a12, a12, 36
4202ac91:  extui	a11, a8, 0, 8
4202ac94:  movi.n	a8, 20
4202ac96:  bgeu	a8, a11, 0x4202ac5a
4202ac99:  j	0x4202acb5
L_4202ac9c:
4202ac9c:  extui	a5, a6, 5, 1
4202ac9f:  add.n	a5, a5, a5
4202aca1:  bbci	a6, 4, 0x4202acb5
4202aca4:  j	0x4202b008
4202aca7:  extui	a1, a0, 28, 1
4202acaa:  and	a5, a6, a5
4202acad:  bnez	a5, 0x4202affd
4202acb0:  j	0x4202aff4
4202acb3:  excw
4202acb6:  lsi	f0, a11, 0x220
4202acb9:  l32r	a1, 0x41fed570
4202acbc:  addx4	a8, a3, a8
4202acbf:  s32i.n	a5, a8, 0
4202acc1:  j	0x4202aef5
4202acc4:  addi.n	a11, a5, -1
4202acc6:  l32i.n	a8, a4, 8
4202acc8:  addi.n	a2, a10, 1
4202acca:  bltui	a11, 6, 0x4202acd0
4202accd:  j	0x4202ad71
L_4202acd0:
4202acd0:  l32r	a12, 0x42001dd4 (0x3c0406d0)
4202acd3:  addx4	a11, a11, a12
4202acd6:  l32i.n	a12, a11, 0
4202acd8:  extui	a11, a10, 0, 16
4202acdb:  jx	a12
4202acde:  l32i.n	a8, a1, 0
4202ace0:  l32i.n	a11, a4, 8
4202ace2:  addi.n	a2, a10, 1
4202ace4:  addx8	a10, a10, a8
4202ace7:  addi.n	a8, a11, 4
4202ace9:  s32i.n	a8, a4, 8
4202aceb:  movi.n	a12, 24
4202aced:  blt	a12, a8, 0x4202acf5
4202acf0:  l32i.n	a11, a4, 4
4202acf2:  j	0x4202acfe
L_4202acf5:
4202acf5:  blt	a12, a11, 0x4202acfa
4202acf8:  movi.n	a8, 36
L_4202acfa:
4202acfa:  l32i.n	a11, a4, 0
4202acfc:  s32i.n	a8, a4, 8
L_4202acfe:
4202acfe:  add.n	a11, a11, a8
4202ad00:  addi	a11, a11, -4
4202ad03:  l32i.n	a8, a11, 0
4202ad05:  movi.n	a3, -1
4202ad07:  s32i.n	a8, a10, 0
4202ad09:  movi.n	a5, 1
4202ad0b:  j	0x4202aef5
4202ad0e:  movi.n	a10, -8
4202ad10:  addi.n	a8, a8, 7
4202ad12:  and	a8, a8, a10
4202ad15:  l32i.n	a9, a1, 0
4202ad17:  addi.n	a10, a8, 8
4202ad19:  s32i.n	a10, a4, 8
4202ad1b:  movi.n	a12, 24
4202ad1d:  addx8	a11, a11, a9
4202ad20:  blt	a12, a10, 0x4202ad28
4202ad23:  l32i.n	a8, a4, 4
4202ad25:  j	0x4202ad31
L_4202ad28:
4202ad28:  blt	a12, a8, 0x4202ad2d
4202ad2b:  movi.n	a10, 40
L_4202ad2d:
4202ad2d:  l32i.n	a8, a4, 0
4202ad2f:  s32i.n	a10, a4, 8
L_4202ad31:
4202ad31:  add.n	a8, a8, a10
4202ad33:  addi	a8, a8, -8
4202ad36:  l32i.n	a9, a8, 4
4202ad38:  l32i.n	a8, a8, 0
4202ad3a:  s32i.n	a9, a11, 4
4202ad3c:  s32i.n	a8, a11, 0
4202ad3e:  j	0x4202aef5
4202ad41:  l32i.n	a8, a1, 0
4202ad43:  l32i.n	a11, a4, 8
4202ad45:  addi.n	a2, a10, 1
4202ad47:  addx8	a10, a10, a8
4202ad4a:  addi.n	a8, a11, 4
4202ad4c:  s32i.n	a8, a4, 8
4202ad4e:  movi.n	a12, 24
4202ad50:  blt	a12, a8, 0x4202ad58
4202ad53:  l32i.n	a11, a4, 4
4202ad55:  j	0x4202ad61
---- end objdump fallback ---- */
