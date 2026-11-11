/* WARNING: Control flow encountered bad instruction data */

void FUN_420106bc(undefined4 param_1,uint param_2,int param_3,char *param_4,uint param_5)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 local_190;
  undefined4 local_90;
  undefined1 auStack_8c [76];
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  
  uStack_40 = param_2 & 0xff;
  if (param_3 == 0) {
    return;
  }
  iVar7 = *(int *)(param_3 + 0x210);
  if (iVar7 == 0) {
    return;
  }
  local_190 = 0;
  uStack_3c = iVar7 + 0x100;
  bVar1 = *(byte *)(iVar7 + 0x1d6);
  uVar8 = (uint)bVar1;
  bVar3 = param_5 != 0;
  if ((uVar8 != param_5) && (bVar3)) {
    return;
  }
  bVar2 = *(byte *)(param_3 + 0x52c);
  if (*(char *)(param_3 + 0x20c) == '\0') {
    if (!bVar3 || param_4 == (char *)0x0) {
      param_4 = (char *)(param_3 + 0x219);
    }
  }
  else {
    if (!bVar3 || param_4 == (char *)0x0) {
      param_4 = (char *)(param_3 + 0x219);
    }
    else if (*param_4 != *(char *)(iVar7 + 0x1d5)) {
      return;
    }
    if (uVar8 != 0) {
      memw();
      memw();
      memw();
      local_190 = (uint)*(byte *)(*(int *)(param_3 + 0x210) + 0x1d5);
      (*DAT_42000064)((int)&local_190 + 1,param_4 + 1,uVar8 - 1);
      goto LAB_42010768;
    }
  }
  (*DAT_42000064)(&local_190,param_4,uVar8);
