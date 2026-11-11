/* WARNING: Control flow encountered bad instruction data */

int FUN_40378870(undefined4 *param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *apuStack_40 [16];
  
  apuStack_40[0] = param_1;
  iVar1 = (**(code **)(*(int *)PTR_PTR_403748f8 + 8))(apuStack_40);
  if (iVar1 == 0) {
    if (*(int *)(apuStack_40[0][1] + 0x44) == 0) {
      iVar1 = DAT_40374914;
    }
    else {
      if (*(code **)(apuStack_40[0][2] + 8) != (code *)0x0) {
        iVar2 = (**(code **)(apuStack_40[0][2] + 8))(apuStack_40[0][3],param_3,param_4);
        if (iVar2 == 0x10d) {
          return 0x10d;
        }
        if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_40381c60();
        }
      }
      if (((param_2 == 0) || ((uint)apuStack_40[0][5] < param_3)) ||
         ((uint)apuStack_40[0][5] < param_3 + param_4)) {
        iVar1 = 0x102;
      }
      else if (param_4 != 0) {
        (**(code **)(*(int *)*apuStack_40[0] + 0x24))((int *)*apuStack_40[0],param_2);
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
  }
  return iVar1;
}

/* ---- objdump fallback (Ghidra stopped on excw / literal pool) ----
40378870:  entry	a1, 96
40378873:  l32r	a7, 0x403748f8 (0x3fc95a88)
40378876:  s32i.n	a2, a1, 32
40378878:  l32i.n	a8, a7, 0
4037887a:  addi	a10, a1, 32
4037887d:  l32i.n	a8, a8, 8
4037887f:  or	a6, a4, a4
40378882:  callx8	a8
40378885:  mov.n	a2, a10
40378887:  bnez	a10, 0x403789f4
4037888a:  l32i.n	a8, a1, 32
4037888c:  l32i.n	a9, a8, 4
4037888e:  l32i	a9, a9, 68
40378891:  beqz	a9, 0x403789e4
40378894:  l32i.n	a9, a8, 8
40378896:  l32i.n	a9, a9, 8
40378898:  beqz.n	a9, 0x403788b1
4037889a:  l32i.n	a10, a8, 12
4037889c:  mov.n	a12, a5
4037889e:  mov.n	a11, a4
403788a0:  callx8	a9
403788a3:  movi	a8, 0x10d
403788a6:  bne	a10, a8, 0x403788ac
403788a9:  j	0x403789ea
L_403788ac:
403788ac:  beqz.n	a10, 0x403788b1
403788ae:  call8	0x40381c60   ; FUN_40381c60
L_403788b1:
403788b1:  beqz	a3, 0x403789f1
403788b4:  l32i.n	a9, a1, 32
403788b6:  l32i.n	a8, a9, 20
403788b8:  bgeu	a8, a6, 0x403788be
403788bb:  j	0x403789f1
L_403788be:
403788be:  add.n	a10, a6, a5
403788c0:  bgeu	a8, a10, 0x403788c6
403788c3:  j	0x403789f1
L_403788c6:
403788c6:  beqz	a5, 0x403789f4
403788c9:  l32i.n	a10, a9, 0
403788cb:  mov.n	a11, a3
403788cd:  l32i.n	a8, a10, 0
403788cf:  or	a4, a5, a5
403788d2:  l32i	a8, a8, 36
403788d5:  callx8	a8
403788d8:  l32r	a9, 0x403746c4 (0xc0378000)
403788db:  l32r	a8, 0x403748b0 (0x77fff)
403788de:  add.n	a9, a3, a9
403788e0:  excw
403788e3:  addi.n	a8, a8, -1
403788e5:  neg	a8, a8
403788e8:  or	a10, a10, a8
403788eb:  extui	a8, a10, 0, 8
403788ee:  s32i.n	a5, a1, 36
403788f0:  s32i.n	a8, a1, 40
403788f2:  s32i.n	a2, a1, 48
403788f4:  s32i.n	a6, a1, 44
403788f6:  mov.n	a5, a6
L_403788f8:
403788f8:  l32i.n	a8, a1, 40
403788fa:  beqz.n	a8, 0x40378908
403788fc:  l32r	a8, 0x40374944 (0x2000)
403788ff:  mov.n	a2, a3
40378901:  minu	a6, a4, a8
40378904:  j	0x4037891b
40378907:  lsx	f2, a12, a0
4037890a:  minu	a6, a4, a8
4037890d:  mov.n	a12, a6
4037890f:  mov.n	a11, a3
40378911:  mov.n	a10, a1
40378913:  l32r	a8, 0x4037450c (0x400011f4)
40378916:  callx8	a8
40378919:  mov.n	a2, a1
L_4037891b:
4037891b:  l32i.n	a10, a1, 32
4037891d:  l32i.n	a8, a10, 4
4037891f:  l32i	a8, a8, 104
40378922:  beqz.n	a8, 0x4037892e
40378924:  movi.n	a11, 0
40378926:  callx8	a8
40378929:  bnez	a10, 0x403789ea
4037892c:  l32i.n	a10, a1, 32
L_4037892e:
4037892e:  l32i	a8, a7, 0
40378931:  l32i	a8, a8, 0
40378934:  callx8	a8
40378937:  or	a8, a10, a10
4037893a:  l32i.n	a10, a1, 32
4037893c:  bnez	a8, 0x40378980
4037893f:  l32i.n	a8, a10, 4
40378941:  mov.n	a13, a6
40378943:  l32i	a8, a8, 68
40378946:  mov.n	a12, a5
40378948:  mov.n	a11, a2
4037894a:  callx8	a8
4037894d:  l32i.n	a9, a1, 36
4037894f:  sub	a4, a4, a6
40378952:  mov.n	a8, a10
40378954:  bltu	a4, a9, 0x40378966
40378957:  l32r	a13, 0x40374948 (0x3c03a64c)   ; "len_remain < length"
4037895a:  l32r	a12, 0x4037494c (0x3c03e9b8)   ; "esp_flash_write"
4037895d:  l32r	a10, 0x40374940 (0x3c03a5f3)
40378960:  movi	a11, 0x436
40378963:  call8	0x40381ce4   ; FUN_40381ce4
L_40378966:
40378966:  l32i.n	a9, a7, 0
40378968:  l32i.n	a10, a1, 32
4037896a:  bnez.n	a8, 0x4037898c
4037896c:  beqz	a4, 0x403789b5
4037896f:  l32i.n	a8, a9, 4
40378971:  movi.n	a11, 0
40378973:  callx8	a8
40378976:  bnez.n	a10, 0x40378999
40378978:  add.n	a5, a5, a6
4037897a:  add.n	a3, a3, a6
4037897c:  j	0x403788f8
4037897f:  mul16u	a12, a8, a0
40378982:  l32i.n	a6, a1, 44
40378984:  l32i.n	a5, a1, 36
40378986:  mov.n	a2, a8
40378988:  j	0x403789a1
4037898b:  excw
4037898e:  l32i.n	a5, a1, 36
40378990:  mov.n	a2, a8
40378992:  movi.n	a12, 1
40378994:  j	0x403789a1
40378997:  excw
4037899a:  l32r	a11, 0x4035cefc
4037899d:  mov.n	a2, a10
4037899f:  movi.n	a12, 1
L_403789a1:
403789a1:  l32i.n	a8, a7, 0
403789a3:  l32i.n	a10, a1, 32
403789a5:  l32i.n	a8, a8, 12
403789a7:  mov.n	a14, a5
403789a9:  mov.n	a13, a6
403789ab:  mov.n	a11, a2
403789ad:  callx8	a8
403789b0:  bnez.n	a10, 0x403789cd
403789b2:  j	0x403789f4
L_403789b5:
403789b5:  l32i.n	a6, a1, 44
403789b7:  l32i.n	a5, a1, 36
403789b9:  l32i.n	a8, a9, 12
403789bb:  mov.n	a14, a5
403789bd:  mov.n	a13, a6
403789bf:  movi.n	a12, 1
403789c1:  mov.n	a11, a4
403789c3:  callx8	a8
403789c6:  mov.n	a2, a10
403789c8:  j	0x403789f4
403789cb:  src	a0, a0, a0
403789ce:  l32r	a9, 0x4035ad88
403789d1:  l32i.n	a0, a12, 36
403789d3:  l32i.n	a14, a1, 44
403789d5:  excw
403789d7:  l32r	a10, 0x40374950 (0x3fc95a6c)   ; "E %s: restore cache fail"
403789da:  l32r	a8, 0x40374438 (0x400005d0)
403789dd:  callx8	a8
403789e0:  j	0x403789f4
403789e3:  excw
403789e6:  { excw; bbsi.w18	a13, 0, 0x4037ea8c }
403789ee:  ill
---- end objdump fallback ---- */
