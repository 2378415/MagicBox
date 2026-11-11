// strings: len_remain < len | esp_flash_api.c | esp_flash_erase_region | ||7@0Z

/* WARNING: Control flow encountered bad instruction data */

int esp_flash_erase_region(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  uint uVar8;
  undefined1 uVar9;
  uint local_40;
  uint uStack_3c;
  int iStack_30;
  uint uStack_2c;
  
  iStack_30 = param_1;
  iVar2 = (**(code **)(*(int *)PTR_PTR_4037487c + 8))(&iStack_30);
  if (iVar2 == 0) {
    if (*(int *)(*(int *)(iStack_30 + 4) + 0x18) == 0) {
      iVar2 = DAT_4037488c;
    }
    else if (*(int *)(*(int *)(iStack_30 + 4) + 0x1c) == 0) {
      iVar2 = DAT_4037488c;
    }
    else {
      if ((iStack_30 != 0) &&
         (pcVar7 = *(code **)(*(int *)(iStack_30 + 8) + 8), pcVar7 != (code *)0x0)) {
        iVar3 = (*pcVar7)(*(undefined4 *)(iStack_30 + 0xc),param_2,param_3);
        if (iVar3 == 0x10d) {
          return 0x10d;
        }
        if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_40381ce0();
        }
      }
      iVar3 = *(int *)(iStack_30 + 4);
      if (*(int *)(iVar3 + 0x1c) == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(uint *)(iVar3 + 0x24);
      }
      uVar6 = *(uint *)(iVar3 + 0x20);
      if (uVar6 == 0) {
        iVar2 = DAT_40374880;
      }
      else if (uVar5 % uVar6 == 0) {
        if (*(uint *)(iStack_30 + 0x14) < param_2) {
          iVar2 = 0x102;
        }
        else if (*(uint *)(iStack_30 + 0x14) < param_2 + param_3) {
          iVar2 = 0x102;
        }
        else if (param_2 % uVar6 == 0) {
          if (param_3 % uVar6 == 0) {
            if (param_3 != 0) {
              if ((*(int *)(iVar3 + 0x38) != 0) && (*(char *)(iVar3 + 0x30) != '\0')) {
                iVar2 = (*(code *)**(undefined4 **)PTR_PTR_4037487c)();
                if (iVar2 != 0) {
                  return iVar2;
                }
                local_40 = 0;
                uStack_3c = 0;
                iVar2 = (**(code **)(*(int *)(iStack_30 + 4) + 0x38))(iStack_30,&local_40);
                if ((iVar2 == 0) && (local_40 != 0 || uStack_3c != 0)) {
                  for (uVar4 = 0; (int)uVar4 < (int)(uint)*(byte *)(*(int *)(iStack_30 + 4) + 0x30);
                      uVar4 = uVar4 + 1) {
                    uVar8 = uStack_3c * 2 << 0x20 - (0x20 - ((uVar4 ^ 0xffffffff) & 0x1f)) |
                            local_40 >> (uVar4 & 0x1f);
                    if ((uVar4 & 0x20) != 0) {
                      uVar8 = uStack_3c >> (uVar4 & 0x1f);
                    }
                    if ((uVar8 & 1) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
                      halt_baddata();
                    }
                  }
                }
                iVar2 = (**(code **)(*(int *)PTR_PTR_4037487c + 4))(iStack_30);
              }
              if (iVar2 == 0) {
                uVar4 = param_3;
                uStack_2c = param_2;
                do {
                  pcVar7 = *(code **)(*(int *)(iStack_30 + 4) + 0x68);
                  if ((pcVar7 != (code *)0x0) && (iVar2 = (*pcVar7)(iStack_30,0), iVar2 != 0)) {
                    return iVar2;
                  }
                  iVar2 = (*(code *)**(undefined4 **)PTR_PTR_4037487c)(iStack_30);
                  uVar8 = uStack_2c;
                  if (iVar2 != 0) {
                    uVar9 = 0;
                    goto LAB_403780e8;
                  }
                  if ((uVar5 - 1 < uVar4) && (uStack_2c % uVar5 == 0)) {
                    iVar2 = (**(code **)(*(int *)(iStack_30 + 4) + 0x1c))(iStack_30,uStack_2c);
                    uVar1 = uVar5;
                  }
                  else {
                    iVar2 = (**(code **)(*(int *)(iStack_30 + 4) + 0x18))(iStack_30,uStack_2c);
                    uVar1 = uVar6;
                  }
                  uStack_2c = uVar8 + uVar1;
                  uVar4 = uVar4 - uVar1;
                  if (param_3 <= uVar4) {
                    /* WARNING: Subroutine does not return */
                    FUN_40381d9c(PTR_s_esp_flash_api_c_3c034314_0x1b_403748a4,0x2a9,
                                 PTR_s_esp_flash_erase_region_403748a0,
                                 PTR_s_len_remain_<_len_4037489c);
                  }
                  uVar9 = 1;
                  if (iVar2 != 0 || uVar4 == 0) goto LAB_403780e8;
                  iVar2 = (**(code **)(*(int *)PTR_PTR_4037487c + 4))(iStack_30,0);
                } while (iVar2 == 0);
                uVar9 = 1;
LAB_403780e8:
                iVar2 = (**(code **)(*(int *)PTR_PTR_4037487c + 0xc))
                                  (iStack_30,iVar2,uVar9,param_2,param_3);
              }
            }
          }
          else {
            iVar2 = 0x102;
          }
        }
        else {
          iVar2 = 0x102;
        }
      }
      else {
        iVar2 = DAT_40374880;
      }
    }
  }
  return iVar2;
}

