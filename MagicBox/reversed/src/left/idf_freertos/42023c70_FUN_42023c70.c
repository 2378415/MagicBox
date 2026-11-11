/* WARNING: Control flow encountered bad instruction data */
/* (1 unreachable decompiler blocks omitted) */

void FUN_42023c70(int param_1,char *param_2,int *param_3,int *param_4,int param_5,int param_6,
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
42023c70:  entry	a1, 64
42023c73:  l32i	a8, a1, 64
42023c76:  s32i.n	a7, a1, 4
42023c78:  l32i.n	a7, a8, 0
42023c7a:  s32i.n	a2, a1, 8
42023c7c:  l32i.n	a14, a1, 8
42023c7e:  l32i.n	a2, a5, 0
42023c80:  s32i.n	a5, a1, 16
42023c82:  s32i.n	a6, a1, 0
42023c84:  moveqz	a7, a3, a7
42023c87:  j	0x42024017
L_42023c8a:
42023c8a:  addi.n	a7, a7, 1
42023c8c:  l8ui	a8, a7, 0
42023c8f:  beqz	a8, 0x420240c2
42023c92:  addi	a10, a8, -37
42023c95:  bnez	a10, 0x42023c8a
42023c98:  beqz	a8, 0x420240c2
42023c9b:  movi.n	a8, 0
42023c9d:  addi.n	a10, a7, 1
42023c9f:  movi.n	a5, 0
42023ca1:  movi.n	a13, 0
42023ca3:  movi.n	a3, -1
42023ca5:  movi.n	a6, 0
42023ca7:  s32i.n	a8, a1, 12
42023ca9:  j	0x42023cae
42023cac:  mov.n	a10, a7
L_42023cae:
42023cae:  l32r	a9, 0x42001ca0 (0x3c040964)
42023cb1:  l8ui	a8, a10, 0
42023cb4:  addi.n	a7, a10, 1
42023cb6:  add.n	a11, a9, a8
42023cb8:  l32i.n	a9, a1, 12
42023cba:  l8ui	a12, a11, 0
42023cbd:  l32r	a11, 0x42001ca4 (0x3c0408f8)
42023cc0:  addx8	a15, a9, a9
42023cc3:  add.n	a11, a11, a15
42023cc5:  add.n	a11, a11, a12
42023cc7:  l8ui	a9, a11, 0
42023cca:  l32r	a11, 0x42001ca8 (0x3c04088c)
42023ccd:  s32i.n	a9, a1, 12
42023ccf:  add.n	a11, a11, a15
42023cd1:  add.n	a11, a11, a12
42023cd3:  l8ui	a11, a11, 0
42023cd6:  addi.n	a11, a11, -1
42023cd8:  extui	a11, a11, 0, 8
42023cdb:  bltui	a11, 8, 0x42023ce1
42023cde:  j	0x4202400d
L_42023ce1:
42023ce1:  l32r	a12, 0x42001d00 (0x3c03ff40)
42023ce4:  addx4	a11, a11, a12
42023ce7:  l32i.n	a11, a11, 0
42023ce9:  jx	a11
42023cec:  excw
42023cef:  add.n	a0, a6, a9
42023cf1:  l8ui	a12, a0, 173
42023cf4:  ball	a6, a0, 0x42023ca4
42023cf7:  addx4	a11, a2, a0
42023cfa:  add.n	a11, a7, a6
42023cfc:  l32i.n	a1, a3, 12
42023cfe:  bltu	a11, a8, 0x42023d0c
42023d01:  movi.n	a11, 76
42023d03:  beq	a8, a11, 0x42023d2d
42023d06:  movi	a11, 104
42023d09:  j	0x42023d24
L_42023d0c:
42023d0c:  movi	a11, 113
42023d0f:  beq	a8, a11, 0x42023d32
42023d12:  movi	a11, 112
42023d15:  bgeu	a11, a8, 0x42023d3c
42023d18:  movi	a11, 116
42023d1b:  bne	a8, a11, 0x42023d21
42023d1e:  j	0x4202400d
L_42023d21:
42023d21:  movi	a11, 122
L_42023d24:
42023d24:  bne	a8, a11, 0x42023d2a
42023d27:  j	0x4202400d
L_42023d2a:
42023d2a:  j	0x42023d3c
L_42023d2d:
42023d2d:  movi.n	a8, 8
42023d2f:  j	0x42023d34
L_42023d32:
42023d32:  movi.n	a8, 32
L_42023d34:
42023d34:  or	a6, a6, a8
42023d37:  j	0x4202400d
42023d3a:  mulsh	a0, a0, a0
42023d3d:  add.n	a0, a1, a0
42023d3f:  movi	a8, 108
42023d42:  bne	a11, a8, 0x42023d50
42023d45:  movi.n	a8, 32
42023d47:  or	a6, a6, a8
42023d4a:  addi.n	a7, a10, 2
42023d4c:  j	0x4202400d
42023d4f:  lsx	f1, a12, a0
42023d52:  j	0x42023d34
42023d55:  movi	a11, 97
42023d58:  extui	a10, a2, 0, 5
42023d5b:  bne	a8, a11, 0x42023d61
42023d5e:  j	0x420240f6
L_42023d61:
42023d61:  bltu	a11, a8, 0x42023da0
42023d64:  addi	a8, a8, -65
42023d67:  extui	a8, a8, 0, 8
42023d6a:  movi.n	a11, 23
42023d6c:  bgeu	a11, a8, 0x42023d94
42023d6f:  j	0x42023dcd
L_42023d72:
42023d72:  movi.n	a8, 1
42023d74:  ssl	a11
42023d77:  sll	a8, a8
42023d7a:  l32r	a11, 0x42001cb0 (0x120821)
42023d7d:  bany	a8, a11, 0x42023db4
42023d80:  movi.n	a11, 37
42023d82:  slli	a11, a11, 10
42023d85:  bnone	a8, a11, 0x42023d8b
42023d88:  j	0x42024101
L_42023d8b:
42023d8b:  extui	a8, a8, 1, 3
42023d8e:  bnez	a8, 0x420240f6
42023d91:  j	0x42023dcd
L_42023d94:
42023d94:  l32r	a11, 0x42001d04 (0x3c03ff60)
42023d97:  addx4	a8, a8, a11
42023d9a:  l32i.n	a8, a8, 0
42023d9c:  jx	a8
42023d9f:  addx4	a11, a2, a0
42023da2:  excw
42023da5:  s32i.n	a1, a2, 32
42023da7:  l32i.n	a12, a12, 36
42023da9:  extui	a11, a8, 0, 8
42023dac:  movi.n	a8, 20
42023dae:  bgeu	a8, a11, 0x42023d72
42023db1:  j	0x42023dcd
L_42023db4:
42023db4:  extui	a5, a6, 5, 1
42023db7:  add.n	a5, a5, a5
42023db9:  bbci	a6, 4, 0x42023dcd
42023dbc:  j	0x42024120
42023dbf:  extui	a1, a0, 28, 1
42023dc2:  and	a5, a6, a5
42023dc5:  bnez	a5, 0x42024115
42023dc8:  j	0x4202410c
42023dcb:  excw
42023dce:  lsi	f0, a11, 0x220
42023dd1:  l32r	a1, 0x41fe6688
42023dd4:  addx4	a8, a3, a8
42023dd7:  s32i.n	a5, a8, 0
42023dd9:  j	0x4202400d
42023ddc:  addi.n	a11, a5, -1
42023dde:  l32i.n	a8, a4, 8
42023de0:  addi.n	a2, a10, 1
42023de2:  bltui	a11, 6, 0x42023de8
42023de5:  j	0x42023e89
L_42023de8:
42023de8:  l32r	a12, 0x42001d08 (0x3c03ffc0)
42023deb:  addx4	a11, a11, a12
42023dee:  l32i.n	a12, a11, 0
42023df0:  extui	a11, a10, 0, 16
42023df3:  jx	a12
42023df6:  l32i.n	a8, a1, 0
42023df8:  l32i.n	a11, a4, 8
42023dfa:  addi.n	a2, a10, 1
42023dfc:  addx8	a10, a10, a8
42023dff:  addi.n	a8, a11, 4
42023e01:  s32i.n	a8, a4, 8
42023e03:  movi.n	a12, 24
42023e05:  blt	a12, a8, 0x42023e0d
42023e08:  l32i.n	a11, a4, 4
42023e0a:  j	0x42023e16
L_42023e0d:
42023e0d:  blt	a12, a11, 0x42023e12
42023e10:  movi.n	a8, 36
L_42023e12:
42023e12:  l32i.n	a11, a4, 0
42023e14:  s32i.n	a8, a4, 8
L_42023e16:
42023e16:  add.n	a11, a11, a8
42023e18:  addi	a11, a11, -4
42023e1b:  l32i.n	a8, a11, 0
42023e1d:  movi.n	a3, -1
42023e1f:  s32i.n	a8, a10, 0
42023e21:  movi.n	a5, 1
42023e23:  j	0x4202400d
42023e26:  movi.n	a10, -8
42023e28:  addi.n	a8, a8, 7
42023e2a:  and	a8, a8, a10
42023e2d:  l32i.n	a9, a1, 0
42023e2f:  addi.n	a10, a8, 8
42023e31:  s32i.n	a10, a4, 8
42023e33:  movi.n	a12, 24
42023e35:  addx8	a11, a11, a9
42023e38:  blt	a12, a10, 0x42023e40
42023e3b:  l32i.n	a8, a4, 4
42023e3d:  j	0x42023e49
L_42023e40:
42023e40:  blt	a12, a8, 0x42023e45
42023e43:  movi.n	a10, 40
L_42023e45:
42023e45:  l32i.n	a8, a4, 0
42023e47:  s32i.n	a10, a4, 8
L_42023e49:
42023e49:  add.n	a8, a8, a10
42023e4b:  addi	a8, a8, -8
42023e4e:  l32i.n	a9, a8, 4
42023e50:  l32i.n	a8, a8, 0
42023e52:  s32i.n	a9, a11, 4
42023e54:  s32i.n	a8, a11, 0
42023e56:  j	0x4202400d
42023e59:  l32i.n	a8, a1, 0
42023e5b:  l32i.n	a11, a4, 8
42023e5d:  addi.n	a2, a10, 1
42023e5f:  addx8	a10, a10, a8
42023e62:  addi.n	a8, a11, 4
42023e64:  s32i.n	a8, a4, 8
42023e66:  movi.n	a12, 24
42023e68:  blt	a12, a8, 0x42023e70
42023e6b:  l32i.n	a11, a4, 4
42023e6d:  j	0x42023e79
---- end objdump fallback ---- */
