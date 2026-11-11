/* WARNING: Control flow encountered bad instruction data */
/* (1 unreachable decompiler blocks omitted) */

void FUN_42020c30(int param_1,char *param_2,int *param_3,int *param_4,int param_5,int param_6,
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
42020c30:  entry	a1, 64
42020c33:  l32i	a8, a1, 64
42020c36:  s32i.n	a7, a1, 4
42020c38:  l32i.n	a7, a8, 0
42020c3a:  s32i.n	a2, a1, 8
42020c3c:  l32i.n	a14, a1, 8
42020c3e:  l32i.n	a2, a5, 0
42020c40:  s32i.n	a5, a1, 16
42020c42:  s32i.n	a6, a1, 0
42020c44:  moveqz	a7, a3, a7
42020c47:  j	0x42020fd7
L_42020c4a:
42020c4a:  addi.n	a7, a7, 1
42020c4c:  l8ui	a8, a7, 0
42020c4f:  beqz	a8, 0x42021082
42020c52:  addi	a10, a8, -37
42020c55:  bnez	a10, 0x42020c4a
42020c58:  beqz	a8, 0x42021082
42020c5b:  movi.n	a8, 0
42020c5d:  addi.n	a10, a7, 1
42020c5f:  movi.n	a5, 0
42020c61:  movi.n	a13, 0
42020c63:  movi.n	a3, -1
42020c65:  movi.n	a6, 0
42020c67:  s32i.n	a8, a1, 12
42020c69:  j	0x42020c6e
42020c6c:  mov.n	a10, a7
L_42020c6e:
42020c6e:  l32r	a9, 0x42001ca0 (0x3c040964)
42020c71:  l8ui	a8, a10, 0
42020c74:  addi.n	a7, a10, 1
42020c76:  add.n	a11, a9, a8
42020c78:  l32i.n	a9, a1, 12
42020c7a:  l8ui	a12, a11, 0
42020c7d:  l32r	a11, 0x42001ca4 (0x3c0408f8)
42020c80:  addx8	a15, a9, a9
42020c83:  add.n	a11, a11, a15
42020c85:  add.n	a11, a11, a12
42020c87:  l8ui	a9, a11, 0
42020c8a:  l32r	a11, 0x42001ca8 (0x3c04088c)
42020c8d:  s32i.n	a9, a1, 12
42020c8f:  add.n	a11, a11, a15
42020c91:  add.n	a11, a11, a12
42020c93:  l8ui	a11, a11, 0
42020c96:  addi.n	a11, a11, -1
42020c98:  extui	a11, a11, 0, 8
42020c9b:  bltui	a11, 8, 0x42020ca1
42020c9e:  j	0x42020fcd
L_42020ca1:
42020ca1:  l32r	a12, 0x42001cac (0x3c03fd04)
42020ca4:  addx4	a11, a11, a12
42020ca7:  l32i.n	a11, a11, 0
42020ca9:  jx	a11
42020cac:  excw
42020caf:  add.n	a0, a6, a9
42020cb1:  l8ui	a12, a0, 173
42020cb4:  ball	a6, a0, 0x42020c64
42020cb7:  addx4	a11, a2, a0
42020cba:  add.n	a11, a7, a6
42020cbc:  l32i.n	a1, a3, 12
42020cbe:  bltu	a11, a8, 0x42020ccc
42020cc1:  movi.n	a11, 76
42020cc3:  beq	a8, a11, 0x42020ced
42020cc6:  movi	a11, 104
42020cc9:  j	0x42020ce4
L_42020ccc:
42020ccc:  movi	a11, 113
42020ccf:  beq	a8, a11, 0x42020cf2
42020cd2:  movi	a11, 112
42020cd5:  bgeu	a11, a8, 0x42020cfc
42020cd8:  movi	a11, 116
42020cdb:  bne	a8, a11, 0x42020ce1
42020cde:  j	0x42020fcd
L_42020ce1:
42020ce1:  movi	a11, 122
L_42020ce4:
42020ce4:  bne	a8, a11, 0x42020cea
42020ce7:  j	0x42020fcd
L_42020cea:
42020cea:  j	0x42020cfc
L_42020ced:
42020ced:  movi.n	a8, 8
42020cef:  j	0x42020cf4
L_42020cf2:
42020cf2:  movi.n	a8, 32
L_42020cf4:
42020cf4:  or	a6, a6, a8
42020cf7:  j	0x42020fcd
42020cfa:  mulsh	a0, a0, a0
42020cfd:  add.n	a0, a1, a0
42020cff:  movi	a8, 108
42020d02:  bne	a11, a8, 0x42020d10
42020d05:  movi.n	a8, 32
42020d07:  or	a6, a6, a8
42020d0a:  addi.n	a7, a10, 2
42020d0c:  j	0x42020fcd
42020d0f:  lsx	f1, a12, a0
42020d12:  j	0x42020cf4
42020d15:  movi	a11, 97
42020d18:  extui	a10, a2, 0, 5
42020d1b:  bne	a8, a11, 0x42020d21
42020d1e:  j	0x420210b6
L_42020d21:
42020d21:  bltu	a11, a8, 0x42020d60
42020d24:  addi	a8, a8, -65
42020d27:  extui	a8, a8, 0, 8
42020d2a:  movi.n	a11, 23
42020d2c:  bgeu	a11, a8, 0x42020d54
42020d2f:  j	0x42020d8d
L_42020d32:
42020d32:  movi.n	a8, 1
42020d34:  ssl	a11
42020d37:  sll	a8, a8
42020d3a:  l32r	a11, 0x42001cb0 (0x120821)
42020d3d:  bany	a8, a11, 0x42020d74
42020d40:  movi.n	a11, 37
42020d42:  slli	a11, a11, 10
42020d45:  bnone	a8, a11, 0x42020d4b
42020d48:  j	0x420210c1
L_42020d4b:
42020d4b:  extui	a8, a8, 1, 3
42020d4e:  bnez	a8, 0x420210b6
42020d51:  j	0x42020d8d
L_42020d54:
42020d54:  l32r	a11, 0x42001cb4 (0x3c03fd24)
42020d57:  addx4	a8, a8, a11
42020d5a:  l32i.n	a8, a8, 0
42020d5c:  jx	a8
42020d5f:  addx4	a11, a2, a0
42020d62:  excw
42020d65:  s32i.n	a1, a2, 32
42020d67:  l32i.n	a12, a12, 36
42020d69:  extui	a11, a8, 0, 8
42020d6c:  movi.n	a8, 20
42020d6e:  bgeu	a8, a11, 0x42020d32
42020d71:  j	0x42020d8d
L_42020d74:
42020d74:  extui	a5, a6, 5, 1
42020d77:  add.n	a5, a5, a5
42020d79:  bbci	a6, 4, 0x42020d8d
42020d7c:  j	0x420210e0
42020d7f:  extui	a1, a0, 28, 1
42020d82:  and	a5, a6, a5
42020d85:  bnez	a5, 0x420210d5
42020d88:  j	0x420210cc
42020d8b:  excw
42020d8e:  lsi	f0, a11, 0x220
42020d91:  l32r	a1, 0x41fe3648
42020d94:  addx4	a8, a3, a8
42020d97:  s32i.n	a5, a8, 0
42020d99:  j	0x42020fcd
42020d9c:  addi.n	a11, a5, -1
42020d9e:  l32i.n	a8, a4, 8
42020da0:  addi.n	a2, a10, 1
42020da2:  bltui	a11, 6, 0x42020da8
42020da5:  j	0x42020e49
L_42020da8:
42020da8:  l32r	a12, 0x42001cb8 (0x3c03fd84)
42020dab:  addx4	a11, a11, a12
42020dae:  l32i.n	a12, a11, 0
42020db0:  extui	a11, a10, 0, 16
42020db3:  jx	a12
42020db6:  l32i.n	a8, a1, 0
42020db8:  l32i.n	a11, a4, 8
42020dba:  addi.n	a2, a10, 1
42020dbc:  addx8	a10, a10, a8
42020dbf:  addi.n	a8, a11, 4
42020dc1:  s32i.n	a8, a4, 8
42020dc3:  movi.n	a12, 24
42020dc5:  blt	a12, a8, 0x42020dcd
42020dc8:  l32i.n	a11, a4, 4
42020dca:  j	0x42020dd6
L_42020dcd:
42020dcd:  blt	a12, a11, 0x42020dd2
42020dd0:  movi.n	a8, 36
L_42020dd2:
42020dd2:  l32i.n	a11, a4, 0
42020dd4:  s32i.n	a8, a4, 8
L_42020dd6:
42020dd6:  add.n	a11, a11, a8
42020dd8:  addi	a11, a11, -4
42020ddb:  l32i.n	a8, a11, 0
42020ddd:  movi.n	a3, -1
42020ddf:  s32i.n	a8, a10, 0
42020de1:  movi.n	a5, 1
42020de3:  j	0x42020fcd
42020de6:  movi.n	a10, -8
42020de8:  addi.n	a8, a8, 7
42020dea:  and	a8, a8, a10
42020ded:  l32i.n	a9, a1, 0
42020def:  addi.n	a10, a8, 8
42020df1:  s32i.n	a10, a4, 8
42020df3:  movi.n	a12, 24
42020df5:  addx8	a11, a11, a9
42020df8:  blt	a12, a10, 0x42020e00
42020dfb:  l32i.n	a8, a4, 4
42020dfd:  j	0x42020e09
L_42020e00:
42020e00:  blt	a12, a8, 0x42020e05
42020e03:  movi.n	a10, 40
L_42020e05:
42020e05:  l32i.n	a8, a4, 0
42020e07:  s32i.n	a10, a4, 8
L_42020e09:
42020e09:  add.n	a8, a8, a10
42020e0b:  addi	a8, a8, -8
42020e0e:  l32i.n	a9, a8, 4
42020e10:  l32i.n	a8, a8, 0
42020e12:  s32i.n	a9, a11, 4
42020e14:  s32i.n	a8, a11, 0
42020e16:  j	0x42020fcd
42020e19:  l32i.n	a8, a1, 0
42020e1b:  l32i.n	a11, a4, 8
42020e1d:  addi.n	a2, a10, 1
42020e1f:  addx8	a10, a10, a8
42020e22:  addi.n	a8, a11, 4
42020e24:  s32i.n	a8, a4, 8
42020e26:  movi.n	a12, 24
42020e28:  blt	a12, a8, 0x42020e30
42020e2b:  l32i.n	a11, a4, 4
42020e2d:  j	0x42020e39
---- end objdump fallback ---- */
