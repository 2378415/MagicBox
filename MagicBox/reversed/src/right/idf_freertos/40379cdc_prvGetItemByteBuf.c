// strings: (pxRingbuffer->xItemsWaiting > 0) && ((pxRingbuf | ringbuf.c | prvGetItemByteBuf | pxRingbuffer->pucRead >= pxRingbuffer->pucHead & | pxRingbuffer->pucRead == pxRingbuffer->pucFree

void FUN_40379cdc(uint param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint in_t0;
  
  uVar1 = param_1;
  if (0 < *(int *)(param_1 + 0x38)) {
    uVar1 = *(uint *)(param_1 + 0x28);
    uVar3 = *(uint *)(param_1 + 0x24);
    if ((uVar1 != uVar3) || ((*(uint *)(param_1 + 8) & 4) != 0)) goto LAB_40379d06;
  }
  param_1 = in_t0;
  uVar3 = FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x23f,PTR_s_prvGetItemByteBuf_40374a9c
                       ,PTR_s__pxRingbuffer_>xItemsWaiting_>_0_40374a98);
  in_t0 = param_1;
LAB_40379d06:
  if (((-(*(int *)(param_1 + 0x30) + -1) & 0xffU) == 0) ||
     (uVar2 = *(uint *)(param_1 + 0x34), *(uint *)(param_1 + 0x34) <= uVar1)) {
    param_1 = in_t0;
    uVar3 = FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x240,
                         PTR_s_prvGetItemByteBuf_40374a9c,
                         PTR_s_pxRingbuffer_>pucRead_>__pxRingb_40374aa0);
    uVar2 = param_1;
    in_t0 = param_1;
  }
  if (uVar1 != *(uint *)(param_1 + 0x2c)) {
    param_1 = in_t0;
    uVar3 = FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x241,
                         PTR_s_prvGetItemByteBuf_40374a9c,
                         PTR_s_pxRingbuffer_>pucRead____pxRingb_40374aa4);
    uVar2 = param_1;
  }
  if ((uVar3 < uVar1) || ((*(uint *)(param_1 + 8) & 4) != 0)) {
    if ((param_3 == 0) || (uVar2 - uVar1 <= param_3)) {
      *param_4 = uVar2 - uVar1;
      *(int *)(param_1 + 0x38) =
           *(int *)(param_1 + 0x38) - (*(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x28));
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x30);
    }
    else {
      *param_4 = param_3;
      *(uint *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) - param_3;
      *(uint *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + param_3;
    }
  }
  else if ((param_3 == 0) || (uVar3 - uVar1 <= param_3)) {
    *param_4 = uVar3 - uVar1;
    *(int *)(param_1 + 0x38) =
         *(int *)(param_1 + 0x38) - (*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x28));
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x24);
  }
  else {
    *param_4 = param_3;
    *(uint *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) - param_3;
    *(uint *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + param_3;
  }
  return;
}