// strings: pxRingbuffer->pucAcquire >= pxRingbuffer->pucHea | ringbuf.c | prvCopyItemByteBuf

void FUN_4037a7f4(int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                 uint param_6)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x20);
  if ((uVar2 < *(uint *)(param_1 + 0x30)) || (param_6 = *(uint *)(param_1 + 0x34), param_6 <= uVar2)
     ) {
    uVar2 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x1df,
                         PTR_s_prvCopyItemByteBuf_40374bf8,
                         PTR_s_pxRingbuffer_>pucAcquire_>__pxRi_40374b64);
  }
  param_6 = param_6 - uVar2;
  if (param_6 < param_3) {
    (*DAT_4037450c)(uVar2,param_2,param_6);
    uVar2 = *(uint *)(param_1 + 0x30);
    *(uint *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + param_6;
    param_2 = param_2 + param_6;
    param_3 = param_3 - param_6;
    *(uint *)(param_1 + 0x20) = uVar2;
  }
  (*DAT_4037450c)(uVar2,param_2,param_3);
  iVar1 = *(int *)(param_1 + 0x20) + param_3;
  *(uint *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + param_3;
  *(int *)(param_1 + 0x20) = iVar1;
  if (iVar1 == *(int *)(param_1 + 0x34)) {
    iVar1 = *(int *)(param_1 + 0x30);
    *(int *)(param_1 + 0x20) = iVar1;
  }
  if (iVar1 == *(int *)(param_1 + 0x2c)) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 4;
  }
  *(int *)(param_1 + 0x24) = iVar1;
  return;
}