LAB_42010768:
  memw();
  memw();
  memw();
  if (*(char *)(param_3 + 0x52d) == '\0') {
    uVar12 = (uint)*(byte *)(param_3 + 0x20c) * 8;
    uVar9 = uStack_3c;
    if (*(byte *)(uStack_3c + 0xb4) != 0) {
      uVar11 = uVar8 * 8;
      uVar10 = uVar12 + *(int *)(iVar7 + 0x1b0);
      if (uVar10 < uVar11) {
        uVar13 = *(byte *)(uStack_3c + 0xb4) + uVar10;
        uVar13 = (uVar13 < uVar11) * uVar13 + (uVar13 >= uVar11) * uVar11;
        uVar11 = uVar13 + 7;
        uVar10 = uVar10 >> 3;
        uVar14 = uVar11 >> 3;
        if (uVar10 < uVar14) {
          uStack_2c = uStack_3c;
          uStack_3c = uVar14;
          uStack_38 = uVar12;
          uStack_34 = uVar13;
          uStack_30 = uVar11;
          (*DAT_42000094)((int)&local_190 + uVar10,0,uVar14 - uVar10);
          uVar11 = uStack_30;
          uVar9 = uStack_2c;
          uVar12 = uStack_38;
          uVar13 = uStack_34;
        }
        if ((uVar11 & 0xfffffff8) != uVar13) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
    }
    if (*(byte *)(uVar9 + 0xbc) != 0) {
      uVar11 = uVar8 * 8;
      uVar10 = uVar12 + *(int *)(iVar7 + 0x1b8);
      if (uVar10 < uVar11) {
        uVar13 = *(byte *)(uVar9 + 0xbc) + uVar10;
        uVar13 = (uVar13 < uVar11) * uVar13 + (uVar13 >= uVar11) * uVar11;
        uVar11 = uVar13 + 7;
        uVar10 = uVar10 >> 3;
        uVar14 = uVar11 >> 3;
        if (uVar10 < uVar14) {
          uStack_3c = uVar14;
          uStack_38 = uVar12;
          uStack_34 = uVar13;
          uStack_30 = uVar11;
          uStack_2c = uVar9;
          (*DAT_42000094)((int)&local_190 + uVar10,0,uVar14 - uVar10);
          uVar11 = uStack_30;
          uVar9 = uStack_2c;
          uVar12 = uStack_38;
          uVar13 = uStack_34;
        }
        if ((uVar11 & 0xfffffff8) != uVar13) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
    }
    if (*(byte *)(uVar9 + 0xc4) != 0) {
      uVar10 = uVar8 * 8;
      uVar12 = uVar12 + *(int *)(iVar7 + 0x1c0);
      if (uVar12 < uVar10) {
        uVar9 = *(byte *)(uVar9 + 0xc4) + uVar12;
        uVar9 = (uVar9 < uVar10) * uVar9 + (uVar9 >= uVar10) * uVar10;
        uVar10 = uVar9 + 7;
        uVar12 = uVar12 >> 3;
        uVar11 = uVar10 >> 3;
        if (uVar12 < uVar11) {
          uStack_3c = uVar11;
          uStack_38 = uVar9;
          uStack_34 = uVar10;
          (*DAT_42000094)((int)&local_190 + uVar12,0,uVar11 - uVar12);
          uVar9 = uStack_38;
          uVar10 = uStack_34;
        }
        if ((uVar10 & 0xfffffff8) != uVar9) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
    }
  }
  FUN_4200fe10(param_3,&local_190,uVar8);
  iVar5 = FUN_4200fcb4(param_3,&local_190,uVar8);
  if (iVar5 == 0) {
    memw();
    memw();
    *DAT_42000e04 = 0;
    memw();
  }
  else {
    uVar6 = FUN_4202d108(&local_190,uVar8,*(undefined1 *)(param_3 + 0x20c),
                         *(undefined4 *)(param_3 + 0x210));
    (*(code *)PTR_spinlock_acquire_420004dc)(PTR_DAT_42000ea0,0xffffffff);
    uVar9 = -(bVar2 - 1);
    (*DAT_42000064)(param_3 + (uVar9 & 0xff) * 0x100 + 0x321,&local_190,uVar8);
    puVar4 = PTR_DAT_42000ea4;
    *(uint *)(param_3 + (uVar9 & 0xff) * 4 + 0x524) = uVar8;
    iVar5 = (*DAT_42000114)(&local_190,puVar4,uVar8);
    *(bool *)(param_3 + 800) = iVar5 == 0;
    (*DAT_42000064)(param_3 + 0x219,&local_190,uVar8);
    puVar4 = PTR_DAT_42000ea0;
    *(uint *)(param_3 + 0x31c) = uVar8;
    *(undefined4 *)(iVar7 + 0x1e4) = uVar6;
    (*(code *)PTR_vPortExitCritical_420004e0)(puVar4);
    *(char *)(param_3 + 0x52c) = -(*(char *)(param_3 + 0x52c) + -1);
    local_90 = (uStack_40 & 0xff) << 8;
    local_90 = (uint)CONCAT12(bVar1,(undefined2)local_90);
    (*DAT_42000064)(auStack_8c,&local_190,uVar8);
    FUN_42014610(&local_90);
    if (*DAT_42000e64 != 0) {
      (*(code *)PTR_xQueueGenericSend_42000488)(*DAT_42000e64,0,0);
    }
    memw();
    memw();
    *DAT_42000e04 = 0;
    memw();
  }
  return;
}

/* ---- objdump fallback (Ghidra stopped on excw / literal pool) ----
420106bc:  entry	a1, 0x190
420106bf:  extui	a8, a3, 0, 8
420106c2:  s32i	a8, a1, 0x150
420106c5:  mov.n	a11, a5
420106c7:  beqz	a4, 0x420109e9
420106ca:  l32i	a3, a4, 0x210
420106cd:  beqz	a3, 0x420109e9
420106d0:  mov.n	a10, a1
420106d2:  movi.n	a12, 0
420106d4:  movi.n	a9, 64
420106d6:  loop	a9, 0x420106dd
420106d9:  s32i.n	a12, a10, 0
420106db:  addi.n	a10, a10, 4
L_420106dd:
420106dd:  addmi	a9, a3, 0x100
420106e0:  l8ui	a7, a9, 214
420106e3:  movi.n	a12, 1
420106e5:  moveqz	a12, a6, a6
420106e8:  beq	a7, a6, 0x420106ee
420106eb:  bnez	a12, 0x420109e9
L_420106ee:
420106ee:  addmi	a5, a4, 0x200
420106f1:  movi.n	a10, 1
420106f3:  l8ui	a13, a5, 12
420106f6:  addmi	a2, a4, 0x500
420106f9:  moveqz	a10, a11, a11
420106fc:  l8ui	a6, a2, 44
420106ff:  and	a10, a12, a10
42010702:  beqz.n	a13, 0x42010715
42010704:  beqz.n	a10, 0x42010720
42010706:  l8ui	a12, a11, 0
42010709:  l8ui	a10, a9, 213
4201070c:  beq	a12, a10, 0x42010712
4201070f:  j	0x420109e9
L_42010712:
42010712:  j	0x42010725
L_42010715:
42010715:  movi	a12, 0x219
42010718:  add.n	a12, a4, a12
4201071a:  moveqz	a11, a12, a10
4201071d:  j	0x42010758
L_42010720:
42010720:  movi	a11, 0x219
42010723:  add.n	a11, a4, a11
L_42010725:
42010725:  beqz.n	a7, 0x42010758
42010727:  s32i	a9, a1, 0x154
4201072a:  memw
4201072d:  l32r	a10, 0x42000e4c (0x3fc99fa0)
42010730:  addi.n	a12, a7, -1
42010732:  memw
42010735:  l8ui	a10, a10, 0
42010738:  memw
4201073b:  l32i	a10, a4, 0x210
4201073e:  addi.n	a11, a11, 1
42010740:  addmi	a10, a10, 0x100
42010743:  l8ui	a13, a10, 213
42010746:  addi.n	a10, a1, 1
42010748:  s8i	a13, a1, 0
4201074b:  l32r	a8, 0x42000064 (0x400011f4)
4201074e:  callx8	a8
42010751:  l32i	a9, a1, 0x154
42010754:  j	0x42010768
42010757:  excw
4201075a:  mov.n	a10, a1
4201075c:  s32i	a9, a1, 0x154
4201075f:  l32r	a8, 0x42000064 (0x400011f4)
42010762:  callx8	a8
42010765:  l32i	a9, a1, 0x154
L_42010768:
42010768:  memw
4201076b:  memw
4201076e:  l8ui	a11, a2, 45
42010771:  memw
42010774:  extui	a11, a11, 0, 8
42010777:  bnez	a11, 0x420108ea
4201077a:  l8ui	a13, a5, 12
4201077d:  l8ui	a14, a9, 180
42010780:  slli	a13, a13, 3
42010783:  beqz	a14, 0x420107fc
42010786:  l32i	a10, a3, 0x1b0
42010789:  slli	a12, a7, 3
4201078c:  add.n	a10, a13, a10
4201078e:  bgeu	a10, a12, 0x420107fc
42010791:  add.n	a14, a14, a10
42010793:  minu	a14, a14, a12
42010796:  addi	a8, a14, 7
42010799:  srli	a10, a10, 3
4201079c:  srli	a15, a8, 3
4201079f:  bgeu	a10, a15, 0x420107cc
420107a2:  sub	a12, a15, a10
420107a5:  add	a10, a1, a10
420107a8:  s32i	a9, a1, 0x164
420107ab:  s32i	a8, a1, 0x160
420107ae:  s32i	a14, a1, 0x15c
420107b1:  s32i	a13, a1, 0x158
420107b4:  s32i	a15, a1, 0x154
420107b7:  l32r	a8, 0x42000094 (0x400011e8)
420107ba:  callx8	a8
420107bd:  l32i	a9, a1, 0x164
420107c0:  l32i	a8, a1, 0x160
420107c3:  l32i	a14, a1, 0x15c
420107c6:  l32i	a13, a1, 0x158
420107c9:  l32i	a15, a1, 0x154
L_420107cc:
420107cc:  movi.n	a10, -8
420107ce:  and	a10, a8, a10
420107d1:  sub	a11, a10, a14
420107d4:  beq	a10, a14, 0x420107fc
420107d7:  excw
420107da:  addi.n	a10, a10, -1
420107dc:  neg	a10, a10
420107df:  extui	a10, a10, 0, 8
420107e2:  beqz.n	a10, 0x420107fc
420107e4:  addi.n	a10, a15, -1
420107e6:  add.n	a10, a1, a10
420107e8:  movi.n	a14, 1
420107ea:  l8ui	a12, a10, 0
420107ed:  ssl	a11
420107f0:  sll	a11, a14
420107f3:  addi	a11, a11, -1
420107f6:  and	a11, a11, a12
420107f9:  s8i	a11, a10, 0
L_420107fc:
420107fc:  l8ui	a14, a9, 188
420107ff:  beqz	a14, 0x42010878
42010802:  l32i	a10, a3, 0x1b8
42010805:  slli	a11, a7, 3
42010808:  add.n	a10, a13, a10
4201080a:  bgeu	a10, a11, 0x42010878
4201080d:  add.n	a14, a14, a10
4201080f:  minu	a14, a14, a11
42010812:  addi.n	a8, a14, 7
42010814:  srli	a10, a10, 3
42010817:  srli	a15, a8, 3
4201081a:  bgeu	a10, a15, 0x42010848
4201081d:  sub	a12, a15, a10
42010820:  movi.n	a11, 0
42010822:  add.n	a10, a1, a10
42010824:  s32i	a9, a1, 0x164
42010827:  s32i	a8, a1, 0x160
4201082a:  s32i	a14, a1, 0x15c
4201082d:  s32i	a13, a1, 0x158
42010830:  s32i	a15, a1, 0x154
42010833:  l32r	a8, 0x42000094 (0x400011e8)
42010836:  callx8	a8
42010839:  l32i	a9, a1, 0x164
4201083c:  l32i	a8, a1, 0x160
4201083f:  l32i	a14, a1, 0x15c
42010842:  l32i	a13, a1, 0x158
42010845:  l32i	a15, a1, 0x154
L_42010848:
42010848:  movi.n	a10, -8
4201084a:  and	a10, a8, a10
4201084d:  sub	a11, a10, a14
42010850:  beq	a10, a14, 0x42010878
42010853:  excw
42010856:  addi.n	a10, a10, -1
42010858:  neg	a10, a10
4201085b:  extui	a10, a10, 0, 8
4201085e:  beqz.n	a10, 0x42010878
42010860:  addi.n	a10, a15, -1
42010862:  add.n	a10, a1, a10
42010864:  movi.n	a14, 1
42010866:  l8ui	a12, a10, 0
42010869:  ssl	a11
4201086c:  sll	a11, a14
4201086f:  addi	a11, a11, -1
42010872:  and	a11, a11, a12
42010875:  s8i	a11, a10, 0
L_42010878:
42010878:  l8ui	a9, a9, 196
4201087b:  beqz	a9, 0x420108ea
4201087e:  l32i	a11, a3, 0x1c0
42010881:  slli	a10, a7, 3
42010884:  add.n	a13, a13, a11
42010886:  bgeu	a13, a10, 0x420108ea
42010889:  add.n	a9, a9, a13
4201088b:  minu	a9, a9, a10
4201088e:  addi.n	a14, a9, 7
42010890:  srli	a13, a13, 3
42010893:  srli	a15, a14, 3
42010896:  bgeu	a13, a15, 0x420108b9
42010899:  sub	a12, a15, a13
4201089c:  movi.n	a11, 0
4201089e:  add	a10, a1, a13
420108a1:  s32i	a14, a1, 0x15c
420108a4:  s32i	a9, a1, 0x158
420108a7:  s32i	a15, a1, 0x154
420108aa:  l32r	a8, 0x42000094 (0x400011e8)
420108ad:  callx8	a8
420108b0:  l32i	a14, a1, 0x15c
420108b3:  l32i	a9, a1, 0x158
420108b6:  l32i	a15, a1, 0x154
L_420108b9:
420108b9:  movi	a10, -8
420108bc:  and	a14, a14, a10
420108bf:  sub	a10, a14, a9
420108c2:  beq	a14, a9, 0x420108ea
420108c5:  excw
420108c8:  addi	a9, a9, -1
420108cb:  neg	a9, a9
420108ce:  extui	a9, a9, 0, 8
420108d1:  beqz.n	a9, 0x420108ea
420108d3:  addi.n	a9, a15, -1
420108d5:  add.n	a9, a1, a9
420108d7:  movi.n	a11, 1
420108d9:  l8ui	a12, a9, 0
420108dc:  ssl	a10
420108df:  sll	a10, a11
420108e2:  addi.n	a10, a10, -1
420108e4:  and	a10, a10, a12
420108e7:  s8i	a10, a9, 0
L_420108ea:
420108ea:  mov.n	a12, a7
420108ec:  mov.n	a11, a1
420108ee:  mov.n	a10, a4
420108f0:  call8	0x4200fe10   ; FUN_4200fe10
420108f3:  mov.n	a12, a7
420108f5:  mov.n	a11, a1
420108f7:  mov.n	a10, a4
420108f9:  call8	0x4200fcb4   ; FUN_4200fcb4
420108fc:  bnez.n	a10, 0x42010911
420108fe:  memw
42010901:  l32r	a8, 0x42000e04 (0x3fc99f88)
42010904:  memw
42010907:  s8i	a10, a8, 0
4201090a:  memw
4201090d:  j	0x420109e9
42010910:  extui	a13, a0, 2, 3
42010913:  excw
42010916:  movi.n	a13, 11
42010918:  bge	a13, a0, 0x4201091d
4201091b:  call8	0x4202d108   ; FUN_4202d108
4201091e:  mov.n	a5, a10
42010920:  l32r	a10, 0x42000ea0 (0x3fc94128)
42010923:  movi.n	a11, -1
42010925:  addi.n	a6, a6, -1
42010927:  l32r	a8, 0x420004dc (0x4037bf44)   ; spinlock_acquire
4201092a:  callx8	a8
4201092d:  neg	a6, a6
42010930:  extui	a10, a6, 0, 8
42010933:  movi	a11, 0x321
42010936:  slli	a10, a10, 8
42010939:  add.n	a10, a10, a11
4201093b:  mov.n	a12, a7
4201093d:  mov.n	a11, a1
4201093f:  add.n	a10, a4, a10
42010941:  l32r	a8, 0x42000064 (0x400011f4)
42010944:  callx8	a8
42010947:  movi	a10, 0x520
4201094a:  extui	a6, a6, 0, 8
4201094d:  addx4	a6, a6, a10
42010950:  l32r	a11, 0x42000ea4 (0x3c03e2e4)
42010953:  add.n	a6, a4, a6
42010955:  s32i.n	a7, a6, 4
42010957:  mov.n	a12, a7
42010959:  mov.n	a10, a1
4201095b:  l32r	a8, 0x42000114 (0x4000120c)
4201095e:  callx8	a8
42010961:  nsau	a10, a10
42010964:  addmi	a11, a4, 0x300
42010967:  srli	a10, a10, 5
4201096a:  s8i	a10, a11, 32
4201096d:  movi	a10, 0x219
42010970:  mov.n	a12, a7
42010972:  mov.n	a11, a1
42010974:  add	a10, a4, a10
42010977:  l32r	a8, 0x42000064 (0x400011f4)
4201097a:  callx8	a8
4201097d:  l32r	a10, 0x42000ea0 (0x3fc94128)
42010980:  s32i	a7, a4, 0x31c
42010983:  s32i	a5, a3, 0x1e4
42010986:  l32r	a8, 0x420004e0 (0x4037c094)   ; vPortExitCritical
42010989:  callx8	a8
4201098c:  l8ui	a8, a2, 44
4201098f:  addmi	a5, a1, 0x100
42010992:  addi.n	a8, a8, -1
42010994:  neg	a8, a8
42010997:  s8i	a8, a2, 44
4201099a:  movi.n	a6, 0
4201099c:  mov.n	a9, a5
4201099e:  movi	a8, 17
420109a1:  loop	a8, 0x420109a9
420109a4:  s32i.n	a6, a9, 0
420109a6:  addi	a9, a9, 4
L_420109a9:
420109a9:  l32i	a8, a1, 0x150
420109ac:  or	a12, a7, a7
420109af:  s8i	a8, a5, 1
420109b2:  or	a11, a1, a1
420109b5:  addi.n	a10, a5, 4
420109b7:  s8i	a7, a5, 2
420109ba:  l32r	a8, 0x42000064 (0x400011f4)
420109bd:  callx8	a8
420109c0:  mov.n	a10, a5
420109c2:  call8	0x42014610   ; FUN_42014610
420109c5:  l32r	a8, 0x42000e64 (0x3fc99f84)
420109c8:  l32i.n	a10, a8, 0
420109ca:  beqz.n	a10, 0x420109d8
420109cc:  movi.n	a13, 0
420109ce:  mov.n	a12, a13
420109d0:  mov.n	a11, a13
420109d2:  l32r	a8, 0x42000488 (0x4037b768)   ; xQueueGenericSend
420109d5:  callx8	a8
L_420109d8:
420109d8:  memw
420109db:  l32r	a8, 0x42000e04 (0x3fc99f88)
420109de:  movi.n	a9, 0
420109e0:  memw
420109e3:  s8i	a9, a8, 0
420109e6:  memw
L_420109e9:
420109e9:  retw.n
---- end objdump fallback ---- */
