// strings: (pxRingbuffer->xItemsWaiting > 0) && ((pxRingbuf | ringbuf.c | prvGetItemByteBuf | pxRingbuffer->pucRead >= pxRingbuffer->pucHead & | pxRingbuffer->pucRead == pxRingbuffer->pucFree

void FUN_4037a20c(uint param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint in_t0;
  undefined8 uVar5;
  
  uVar1 = param_1;
  if (*(int *)(param_1 + 0x38) < 1) {
LAB_4037a224:
    param_1 = in_t0;
    uVar3 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x23f,
                         PTR_s_prvGetItemByteBuf_40374b54,
                         PTR_s__pxRingbuffer_>xItemsWaiting_>_0_40374b50);
    in_t0 = param_1;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x28);
    uVar3 = *(uint *)(param_1 + 0x24);
    if ((uVar1 == uVar3) && ((*(uint *)(param_1 + 8) & 4) == 0)) goto LAB_4037a224;
  }
  uVar5 = CONCAT44(*(uint *)(param_1 + 0x30),uVar3);
  if ((uVar1 < *(uint *)(param_1 + 0x30)) ||
     (uVar3 = *(uint *)(param_1 + 0x34), *(uint *)(param_1 + 0x34) <= uVar1)) {
    param_1 = in_t0;
    uVar5 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x240,
                         PTR_s_prvGetItemByteBuf_40374b54,
                         PTR_s_pxRingbuffer_>pucRead_>__pxRingb_40374b5c);
    uVar3 = param_1;
    in_t0 = param_1;
  }
  if (uVar1 != *(uint *)(param_1 + 0x2c)) {
    param_1 = in_t0;
    uVar5 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x241,
                         PTR_s_prvGetItemByteBuf_40374b54,
                         PTR_s_pxRingbuffer_>pucRead____pxRingb_40374b60);
    uVar3 = param_1;
  }
  uVar4 = (uint)uVar5;
  if ((uVar4 < uVar1) || ((*(uint *)(param_1 + 8) & 4) != 0)) {
    uVar3 = uVar3 - uVar1;
    if ((param_3 == 0) || (uVar3 <= param_3)) {
      *param_4 = uVar3;
      iVar2 = *(int *)(param_1 + 0x38) - uVar3;
      uVar4 = (uint)((ulonglong)uVar5 >> 0x20);
      goto LAB_4037a2a1;
    }
  }
  else {
    uVar3 = uVar4 - uVar1;
    if ((param_3 == 0) || (uVar3 <= param_3)) {
      *param_4 = uVar3;
      iVar2 = *(int *)(param_1 + 0x38) - uVar3;
      goto LAB_4037a2a1;
    }
  }
  *param_4 = param_3;
  uVar4 = uVar1 + param_3;
  iVar2 = *(int *)(param_1 + 0x38) - param_3;
LAB_4037a2a1:
  *(int *)(param_1 + 0x38) = iVar2;
  *(uint *)(param_1 + 0x28) = uVar4;
  return;
}