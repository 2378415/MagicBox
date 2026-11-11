// 4037a390  FUN_4037a390  FUN_4037a390  size=125
// strings: pxRingbuffer->pucAcquire >= pxRingbuffer->pucHea | ringbuf.c | prvCopyItemByteBuf

void FUN_4037a390(int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                 uint param_6)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x20);
  if (((-(*(int *)(param_1 + 0x30) + -1) & 0xffU) == 0) ||
     (param_6 = *(uint *)(param_1 + 0x34), param_6 <= uVar2)) {
    uVar2 = FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x1df,
                         PTR_s_prvCopyItemByteBuf_40374b48,
                         PTR_s_pxRingbuffer_>pucAcquire_>__pxRi_40374aa8);
  }
  param_6 = param_6 - uVar2;
  if (param_6 < param_3) {
    (*DAT_403744d4)(uVar2,param_2,param_6);
    *(uint *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + param_6;
    param_2 = param_2 + param_6;
    param_3 = param_3 - param_6;
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x30);
  }
  (*DAT_403744d4)(*(undefined4 *)(param_1 + 0x20),param_2,param_3);
  *(uint *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + param_3;
  iVar1 = *(int *)(param_1 + 0x20) + param_3;
  *(int *)(param_1 + 0x20) = iVar1;
  if (iVar1 == *(int *)(param_1 + 0x34)) {
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x30);
  }
  if (*(int *)(param_1 + 0x20) == *(int *)(param_1 + 0x2c)) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 4;
  }
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x20);
  return;
}


