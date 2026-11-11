void FUN_4200e9f4(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = *(int *)(param_1 + 0x2af0);
  iVar3 = *(int *)(param_1 + 11000);
  uVar5 = *(undefined4 *)(param_1 + 0x2b3c);
  iVar2 = param_1 + DAT_42000c64;
  *(int *)(iVar2 + 8) = iVar4;
  *(int *)(iVar2 + 0xc) = iVar3;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  *(undefined4 *)(iVar2 + 0x18) = uVar5;
  *(undefined4 *)(iVar2 + 0x1c) = 1;
  *(undefined4 *)(iVar2 + 0x28) = 0;
  *(undefined **)(iVar2 + 0x38) = PTR_FUN_42000c6c;
  *(int *)(iVar2 + 0x3c) = param_1;
  if (*(byte *)(iVar4 + 3) < 3) {
    uVar1 = *(undefined1 *)(iVar3 + 6);
  }
  else {
    uVar1 = (undefined1)(1 << 0x20 - (0x20 - (*(byte *)(iVar3 + 6) - 1 & 0x1f)));
  }
  *(undefined1 *)(param_1 + DAT_42000c64 + 0x11) = uVar1;
  usb_xfer_submit();
  return;
}