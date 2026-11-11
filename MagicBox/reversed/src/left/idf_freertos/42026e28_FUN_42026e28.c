/* WARNING: Control flow encountered bad instruction data */
/* (1 unreachable decompiler blocks omitted) */

void FUN_42026e28(int param_1,char *param_2,int *param_3,int *param_4,int param_5,int param_6,
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
42026e28:  entry	a1, 64
42026e2b:  l32i	a8, a1, 64
42026e2e:  s32i.n	a7, a1, 4
42026e30:  l32i.n	a7, a8, 0
42026e32:  s32i.n	a2, a1, 8
42026e34:  l32i.n	a14, a1, 8
42026e36:  l32i.n	a2, a5, 0
42026e38:  s32i.n	a5, a1, 16
42026e3a:  s32i.n	a6, a1, 0
42026e3c:  moveqz	a7, a3, a7
42026e3f:  j	0x420271cf
L_42026e42:
42026e42:  addi.n	a7, a7, 1
42026e44:  l8ui	a8, a7, 0
42026e47:  beqz	a8, 0x4202727a
42026e4a:  addi	a10, a8, -37
42026e4d:  bnez	a10, 0x42026e42
42026e50:  beqz	a8, 0x4202727a
42026e53:  movi.n	a8, 0
42026e55:  addi.n	a10, a7, 1
42026e57:  movi.n	a5, 0
42026e59:  movi.n	a13, 0
42026e5b:  movi.n	a3, -1
42026e5d:  movi.n	a6, 0
42026e5f:  s32i.n	a8, a1, 12
42026e61:  j	0x42026e66
42026e64:  mov.n	a10, a7
L_42026e66:
42026e66:  l32r	a9, 0x42001ca0 (0x3c040964)
42026e69:  l8ui	a8, a10, 0
42026e6c:  addi.n	a7, a10, 1
42026e6e:  add.n	a11, a9, a8
42026e70:  l32i.n	a9, a1, 12
42026e72:  l8ui	a12, a11, 0
42026e75:  l32r	a11, 0x42001ca4 (0x3c0408f8)
42026e78:  addx8	a15, a9, a9
42026e7b:  add.n	a11, a11, a15
42026e7d:  add.n	a11, a11, a12
42026e7f:  l8ui	a9, a11, 0
42026e82:  l32r	a11, 0x42001ca8 (0x3c04088c)
42026e85:  s32i.n	a9, a1, 12
42026e87:  add.n	a11, a11, a15
42026e89:  add.n	a11, a11, a12
42026e8b:  l8ui	a11, a11, 0
42026e8e:  addi.n	a11, a11, -1
42026e90:  extui	a11, a11, 0, 8
42026e93:  bltui	a11, 8, 0x42026e99
42026e96:  j	0x420271c5
L_42026e99:
42026e99:  l32r	a12, 0x42001d38 (0x3c04017c)
42026e9c:  addx4	a11, a11, a12
42026e9f:  l32i.n	a11, a11, 0
42026ea1:  jx	a11
42026ea4:  excw
42026ea7:  add.n	a0, a6, a9
42026ea9:  l8ui	a12, a0, 173
42026eac:  ball	a6, a0, 0x42026e5c
42026eaf:  addx4	a11, a2, a0
42026eb2:  add.n	a11, a7, a6
42026eb4:  l32i.n	a1, a3, 12
42026eb6:  bltu	a11, a8, 0x42026ec4
42026eb9:  movi.n	a11, 76
42026ebb:  beq	a8, a11, 0x42026ee5
42026ebe:  movi	a11, 104
42026ec1:  j	0x42026edc
L_42026ec4:
42026ec4:  movi	a11, 113
42026ec7:  beq	a8, a11, 0x42026eea
42026eca:  movi	a11, 112
42026ecd:  bgeu	a11, a8, 0x42026ef4
42026ed0:  movi	a11, 116
42026ed3:  bne	a8, a11, 0x42026ed9
42026ed6:  j	0x420271c5
L_42026ed9:
42026ed9:  movi	a11, 122
L_42026edc:
42026edc:  bne	a8, a11, 0x42026ee2
42026edf:  j	0x420271c5
L_42026ee2:
42026ee2:  j	0x42026ef4
L_42026ee5:
42026ee5:  movi.n	a8, 8
42026ee7:  j	0x42026eec
L_42026eea:
42026eea:  movi.n	a8, 32
L_42026eec:
42026eec:  or	a6, a6, a8
42026eef:  j	0x420271c5
42026ef2:  mulsh	a0, a0, a0
42026ef5:  add.n	a0, a1, a0
42026ef7:  movi	a8, 108
42026efa:  bne	a11, a8, 0x42026f08
42026efd:  movi.n	a8, 32
42026eff:  or	a6, a6, a8
42026f02:  addi.n	a7, a10, 2
42026f04:  j	0x420271c5
42026f07:  lsx	f1, a12, a0
42026f0a:  j	0x42026eec
42026f0d:  movi	a11, 97
42026f10:  extui	a10, a2, 0, 5
42026f13:  bne	a8, a11, 0x42026f19
42026f16:  j	0x420272ae
L_42026f19:
42026f19:  bltu	a11, a8, 0x42026f58
42026f1c:  addi	a8, a8, -65
42026f1f:  extui	a8, a8, 0, 8
42026f22:  movi.n	a11, 23
42026f24:  bgeu	a11, a8, 0x42026f4c
42026f27:  j	0x42026f85
L_42026f2a:
42026f2a:  movi.n	a8, 1
42026f2c:  ssl	a11
42026f2f:  sll	a8, a8
42026f32:  l32r	a11, 0x42001cb0 (0x120821)
42026f35:  bany	a8, a11, 0x42026f6c
42026f38:  movi.n	a11, 37
42026f3a:  slli	a11, a11, 10
42026f3d:  bnone	a8, a11, 0x42026f43
42026f40:  j	0x420272b9
L_42026f43:
42026f43:  extui	a8, a8, 1, 3
42026f46:  bnez	a8, 0x420272ae
42026f49:  j	0x42026f85
L_42026f4c:
42026f4c:  l32r	a11, 0x42001d3c (0x3c04019c)
42026f4f:  addx4	a8, a8, a11
42026f52:  l32i.n	a8, a8, 0
42026f54:  jx	a8
42026f57:  addx4	a11, a2, a0
42026f5a:  excw
42026f5d:  s32i.n	a1, a2, 32
42026f5f:  l32i.n	a12, a12, 36
42026f61:  extui	a11, a8, 0, 8
42026f64:  movi.n	a8, 20
42026f66:  bgeu	a8, a11, 0x42026f2a
42026f69:  j	0x42026f85
L_42026f6c:
42026f6c:  extui	a5, a6, 5, 1
42026f6f:  add.n	a5, a5, a5
42026f71:  bbci	a6, 4, 0x42026f85
42026f74:  j	0x420272d8
42026f77:  extui	a1, a0, 28, 1
42026f7a:  and	a5, a6, a5
42026f7d:  bnez	a5, 0x420272cd
42026f80:  j	0x420272c4
42026f83:  excw
42026f86:  lsi	f0, a11, 0x220
42026f89:  l32r	a1, 0x41fe9840
42026f8c:  addx4	a8, a3, a8
42026f8f:  s32i.n	a5, a8, 0
42026f91:  j	0x420271c5
42026f94:  addi.n	a11, a5, -1
42026f96:  l32i.n	a8, a4, 8
42026f98:  addi.n	a2, a10, 1
42026f9a:  bltui	a11, 6, 0x42026fa0
42026f9d:  j	0x42027041
L_42026fa0:
42026fa0:  l32r	a12, 0x42001d40 (0x3c0401fc)
42026fa3:  addx4	a11, a11, a12
42026fa6:  l32i.n	a12, a11, 0
42026fa8:  extui	a11, a10, 0, 16
42026fab:  jx	a12
42026fae:  l32i.n	a8, a1, 0
42026fb0:  l32i.n	a11, a4, 8
42026fb2:  addi.n	a2, a10, 1
42026fb4:  addx8	a10, a10, a8
42026fb7:  addi.n	a8, a11, 4
42026fb9:  s32i.n	a8, a4, 8
42026fbb:  movi.n	a12, 24
42026fbd:  blt	a12, a8, 0x42026fc5
42026fc0:  l32i.n	a11, a4, 4
42026fc2:  j	0x42026fce
L_42026fc5:
42026fc5:  blt	a12, a11, 0x42026fca
42026fc8:  movi.n	a8, 36
L_42026fca:
42026fca:  l32i.n	a11, a4, 0
42026fcc:  s32i.n	a8, a4, 8
L_42026fce:
42026fce:  add.n	a11, a11, a8
42026fd0:  addi	a11, a11, -4
42026fd3:  l32i.n	a8, a11, 0
42026fd5:  movi.n	a3, -1
42026fd7:  s32i.n	a8, a10, 0
42026fd9:  movi.n	a5, 1
42026fdb:  j	0x420271c5
42026fde:  movi.n	a10, -8
42026fe0:  addi.n	a8, a8, 7
42026fe2:  and	a8, a8, a10
42026fe5:  l32i.n	a9, a1, 0
42026fe7:  addi.n	a10, a8, 8
42026fe9:  s32i.n	a10, a4, 8
42026feb:  movi.n	a12, 24
42026fed:  addx8	a11, a11, a9
42026ff0:  blt	a12, a10, 0x42026ff8
42026ff3:  l32i.n	a8, a4, 4
42026ff5:  j	0x42027001
L_42026ff8:
42026ff8:  blt	a12, a8, 0x42026ffd
42026ffb:  movi.n	a10, 40
L_42026ffd:
42026ffd:  l32i.n	a8, a4, 0
42026fff:  s32i.n	a10, a4, 8
L_42027001:
42027001:  add.n	a8, a8, a10
42027003:  addi	a8, a8, -8
42027006:  l32i.n	a9, a8, 4
42027008:  l32i.n	a8, a8, 0
4202700a:  s32i.n	a9, a11, 4
4202700c:  s32i.n	a8, a11, 0
4202700e:  j	0x420271c5
42027011:  l32i.n	a8, a1, 0
42027013:  l32i.n	a11, a4, 8
42027015:  addi.n	a2, a10, 1
42027017:  addx8	a10, a10, a8
4202701a:  addi.n	a8, a11, 4
4202701c:  s32i.n	a8, a4, 8
4202701e:  movi.n	a12, 24
42027020:  blt	a12, a8, 0x42027028
42027023:  l32i.n	a11, a4, 4
42027025:  j	0x42027031
---- end objdump fallback ---- */
