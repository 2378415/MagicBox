// 4037a2a8  prvCheckItemFitsByteBuffer  FUN_4037a2a8  size=87
// strings: pxRingbuffer->pucAcquire >= pxRingbuffer->pucHea | ringbuf.c | prvCheckItemFitsByteBuffer

uint FUN_4037a2a8(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint in_t0;
  
  uVar1 = param_1[8];
  if ((uVar1 < (uint)param_1[0xc]) || ((uint)param_1[0xd] <= uVar1)) {
    uVar1 = in_t0;
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x136,
                 PTR_s_prvCheckItemFitsByteBuffer_40374b68,
                 PTR_s_pxRingbuffer_>pucAcquire_>__pxRi_40374b64);
  }
  uVar2 = param_1[0xb];
  if (uVar1 == uVar2) {
    uVar1 = (uint)param_1[2] >> 2 & 1 ^ 1;
  }
  else if (uVar1 < uVar2) {
    uVar1 = -(param_2 + -1);
  }
  else {
    uVar1 = -((*param_1 - (uVar1 - uVar2)) + -1);
  }
  return uVar1;
}


