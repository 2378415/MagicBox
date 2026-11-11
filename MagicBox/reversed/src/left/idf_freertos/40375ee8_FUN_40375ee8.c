// strings:  0x%08lX:0x%08lX |  |<-CORRUPTED |  |<-CONTINUES

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_40375ee8(int param_1,undefined4 param_2,char param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_40;
  uint uStack_3c;
  int iStack_38;
  int iStack_30;
  
  if (param_1 < 1) {
    return 0x102;
  }
  (*DAT_4037450c)(&local_40,param_2,0x10);
  if (param_3 == '\0') {
    (*DAT_40374438)(PTR_s_Backtrace__4037462c);
    uVar4 = local_40;
    if ((int)local_40 < 0) {
      uVar4 = local_40 & 0x3fffffff | DAT_4037460c;
    }
    (*DAT_40374438)(PTR_s_0x_08lX_0x_08lX_40374638,uVar4 - 3,uStack_3c);
  }
  else {
    (*(code *)PTR_FUN_40374648)();
    uVar4 = uStack_3c;
    uVar3 = local_40;
    if ((int)local_40 < 0) {
      uVar3 = local_40 & 0x3fffffff | DAT_4037460c;
    }
    (*(code *)PTR_FUN_40374648)(PTR_s_0x_3c030f7c_0x48_40374630);
    (*(code *)PTR_FUN_4037464c)(uVar3 - 3);
    (*(code *)PTR_FUN_40374648)(PTR_DAT_40374634);
    (*(code *)PTR_FUN_4037464c)(uVar4);
  }
  uVar4 = DAT_4037460c;
  if (DAT_40374600 < uStack_3c + DAT_403745fc) {
    if (uStack_3c + DAT_40374604 <= DAT_40374608) {
      halt_baddata();
    }
  }
  else if ((uStack_3c & 0xf) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  bVar1 = 1;
  do {
    if (iStack_38 == 0) {
      if (bVar1 != 0) goto LAB_4037607c;
      goto LAB_403760b5;
    }
    if (bVar1 != 0) goto LAB_4037607c;
    bVar1 = FUN_40375e54(&local_40);
    uVar3 = uStack_3c;
    uVar5 = local_40;
    if ((int)local_40 < 0) {
      uVar5 = local_40 & 0x3fffffff | uVar4;
    }
    iStack_30 = uVar5 - 3;
    bVar1 = bVar1 ^ 1;
    if (param_3 == '\0') {
      (*DAT_40374438)(PTR_s_0x_08lX_0x_08lX_40374638,iStack_30,uStack_3c);
    }
    else {
      (*(code *)PTR_FUN_40374648)(PTR_s_0x_3c030f7c_0x48_40374630);
      (*(code *)PTR_FUN_4037464c)(iStack_30);
      (*(code *)PTR_FUN_40374648)(PTR_DAT_40374634);
      (*(code *)PTR_FUN_4037464c)(uVar3);
    }
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  if (bVar1 != 0) {
LAB_4037607c:
    if (param_3 == '\0') {
      (*DAT_40374438)(PTR_s__<_CORRUPTED_4037463c);
      uVar2 = 0xffffffff;
      goto LAB_403760cb;
    }
    (*(code *)PTR_FUN_40374648)();
    uVar2 = 0xffffffff;
    goto LAB_403760bb;
  }
  if (iStack_38 == 0) {
LAB_403760b5:
    if (param_3 == '\0') goto LAB_403760c9;
  }
  else {
    if (param_3 == '\0') {
      (*DAT_40374438)(PTR_s__<_CONTINUES_40374640);
LAB_403760c9:
      uVar2 = 0;
LAB_403760cb:
      (*DAT_40374438)(PTR_DAT_40374644);
      return uVar2;
    }
    (*(code *)PTR_FUN_40374648)();
  }
  uVar2 = 0;
LAB_403760bb:
  (*(code *)PTR_FUN_40374648)(PTR_DAT_40374644);
  return uVar2;
}

/* ---- objdump fallback (Ghidra stopped on excw / literal pool) ----
40375ee8:  entry	a1, 64
40375eeb:  mov.n	a7, a2
40375eed:  mov.n	a11, a3
40375eef:  extui	a4, a4, 0, 8
40375ef2:  movi	a2, 0x102
40375ef5:  bgei	a7, 1, 0x40375efb
40375ef8:  j	0x403760de
L_40375efb:
40375efb:  movi.n	a12, 16
40375efd:  mov.n	a10, a1
40375eff:  l32r	a8, 0x4037450c (0x400011f4)
40375f02:  callx8	a8
40375f05:  l32r	a10, 0x4037462c (0x3c031588)
40375f08:  beqz.n	a4, 0x40375f2c
40375f0a:  l32r	a8, 0x40374648 (0x4200330c)   ; FUN_4200330c
40375f0d:  callx8	a8
40375f10:  l32i.n	a8, a1, 0
40375f12:  l32i.n	a6, a1, 4
40375f14:  addi	a5, a8, -3
40375f17:  bgez	a8, 0x40375f50
40375f1a:  l32r	a9, 0x4037460c (0x40000000)
40375f1d:  slli	a8, a8, 2
40375f20:  srli	a8, a8, 2
40375f23:  or	a8, a8, a9
40375f26:  addi	a5, a8, -3
40375f29:  j	0x40375f50
L_40375f2c:
40375f2c:  l32r	a8, 0x40374438 (0x400005d0)
40375f2f:  callx8	a8
40375f32:  l32i.n	a11, a1, 0
40375f34:  l32i.n	a12, a1, 4
40375f36:  bltz	a11, 0x40375f3c
40375f39:  j	0x40375f48
L_40375f3c:
40375f3c:  l32r	a8, 0x4037460c (0x40000000)
40375f3f:  slli	a11, a11, 2
40375f42:  srli	a11, a11, 2
40375f45:  or	a11, a11, a8
L_40375f48:
40375f48:  addi	a11, a11, -3
40375f4b:  j	0x40375f75
40375f4e:  sll	a0, a0
40375f51:  l32i.n	a11, a9, 60
40375f53:  l32r	a8, 0x40374648 (0x4200330c)   ; FUN_4200330c
40375f56:  callx8	a8
40375f59:  mov.n	a10, a5
40375f5b:  l32r	a8, 0x4037464c (0x42003360)   ; FUN_42003360
40375f5e:  callx8	a8
40375f61:  l32r	a10, 0x40374634 (0x3c031598)
40375f64:  l32r	a8, 0x40374648 (0x4200330c)   ; FUN_4200330c
40375f67:  callx8	a8
40375f6a:  mov.n	a10, a6
40375f6c:  l32r	a8, 0x4037464c (0x42003360)   ; FUN_42003360
40375f6f:  callx8	a8
40375f72:  j	0x40375f7e
L_40375f75:
40375f75:  l32r	a10, 0x40374638 (0x3c03159c)   ; " 0x%08lX:0x%08lX"
40375f78:  l32r	a8, 0x40374438 (0x400005d0)
40375f7b:  callx8	a8
L_40375f7e:
40375f7e:  l32i.n	a8, a1, 4
40375f80:  l32r	a9, 0x403745fc (0xc0377ff0)
40375f83:  l32r	a10, 0x40374600 (0x77fe0)
40375f86:  add.n	a9, a8, a9
40375f88:  bltu	a10, a9, 0x40375f94
40375f8b:  extui	a8, a8, 0, 4
40375f8e:  beqz.n	a8, 0x40375fa1
40375f90:  j	0x40376008
40375f93:  excw
40375f96:  s32i.n	a15, a1, 40
40375f98:  beqz.n	a9, 0x40375fbb
40375f9a:  add.n	a9, a8, a9
40375f9c:  movi.n	a3, 1
40375f9e:  bltu	a10, a9, 0x4037600a
L_40375fa1:
40375fa1:  l32i.n	a10, a1, 0
40375fa3:  bgez	a10, 0x40375fb2
40375fa6:  l32r	a8, 0x4037460c (0x40000000)
40375fa9:  slli	a10, a10, 2
40375fac:  srli	a10, a10, 2
40375faf:  or	a10, a10, a8
L_40375fb2:
40375fb2:  l32r	a9, 0x40374610 (0xbdfffffd)
40375fb5:  l32r	a8, 0x40374614 (0x1ffffff)
40375fb8:  add.n	a9, a10, a9
40375fba:  l32r	a11, 0x40374618 (0xbfc8fffd)
40375fbd:  excw
40375fc0:  l32r	a9, 0x4037461c (0x6ffff)
40375fc3:  add.n	a11, a10, a11
40375fc5:  excw
40375fc8:  addi.n	a8, a8, -1
40375fca:  addi.n	a9, a9, -1
40375fcc:  neg	a8, a8
40375fcf:  neg	a9, a9
40375fd2:  or	a8, a8, a9
40375fd5:  extui	a3, a8, 0, 8
40375fd8:  bnez.n	a3, 0x40376002
40375fda:  l32r	a9, 0x40374620 (0xbffffffd)
40375fdd:  l32r	a11, 0x40374624 (0x5ffff)
40375fe0:  add.n	a9, a10, a9
40375fe2:  bgeu	a11, a9, 0x4037600a
40375fe5:  l32r	a11, 0x40374628 (0x9ff01ffd)
40375fe8:  l32r	a9, 0x40374608 (0x1fff)
40375feb:  add.n	a10, a10, a11
40375fed:  bgeu	a9, a10, 0x4037600a
40375ff0:  l32i.n	a9, a1, 12
40375ff2:  beqz.n	a9, 0x40376008
40375ff4:  l32i	a9, a9, 80
40375ff7:  movi.n	a10, 1
40375ff9:  addi	a9, a9, -20
40375ffc:  movnez	a3, a10, a9
40375fff:  j	0x4037600a
L_40376002:
40376002:  movi.n	a3, 0
40376004:  j	0x4037600a
40376007:  wsr.scompare1	a0
L_4037600a:
4037600a:  mov.n	a2, a7
4037600c:  l32r	a5, 0x4037460c (0x40000000)
4037600f:  movi.n	a7, 1
40376011:  j	0x4037606d
L_40376014:
40376014:  call8	0x40375e54   ; FUN_40375e54
40376017:  l32i.n	a11, a1, 0
40376019:  mov.n	a9, a10
4037601b:  slli	a8, a11, 2
4037601e:  srli	a8, a8, 2
40376021:  mov.n	a12, a11
40376023:  or	a8, a8, a5
40376026:  movltz	a12, a8, a11
40376029:  addi	a11, a12, -3
4037602c:  l32i.n	a6, a1, 4
4037602e:  xor	a9, a9, a7
40376031:  s32i.n	a11, a1, 16
40376033:  l32r	a10, 0x40374630 (0x3c030fc4)
40376036:  mov.n	a12, a6
40376038:  extui	a3, a9, 0, 8
4037603b:  beqz.n	a4, 0x40376060
4037603d:  l32r	a8, 0x40374648 (0x4200330c)   ; FUN_4200330c
40376040:  callx8	a8
40376043:  l32i.n	a10, a1, 16
40376045:  l32r	a8, 0x4037464c (0x42003360)   ; FUN_42003360
40376048:  callx8	a8
4037604b:  l32r	a10, 0x40374634 (0x3c031598)
4037604e:  l32r	a8, 0x40374648 (0x4200330c)   ; FUN_4200330c
40376051:  callx8	a8
40376054:  mov.n	a10, a6
40376056:  l32r	a8, 0x4037464c (0x42003360)   ; FUN_42003360
40376059:  callx8	a8
4037605c:  j	0x40376069
4037605f:  excw
40376062:  s32i.n	a15, a1, 32
40376064:  call12	0x40356ff4
40376067:  l32i.n	a0, a0, 0
L_40376069:
40376069:  addi.n	a2, a2, -1
4037606b:  beqz.n	a2, 0x4037607a
L_4037606d:
4037606d:  l32i.n	a9, a1, 8
4037606f:  mov.n	a10, a1
40376071:  beqz	a9, 0x403760d8
40376074:  beqz	a3, 0x40376014
40376077:  j	0x4037607c
L_4037607a:
4037607a:  beqz.n	a3, 0x40376099
L_4037607c:
4037607c:  l32r	a10, 0x4037463c (0x3c0315b0)   ; " |<-CORRUPTED"
4037607f:  beqz	a4, 0x4037608d
40376082:  l32r	a8, 0x40374648 (0x4200330c)   ; FUN_4200330c
40376085:  callx8	a8
40376088:  movi.n	a2, -1
4037608a:  j	0x403760bb
L_4037608d:
4037608d:  l32r	a8, 0x40374438 (0x400005d0)
40376090:  callx8	a8
40376093:  movi.n	a2, -1
40376095:  j	0x403760cb
40376098:  srai	a8, a0, 8
4037609b:  beqz.n	a8, 0x403760b5
4037609d:  l32r	a10, 0x40374640 (0x3c0315c0)   ; " |<-CONTINUES"
403760a0:  beqz.n	a4, 0x403760ac
403760a2:  l32r	a8, 0x40374648 (0x4200330c)   ; FUN_4200330c
403760a5:  callx8	a8
403760a8:  j	0x403760b8
403760ab:  excw
403760ae:  l32i.n	a15, a0, 56
403760b0:  l32i.n	a0, a0, 0
403760b2:  j	0x403760c9
L_403760b5:
403760b5:  beqz	a4, 0x403760c9
L_403760b8:
403760b8:  movi	a2, 0
L_403760bb:
403760bb:  l32r	a10, 0x40374644 (0x3c0315d0)
403760be:  l32r	a8, 0x40374648 (0x4200330c)   ; FUN_4200330c
403760c1:  callx8	a8
403760c4:  j	0x403760de
403760c7:  excw
403760ca:  movi	a0, 0x15e
403760cd:  s32i.n	a15, a1, 32
403760cf:  add.n	a15, a8, a13
403760d1:  callx8	a8
403760d4:  j	0x403760de
403760d7:  movnez	a1, a6, a0
403760da:  excw
403760dc:  bbsi	a15, 30, 0x403760fd
403760df:  excw
---- end objdump fallback ---- */
