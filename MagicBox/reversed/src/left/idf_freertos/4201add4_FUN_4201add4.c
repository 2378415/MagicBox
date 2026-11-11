// strings: (p7@

/* WARNING: Control flow encountered bad instruction data */
/* (1 unreachable decompiler blocks omitted) */

void FUN_4201add4(void)

{
  bool bVar1;
  undefined4 *puVar2;
  code *pcVar3;
  ulonglong *puVar4;
  undefined4 uVar5;
  int iVar6;
  ulonglong uVar7;
  
  puVar2 = DAT_420019fc;
  do {
    (*(code *)PTR_ulTaskGenericNotifyTake_42000eb8)(0,1,0xffffffff);
    (*(code *)PTR_FUN_420004c8)();
    (*(code *)PTR_spinlock_acquire_420004dc)(PTR_DAT_420019f8,0xffffffff);
    bVar1 = false;
    while( true ) {
      puVar4 = (ulonglong *)*puVar2;
      uVar7 = (*(code *)PTR_FUN_4200092c)();
      if (puVar4 == (ulonglong *)0x0) break;
      if (uVar7 < *puVar4) {
        (*(code *)PTR_FUN_42001a08)((int)*puVar4,*(undefined4 *)((int)puVar4 + 4),0);
        goto LAB_4201aef9;
      }
      iVar6 = (int)puVar4[3];
      if (iVar6 != 0) {
        *(undefined4 *)(iVar6 + 0x1c) = *(undefined4 *)((int)puVar4 + 0x1c);
      }
      uVar7 = puVar4[2];
      **(int **)((int)puVar4 + 0x1c) = iVar6;
      bVar1 = true;
      if ((int)uVar7 == DAT_42001a00) {
        (*(code *)PTR_FUN_42000570)(puVar4);
      }
      else {
        if ((int)puVar4[1] != 0 || (*(uint *)((int)puVar4 + 0xc) & 0xffffff) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        *(undefined4 *)puVar4 = 0;
        *(undefined4 *)((int)puVar4 + 4) = 0;
        pcVar3 = *(code **)(puVar4 + 2);
        uVar5 = *(undefined4 *)((int)puVar4 + 0x14);
        (*(code *)PTR_FUN_420004c8)();
        (*(code *)PTR_vPortExitCritical_420004e0)(PTR_DAT_420019f8);
        (*pcVar3)(uVar5);
        (*(code *)PTR_FUN_420004c8)();
        (*(code *)PTR_spinlock_acquire_420004dc)(PTR_DAT_420019f8,0xffffffff);
      }
    }
    if (bVar1) {
      (*(code *)PTR_FUN_42001a08)(0xffffffff,0xffffffff,0);
    }
LAB_4201aef9:
    (*(code *)PTR_FUN_420004c8)();
    (*(code *)PTR_vPortExitCritical_420004e0)(PTR_DAT_420019f8);
  } while( true );
}

/* ---- objdump fallback (Ghidra stopped on excw / literal pool) ----
4201add4:  entry	a1, 48
4201add7:  l32r	a2, 0x420019fc (0x3fca92d0)
4201adda:  movi.n	a3, 1
4201addc:  movi.n	a12, -1
4201adde:  mov.n	a11, a3
4201ade0:  movi.n	a10, 0
4201ade2:  l32r	a8, 0x42000eb8 (0x4037e3f0)   ; ulTaskGenericNotifyTake
4201ade5:  callx8	a8
4201ade8:  l32r	a8, 0x420004c8 (0x4037bf20)   ; FUN_4037bf20
4201adeb:  callx8	a8
4201adee:  l32r	a10, 0x420019f8 (0x3fc94670)
4201adf1:  movi.n	a11, -1
4201adf3:  l32r	a8, 0x420004dc (0x4037bf44)   ; spinlock_acquire
4201adf6:  callx8	a8
4201adf9:  movi.n	a6, 0
4201adfb:  j	0x4201ae00
L_4201adfe:
4201adfe:  mov.n	a6, a3
L_4201ae00:
4201ae00:  l32i.n	a7, a2, 0
4201ae02:  l32r	a8, 0x4200092c (0x40377010)   ; FUN_40377010
4201ae05:  callx8	a8
4201ae08:  mov.n	a4, a10
4201ae0a:  mov.n	a5, a11
4201ae0c:  beqz	a7, 0x4201aeea
4201ae0f:  l32i.n	a8, a7, 4
4201ae11:  l32i.n	a14, a7, 0
4201ae13:  bgeu	a11, a8, 0x4201ae19
4201ae16:  j	0x4201aed8
L_4201ae19:
4201ae19:  bne	a8, a11, 0x4201ae22
4201ae1c:  bgeu	a10, a14, 0x4201ae22
4201ae1f:  j	0x4201aed8
L_4201ae22:
4201ae22:  l32i.n	a9, a7, 24
4201ae24:  beqz.n	a9, 0x4201ae2a
4201ae26:  l32i.n	a10, a7, 28
4201ae28:  s32i.n	a10, a9, 28
L_4201ae2a:
4201ae2a:  l32i.n	a11, a7, 28
4201ae2c:  l32i.n	a10, a7, 16
4201ae2e:  s32i	a9, a11, 0
4201ae31:  l32r	a9, 0x42001a00 (0xf0de1e1e)
4201ae34:  bne	a10, a9, 0x4201ae44
4201ae37:  or	a10, a7, a7
4201ae3a:  l32r	a8, 0x42000570 (0x40381e0c)   ; FUN_40381e0c
4201ae3d:  callx8	a8
4201ae40:  j	0x4201adfe
4201ae43:  excw
4201ae46:  l32i.n	a12, a7, 8
4201ae48:  slli	a6, a6, 8
4201ae4b:  srli	a6, a6, 8
4201ae4e:  or	a9, a12, a6
4201ae51:  beqz	a9, 0x4201aea3
4201ae54:  sub	a9, a5, a8
4201ae57:  excw
4201ae5a:  s32i.n	a8, a1, 8
4201ae5c:  s32i.n	a12, a1, 4
4201ae5e:  sub	a10, a4, a14
4201ae61:  s32i.n	a14, a1, 0
4201ae63:  mov.n	a13, a6
4201ae65:  sub	a11, a9, a11
4201ae68:  l32r	a8, 0x420001f0 (0x40002544)
4201ae6b:  callx8	a8
4201ae6e:  l32i.n	a14, a1, 0
4201ae70:  l32i.n	a12, a1, 4
4201ae72:  l32i.n	a8, a1, 8
4201ae74:  bge	a3, a10, 0x4201ae89
4201ae77:  l8ui	a9, a7, 15
4201ae7a:  bbci	a9, 1, 0x4201ae89
4201ae7d:  add.n	a4, a12, a4
4201ae7f:  add.n	a11, a6, a5
4201ae81:  excw
4201ae84:  add.n	a11, a11, a12
4201ae86:  j	0x4201ae92
L_4201ae89:
4201ae89:  add.n	a4, a14, a12
4201ae8b:  add.n	a11, a8, a6
4201ae8d:  excw
4201ae90:  add.n	a11, a11, a12
L_4201ae92:
4201ae92:  s32i.n	a11, a7, 4
4201ae94:  s32i.n	a4, a7, 0
4201ae96:  mov.n	a11, a3
4201ae98:  mov.n	a10, a7
4201ae9a:  l32r	a8, 0x42001a04 (0x40378f14)   ; FUN_40378f14
4201ae9d:  callx8	a8
4201aea0:  j	0x4201aea9
L_4201aea3:
4201aea3:  movi.n	a8, 0
4201aea5:  s32i.n	a8, a7, 0
4201aea7:  s32i.n	a8, a7, 4
L_4201aea9:
4201aea9:  l32i	a6, a7, 16
4201aeac:  l32i	a7, a7, 20
4201aeaf:  l32r	a8, 0x420004c8 (0x4037bf20)   ; FUN_4037bf20
4201aeb2:  callx8	a8
4201aeb5:  l32r	a10, 0x420019f8 (0x3fc94670)
4201aeb8:  l32r	a8, 0x420004e0 (0x4037c094)   ; vPortExitCritical
4201aebb:  callx8	a8
4201aebe:  or	a10, a7, a7
4201aec1:  callx8	a6
4201aec4:  l32r	a8, 0x420004c8 (0x4037bf20)   ; FUN_4037bf20
4201aec7:  callx8	a8
4201aeca:  l32r	a10, 0x420019f8 (0x3fc94670)
4201aecd:  movi.n	a11, -1
4201aecf:  l32r	a8, 0x420004dc (0x4037bf44)   ; spinlock_acquire
4201aed2:  callx8	a8
4201aed5:  j	0x4201adfe
L_4201aed8:
4201aed8:  mov.n	a10, a14
4201aeda:  mov.n	a11, a8
4201aedc:  movi.n	a12, 0
4201aede:  l32r	a8, 0x42001a08 (0x40377028)   ; FUN_40377028
4201aee1:  callx8	a8
4201aee4:  j	0x4201aef9
4201aee7:  ill
---- end objdump fallback ---- */
