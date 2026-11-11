// strings: partition

/* WARNING: Control flow encountered bad instruction data */

int partition(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined1 auStack_b0 [88];
  ushort uStack_58;
  byte bStack_56;
  byte bStack_55;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 auStack_4c [16];
  uint uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  int iStack_30;
  undefined4 *puStack_2c;
  
  (*(code *)PTR_FUN_420008d8)(DAT_4200168c);
  if (*DAT_42001690 == 0) {
    (*DAT_420016b0)(auStack_b0);
    iVar1 = FUN_42019854(0,DAT_42000988,0,&iStack_34,&uStack_38);
    puVar6 = PTR_s_partition_42001698;
    if (iVar1 == 0) {
      iVar1 = iStack_34 + DAT_42000288;
      iStack_30 = iStack_34 + DAT_42001694;
      puStack_2c = (undefined4 *)0x0;
      puVar5 = (undefined4 *)0x0;
      iStack_34 = iVar1;
      while( true ) {
        (*DAT_42000064)(&uStack_58,iVar1,0x20);
        puVar2 = puStack_2c;
        if (uStack_58 == DAT_420016a8) break;
        if (uStack_58 != DAT_420016ac) goto LAB_42018bfb;
        (*DAT_420016b4)(auStack_b0,&uStack_58,0x20);
        puVar2 = (undefined4 *)(*(code *)PTR_FUN_42000910)(1,0x34);
        if (puVar2 == (undefined4 *)0x0) goto LAB_42018bfb;
        *puVar2 = *DAT_42000cbc;
        puVar2[1] = (uint)bStack_56;
        puVar2[3] = uStack_54;
        puVar2[2] = (uint)bStack_55;
        puVar2[4] = uStack_50;
        puVar2[5] = DAT_42000988;
        iVar3 = (*(code *)PTR_FUN_42000cc4)();
        if (iVar3 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        *(undefined1 *)((int)puVar2 + 0x29) = 0;
        *(byte *)((int)puVar2 + 0x2a) = (byte)(uStack_3c >> 1) & 1;
        *(undefined1 *)(puVar2 + 0xb) = 0;
        (*DAT_42000da8)(puVar2 + 6,auStack_4c,0x10);
        if (puVar5 == (undefined4 *)0x0) {
          puVar2[0xc] = puStack_2c;
          puStack_2c = puVar2;
        }
        else {
          puVar2[0xc] = puVar5[0xc];
          puVar5[0xc] = puVar2;
        }
        iVar1 = iVar1 + 0x20;
        if (iVar1 == iStack_30) goto LAB_42018bfb;
        puVar5 = puVar2;
      }
      if (iVar1 == 0) {
LAB_42018bfb:
        puVar2 = puStack_2c;
        uVar4 = (*(code *)PTR_FUN_4200005c)();
        puVar6 = PTR_s_partition_42001698;
        (*(code *)PTR_FUN_42000118)
                  (1,PTR_s_partition_42001698,PTR_DAT_4200169c,uVar4,PTR_s_partition_42001698);
        iVar1 = 0x105;
      }
      else {
        (*DAT_420016b8)(&uStack_58,auStack_b0);
        iVar1 = (*DAT_42000114)(&uStack_58,iVar1 + 0x10);
        if (iVar1 == 0) {
          *DAT_42001690 = (int)puVar2;
          spi_flash_munmap(uStack_38);
          goto LAB_42018c66;
        }
        uVar4 = (*(code *)PTR_FUN_4200005c)();
        puVar6 = PTR_s_partition_42001698;
        (*(code *)PTR_FUN_42000118)
                  (1,PTR_s_partition_42001698,PTR_DAT_420016a0,uVar4,PTR_s_partition_42001698);
        iVar1 = 0x103;
      }
      while (puVar2 != (undefined4 *)0x0) {
        puVar5 = (undefined4 *)puVar2[0xc];
        (*(code *)PTR_FUN_42000570)(puVar2);
        puVar2 = puVar5;
      }
      spi_flash_munmap(uStack_38);
    }
    uVar4 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(1,puVar6,PTR_DAT_420016a4,uVar4,puVar6,iVar1);
  }
  else {
LAB_42018c66:
    iVar1 = 0;
  }
  (*(code *)PTR_FUN_420008dc)(DAT_4200168c);
  return iVar1;
}

/* ---- objdump fallback (Ghidra stopped on excw / literal pool) ----
42018ab8:  entry	a1, 176
42018abb:  l32r	a10, 0x4200168c (0x3fca910c)
42018abe:  l32r	a8, 0x420008d8 (0x40376ce8)   ; FUN_40376ce8
42018ac1:  callx8	a8
42018ac4:  l32r	a8, 0x42001690 (0x3fca9110)
42018ac7:  l32i.n	a7, a8, 0
42018ac9:  bnez	a7, 0x42018c66
42018acc:  mov.n	a10, a1
42018ace:  l32r	a8, 0x420016b0 (0x40001c5c)
42018ad1:  callx8	a8
42018ad4:  l32r	a11, 0x42000988 (0x1000)
42018ad7:  mov.n	a12, a7
42018ad9:  mov.n	a10, a7
42018adb:  addi	a14, a1, 120
42018ade:  addi	a13, a1, 124
42018ae1:  call8	0x42019854   ; FUN_42019854
42018ae4:  mov.n	a2, a10
42018ae6:  l32r	a7, 0x42001698 (0x3c039bd8)   ; "partition"
42018ae9:  bnez	a10, 0x42018c81
42018aec:  l32i	a5, a1, 124
42018aef:  l32r	a13, 0x42000288 (0x8000)
42018af2:  l32r	a8, 0x42001694 (0x9000)
42018af5:  add.n	a4, a5, a13
42018af7:  add.n	a8, a5, a8
42018af9:  s32i	a4, a1, 124
42018afc:  s32i	a8, a1, 128
42018aff:  mov.n	a7, a10
42018b01:  s32i	a10, a1, 132
42018b04:  j	0x42018b0b
42018b07:  excw
42018b0a:  j	0x4201bbbe
42018b0d:  mov.n	a11, a4
42018b0f:  addi	a10, a1, 88
42018b12:  l32r	a8, 0x42000064 (0x400011f4)
42018b15:  callx8	a8
42018b18:  l16ui	a8, a1, 88
42018b1b:  l32r	a9, 0x420016a8 (0xebeb)
42018b1e:  bne	a8, a9, 0x42018b24
42018b21:  j	0x42018bf0
L_42018b24:
42018b24:  l32r	a9, 0x420016ac (0x50aa)
42018b27:  beq	a8, a9, 0x42018b2d
42018b2a:  j	0x42018bf8
L_42018b2d:
42018b2d:  movi.n	a12, 32
42018b2f:  addi	a11, a1, 88
42018b32:  mov.n	a10, a1
42018b34:  l32r	a8, 0x420016b4 (0x40001c68)
42018b37:  callx8	a8
42018b3a:  movi.n	a11, 52
42018b3c:  movi.n	a10, 1
42018b3e:  l32r	a8, 0x42000910 (0x40381de4)   ; FUN_40381de4
42018b41:  callx8	a8
42018b44:  mov.n	a6, a10
42018b46:  beqz	a10, 0x42018bf8
42018b49:  l32r	a8, 0x42000cbc (0x3fca914c)
42018b4c:  l8ui	a3, a1, 90
42018b4f:  l32i.n	a8, a8, 0
42018b51:  l8ui	a2, a1, 91
42018b54:  s32i.n	a8, a10, 0
42018b56:  l32i	a8, a1, 92
42018b59:  s32i.n	a3, a10, 4
42018b5b:  s32i.n	a8, a10, 12
42018b5d:  l32i	a8, a1, 96
42018b60:  s32i.n	a2, a10, 8
42018b62:  s32i.n	a8, a10, 16
42018b64:  l32r	a8, 0x42000988 (0x1000)
42018b67:  l32i	a5, a1, 116
42018b6a:  s32i.n	a8, a10, 20
42018b6c:  l32r	a8, 0x42000cc4 (0x403779c4)   ; FUN_403779c4
42018b6f:  callx8	a8
42018b72:  mov.n	a8, a10
42018b74:  beqz.n	a10, 0x42018bad
42018b76:  addi	a8, a3, -2
42018b79:  movi.n	a10, 1
42018b7b:  extui	a8, a8, 0, 8
42018b7e:  excw
42018b81:  addi.n	a8, a8, -1
42018b83:  movi.n	a12, 0
42018b85:  neg	a8, a8
42018b88:  moveqz	a12, a10, a3
42018b8b:  or	a8, a8, a12
42018b8e:  extui	a8, a8, 0, 8
42018b91:  bnez.n	a8, 0x42018bad
42018b93:  movi.n	a12, -5
42018b95:  and	a11, a2, a12
42018b98:  addi	a9, a3, -1
42018b9b:  or	a12, a8, a8
42018b9e:  moveqz	a12, a10, a11
42018ba1:  movnez	a10, a8, a9
42018ba4:  and	a8, a12, a10
42018ba7:  extui	a5, a5, 0, 1
42018baa:  or	a8, a8, a5
L_42018bad:
42018bad:  l32i	a9, a1, 116
42018bb0:  s8i	a8, a6, 41
42018bb3:  extui	a9, a9, 1, 1
42018bb6:  movi.n	a8, 0
42018bb8:  movi.n	a12, 16
42018bba:  addi	a11, a1, 100
42018bbd:  addi	a10, a6, 24
42018bc0:  s8i	a9, a6, 42
42018bc3:  s8i	a8, a6, 44
42018bc6:  l32r	a8, 0x42000da8 (0x40001224)
42018bc9:  callx8	a8
42018bcc:  bnez.n	a7, 0x42018bd9
42018bce:  l32i	a8, a1, 132
42018bd1:  s32i	a6, a1, 132
42018bd4:  s32i.n	a8, a6, 48
42018bd6:  j	0x42018bdf
L_42018bd9:
42018bd9:  l32i.n	a8, a7, 48
42018bdb:  s32i.n	a8, a6, 48
42018bdd:  s32i.n	a6, a7, 48
L_42018bdf:
42018bdf:  l32i	a8, a1, 128
42018be2:  addi	a4, a4, 32
42018be5:  beq	a4, a8, 0x42018beb
42018be8:  j	0x42018b09
L_42018beb:
42018beb:  j	0x42018bf8
42018bee:  orbc	b0, b0, b0
42018bf1:  l32r	a2, 0x42013c78 (0x778aa88c)
42018bf4:  excw
42018bf7:  srai	a3, a0, 2
42018bfa:  l32r	a2, 0x41fdee00
42018bfd:  excw
42018bff:  l32i.n	a0, a0, 0
42018c01:  l32r	a7, 0x42001698 (0x3c039bd8)   ; "partition"
42018c04:  l32r	a12, 0x4200169c (0x3c039be4)
42018c07:  mov.n	a13, a10
42018c09:  mov.n	a14, a7
42018c0b:  mov.n	a11, a7
42018c0d:  movi.n	a10, 1
42018c0f:  l32r	a8, 0x42000118 (0x40381c18)   ; FUN_40381c18
42018c12:  callx8	a8
42018c15:  movi	a2, 0x105
42018c18:  j	0x42018c78
42018c1b:  excw
42018c1e:  l32r	a0, 0x420092a8 (0x82180c0a)
42018c21:  l32i.n	a5, a1, 32
42018c23:  call8	0x41ff964c
42018c26:  l32i.n	a0, a0, 0
42018c28:  movi.n	a12, 16
42018c2a:  add.n	a11, a4, a12
42018c2c:  addi	a10, a1, 88
42018c2f:  l32r	a8, 0x42000114 (0x4000120c)
42018c32:  callx8	a8
42018c35:  beqz.n	a10, 0x42018c58
42018c37:  l32r	a8, 0x4200005c (0x40381bb0)   ; FUN_40381bb0
42018c3a:  callx8	a8
42018c3d:  l32r	a7, 0x42001698 (0x3c039bd8)   ; "partition"
42018c40:  l32r	a12, 0x420016a0 (0x3c039c1c)
42018c43:  mov.n	a13, a10
42018c45:  mov.n	a14, a7
42018c47:  mov.n	a11, a7
42018c49:  movi.n	a10, 1
42018c4b:  l32r	a8, 0x42000118 (0x40381c18)   ; FUN_40381c18
42018c4e:  callx8	a8
42018c51:  movi	a2, 0x103
42018c54:  j	0x42018c78
42018c57:  excw
42018c5a:  movi	a10, 0x221
42018c5d:  { excw; excw; excw }
42018c65:  andb	b0, b12, b0
42018c68:  j	0x42018c9a
42018c6b:  ill
---- end objdump fallback ---- */
