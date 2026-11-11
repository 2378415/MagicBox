// strings: pxRingbuffer->pucAcquire >= pxRingbuffer->pucHea | ringbuf.c | prvCheckItemFitsByteBuffer

uint FUN_40379db4(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint in_t0;
  
  uVar2 = param_1[8];
  if (((-(param_1[0xc] + -1) & 0xffU) == 0) || ((uint)param_1[0xd] <= uVar2)) {
    uVar2 = in_t0;
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x136,
                 PTR_s_prvCheckItemFitsByteBuffer_40374aac,
                 PTR_s_pxRingbuffer_>pucAcquire_>__pxRi_40374aa8);
  }
  uVar1 = param_1[0xb];
  if (uVar2 == uVar1) {
    uVar2 = (uint)((param_1[2] & 4U) == 0);
  }
  else if (uVar2 < uVar1) {
    uVar2 = -(param_2 + -1);
  }
  else {
    uVar2 = -((*param_1 - (uVar2 - uVar1)) + -1);
  }
  return uVar2;
}