/* ---- objdump fallback (Ghidra stopped on excw / literal pool) ----
40377f28:  entry	a1, 64
40377f2b:  s32i.n	a2, a1, 16
40377f2d:  l32r	a8, 0x4037487c
40377f30:  l32i.n	a8, a8, 0
40377f32:  l32i.n	a8, a8, 8
40377f34:  addi	a10, a1, 16
40377f37:  callx8	a8
40377f3a:  mov.n	a2, a10
40377f3c:  bnez	a10, 0x4037813c
40377f3f:  l32i.n	a8, a1, 16
40377f41:  l32i.n	a9, a8, 4
40377f43:  l32i.n	a10, a9, 24
40377f45:  beqz	a10, 0x40378100
40377f48:  l32i.n	a9, a9, 28
40377f4a:  beqz	a9, 0x40378108
40377f4d:  beqz.n	a8, 0x40377f6d
40377f4f:  l32i.n	a9, a8, 8
40377f51:  l32i.n	a9, a9, 8
40377f53:  beqz.n	a9, 0x40377f6d
40377f55:  mov.n	a12, a4
40377f57:  mov.n	a11, a3
40377f59:  l32i	a10, a8, 12
40377f5c:  callx8	a9
40377f5f:  movi	a8, 0x10d
40377f62:  bne	a10, a8, 0x40377f68
40377f65:  j	0x4037810e
L_40377f68:
40377f68:  beqz.n	a10, 0x40377f6d
40377f6a:  call8	0x40381ce0   ; FUN_40381ce0
L_40377f6d:
40377f6d:  l32i.n	a10, a1, 16
40377f6f:  l32i.n	a8, a10, 4
40377f71:  l32i.n	a9, a8, 28
40377f73:  beqz.n	a9, 0x40377f7a
40377f75:  l32i.n	a6, a8, 36
40377f77:  j	0x40377f7c
L_40377f7a:
40377f7a:  movi.n	a6, 0
L_40377f7c:
40377f7c:  l32i.n	a7, a8, 32
40377f7e:  beqz	a7, 0x40378114
40377f81:  remu	a9, a6, a7
40377f84:  bnez	a9, 0x4037811c
40377f87:  l32i.n	a9, a10, 20
40377f89:  bgeu	a9, a3, 0x40377f8f
40377f8c:  j	0x40378124
L_40377f8f:
40377f8f:  add.n	a5, a3, a4
40377f91:  bgeu	a9, a5, 0x40377f97
40377f94:  j	0x4037812a
L_40377f97:
40377f97:  remu	a9, a3, a7
40377f9a:  bnez	a9, 0x40378130
40377f9d:  remu	a9, a4, a7
40377fa0:  bnez	a9, 0x40378139
40377fa3:  beqz	a4, 0x4037813c
40377fa6:  l32i.n	a9, a8, 56
40377fa8:  beqz	a9, 0x40378049
40377fab:  l8ui	a8, a8, 48
40377fae:  beqz	a8, 0x40378049
40377fb1:  l32r	a8, 0x4037487c
40377fb4:  l32i	a8, a8, 0
40377fb7:  l32i.n	a8, a8, 0
40377fb9:  callx8	a8
40377fbc:  mov.n	a2, a10
40377fbe:  bnez	a10, 0x4037813c
40377fc1:  movi.n	a8, 0
40377fc3:  s32i.n	a8, a1, 0
40377fc5:  s32i.n	a8, a1, 4
40377fc7:  l32i.n	a10, a1, 16
40377fc9:  l32i.n	a8, a10, 4
40377fcb:  l32i.n	a8, a8, 56
40377fcd:  mov.n	a11, a1
40377fcf:  callx8	a8
40377fd2:  mov.n	a11, a10
40377fd4:  bnez	a10, 0x40378039
40377fd7:  l32i.n	a15, a1, 0
40377fd9:  l32i.n	a10, a1, 4
40377fdb:  or	a8, a15, a10
40377fde:  bnez	a8, 0x4037802a
40377fe1:  j	0x40378039
40377fe4:  l32i.n	a13, a9, 52
40377fe6:  addx8	a13, a8, a13
40377fe9:  movi.n	a14, 32
40377feb:  and	a14, a8, a14
40377fee:  add.n	a12, a10, a10
40377ff0:  movi.n	a9, -1
40377ff2:  xor	a9, a8, a9
40377ff5:  ssl	a9
40377ff8:  sll	a12, a12
40377ffb:  ssr	a8
40377ffe:  srl	a9, a15
40378001:  or	a9, a12, a9
40378004:  ssr	a8
40378007:  srl	a12, a10
4037800a:  movnez	a9, a12, a14
4037800d:  bbci	a9, 0, 0x40378022
40378010:  l32i.n	a12, a13, 0
40378012:  l32i.n	a9, a13, 4
40378014:  add.n	a9, a12, a9
40378016:  excw
40378019:  excw
4037801c:  bnone	a12, a9, 0x40378022
4037801f:  l32r	a11, 0x40374898
L_40378022:
40378022:  addi.n	a8, a8, 1
40378024:  j	0x4037802c
40378027:  ill
---- end objdump fallback ---- */
