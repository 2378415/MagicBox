int FUN_4200df94(int param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  int iVar2;
  
  if (param_1 == 0 || param_2 == 0) {
    iVar2 = -2;
  }
  else {
    iVar2 = param_1 + DAT_42000bd4;
    FUN_4200d844(*(undefined4 *)(param_1 + 0xab0));
    uVar1 = *(ushort *)(param_2 + 6);
    *(int *)(param_1 + 0xa78) = param_1;
    *(int *)(param_1 + 0xa7c) = param_1 + DAT_42000be4;
    *(int *)(param_1 + 0xa84) = param_2;
    *(undefined4 *)(param_1 + 0xa88) = param_3;
    *(uint *)(param_1 + 0xa8c) = (uint)uVar1;
    *(undefined4 *)(param_1 + 0xa98) = 500;
    *(undefined4 *)(param_1 + 0xaa8) = 0;
    *(undefined4 *)(param_1 + 0xaac) = 0;
    iVar2 = usb_xfer_submit(iVar2);
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0xa94);
    }
    FUN_4200d860(*(undefined4 *)(param_1 + 0xab0));
  }
  return iVar2;
}