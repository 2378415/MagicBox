// 4200bacc  usb_serial_jtag_return_char  FUN_4200bacc  size=234
// strings: s_ctx.peek_char == NONE | usb_serial_jtag_vfs.c | usb_serial_jtag_return_char | Pm7@L

int FUN_4200bacc(undefined4 param_1,int param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 uVar4;
  int iVar5;
  
  (*(code *)PTR_FUN_420000b8)(PTR_DAT_42000c14);
  puVar1 = PTR_DAT_42000bf0;
  iVar2 = 0;
  while( true ) {
    if (iVar2 == param_3) goto LAB_4200bb83;
    iVar5 = *(int *)puVar1;
    if (iVar5 == -1) break;
    *(undefined4 *)puVar1 = 0xffffffff;
    uVar4 = (undefined1)iVar5;
    if (iVar5 == 0xd) {
LAB_4200baf3:
      if (*(int *)(puVar1 + 0x14) == 1) {
LAB_4200bb1c:
        *(undefined1 *)(param_2 + iVar2) = 10;
        (*(code *)PTR_FUN_420000bc)(PTR_DAT_42000c14);
        return iVar2 + 1;
      }
      if (*(int *)(puVar1 + 0x14) == 0) {
        iVar5 = *(int *)puVar1;
        if (iVar5 == -1) {
          iVar5 = (**(code **)(puVar1 + 0x1c))(param_1);
          if (iVar5 == -1) {
            if (*(int *)puVar1 != -1) {
LAB_4200bb38:
              (*(code *)PTR_FUN_420000a8)
                        (PTR_s_usb_serial_jtag_vfs_c_3c03627c_0x30_42000c20,0xdf,
                         PTR_s_usb_serial_jtag_return_char_42000c1c,
                         PTR_s_s_ctx_peek_char____NONE_42000c18);
            }
            *(undefined4 *)puVar1 = 0xd;
            goto LAB_4200bb4e;
          }
          if (iVar5 == 10) goto LAB_4200bb1c;
          if (*(int *)puVar1 != -1) goto LAB_4200bb38;
        }
        else {
          *(undefined4 *)puVar1 = 0xffffffff;
          if (iVar5 == 10) goto LAB_4200bb1c;
        }
        *(int *)puVar1 = iVar5;
      }
      *(undefined1 *)(param_2 + iVar2) = 0xd;
      iVar2 = iVar2 + 1;
    }
    else {
LAB_4200bb72:
      *(undefined1 *)(param_2 + iVar2) = uVar4;
      iVar2 = iVar2 + 1;
      if (iVar5 == 10) {
        (*(code *)PTR_FUN_420000bc)(PTR_DAT_42000c14);
        return iVar2;
      }
    }
  }
  iVar5 = (**(code **)(puVar1 + 0x1c))(param_1);
  if (iVar5 == 0xd) goto LAB_4200baf3;
  if (iVar5 != -1) {
    uVar4 = (undefined1)iVar5;
    goto LAB_4200bb72;
  }
LAB_4200bb4e:
  param_3 = iVar2;
LAB_4200bb83:
  (*(code *)PTR_FUN_420000bc)(PTR_DAT_42000c14);
  if (param_3 == 0) {
    puVar3 = (undefined4 *)FUN_42020b54();
    *puVar3 = 0xb;
    return -1;
  }
  return param_3;
}


