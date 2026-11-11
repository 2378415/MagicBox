// strings: fd >= 0 && fd < 3 |  :cVc |  3cVs | c != NONE | s_ctx[fd]->peek_char == NONE | uart_vfs.c | uart_return_char | Pm7@L | uart_read

uint FUN_42008d60(uint param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (2 < param_1) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_uart_vfs_c_3c035a28_0x25_420009f0,0x111,PTR_s_uart_read_42000a20,
               PTR_s_fd_>__0____fd_<_3_420009e8);
  }
  iVar4 = *(int *)(PTR_PTR_42000978 + param_1 * 4);
  iVar6 = iVar4 + 8;
  (*(code *)PTR_FUN_420000b8)(iVar6);
  if (*(char *)(iVar4 + 0x10) == '\0') {
    iVar8 = *(int *)(iVar4 + 4);
    if (iVar8 == -1) {
      iVar8 = (**(code **)(iVar4 + 0x20))(param_1);
      uVar1 = (**(code **)(iVar4 + 0x24))(param_1);
      iVar7 = *(int *)(iVar4 + 4);
      if (iVar8 == -1) {
        if (iVar7 == -1) goto LAB_42008dec;
        uVar1 = uVar1 + 1;
        uVar1 = (uVar1 < param_3) * uVar1 + (uVar1 >= param_3) * param_3;
        iVar8 = iVar7;
        goto joined_r0x42008de5;
      }
      uVar1 = uVar1 + 1;
      if (iVar7 != -1) goto LAB_42008e04;
      uVar1 = (param_3 < uVar1) * param_3 + (param_3 >= uVar1) * uVar1;
      if (uVar1 != 0) goto LAB_42008ee4;
    }
    else {
      *(undefined4 *)(iVar4 + 4) = 0xffffffff;
      iVar2 = (**(code **)(iVar4 + 0x24))(param_1);
      iVar7 = *(int *)(iVar4 + 4);
      uVar1 = iVar2 + 1;
      if (iVar7 != -1) {
LAB_42008e04:
        uVar1 = uVar1 + 1;
      }
      uVar1 = (uVar1 < param_3) * uVar1 + (uVar1 >= param_3) * param_3;
      if (uVar1 != 0) {
LAB_42008ee4:
        param_3 = 0;
        goto LAB_42008e3c;
      }
      if (iVar7 != -1) {
LAB_42008e70:
        (*(code *)PTR_FUN_420000a8)
                  (PTR_s_uart_vfs_c_3c035a28_0x25_420009f0,0x10b,PTR_s_uart_return_char_42000a2c,
                   PTR_s_s_ctx_fd__>peek_char____NONE_42000a28);
LAB_42008e82:
        *(int *)(iVar4 + 4) = iVar8;
        (*(code *)PTR_FUN_420000bc)(iVar6);
        if (param_3 != 0) {
          return param_3;
        }
        goto LAB_42008ec8;
      }
    }
    *(int *)(iVar4 + 4) = iVar8;
  }
  else {
    uVar1 = (**(code **)(iVar4 + 0x24))(param_1);
    iVar7 = *(int *)(iVar4 + 4);
    if (iVar7 != -1) {
      uVar1 = uVar1 + 1;
    }
LAB_42008dec:
    uVar1 = (uVar1 < param_3) * uVar1 + (uVar1 >= param_3) * param_3;
    iVar8 = iVar7;
joined_r0x42008de5:
    if (uVar1 != 0) {
      param_3 = 0;
      do {
        if (iVar8 == -1) {
          iVar8 = (**(code **)(iVar4 + 0x20))(param_1);
          if (iVar8 == -1) {
            (*(code *)PTR_FUN_420000a8)
                      (PTR_s_uart_vfs_c_3c035a28_0x25_420009f0,299,PTR_s_uart_read_42000a20,
                       PTR_s_c____NONE_42000a24);
          }
        }
        else {
          *(undefined4 *)(iVar4 + 4) = 0xffffffff;
        }
LAB_42008e3c:
        if (iVar8 == 0xd) {
          if (*(int *)(iVar4 + 0x18) == 1) {
            uVar5 = 10;
          }
          else {
            if (*(int *)(iVar4 + 0x18) == 0) {
              iVar7 = *(int *)(iVar4 + 4);
              if (iVar7 == -1) {
                iVar7 = (**(code **)(iVar4 + 0x20))(param_1);
                iVar8 = 0xd;
                if (iVar7 == -1) {
                  if (*(int *)(iVar4 + 4) == -1) goto LAB_42008e82;
                  goto LAB_42008e70;
                }
                if (iVar7 == 10) goto LAB_42008e94;
                if (*(int *)(iVar4 + 4) != -1) goto LAB_42008e70;
              }
              else {
                *(undefined4 *)(iVar4 + 4) = 0xffffffff;
                if (iVar7 == 10) {
LAB_42008e94:
                  uVar1 = uVar1 - 1;
                  uVar5 = 10;
                  goto LAB_42008eab;
                }
              }
              *(int *)(iVar4 + 4) = iVar7;
            }
            uVar5 = 0xd;
          }
        }
        else {
          uVar5 = (undefined1)iVar8;
        }
LAB_42008eab:
        *(undefined1 *)(param_2 + param_3) = uVar5;
        param_3 = param_3 + 1;
        if (uVar1 <= param_3) {
          (*(code *)PTR_FUN_420000bc)(iVar6);
          return param_3;
        }
        iVar8 = *(int *)(iVar4 + 4);
      } while( true );
    }
  }
  (*(code *)PTR_FUN_420000bc)(iVar6);
LAB_42008ec8:
  puVar3 = (undefined4 *)FUN_42020b54();
  *puVar3 = 0xb;
  return 0xffffffff;
}