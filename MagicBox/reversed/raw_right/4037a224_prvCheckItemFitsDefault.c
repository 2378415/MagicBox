// 4037a224  prvCheckItemFitsDefault  FUN_4037a224  size=164
// strings: ( ( ( UBaseType_t ) ( pxRingbuffer->pucAcquire ) | pxRingbuffer->pucAcquire >= pxRingbuffer->pucHea | ringbuf.c | prvCheckItemFitsDefault

undefined8 FUN_4037a224(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint in_t0;
  undefined8 uVar4;
  
  uVar2 = 0;
  uVar1 = param_1[8];
  if ((param_1[8] & 3U) != 0) {
    uVar2 = in_t0;
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x11a,PTR_s_prvCheckItemFitsDefault_40374b04
                 ,PTR_s_______UBaseType_t_____pxRingbuff_40374aec);
    uVar1 = uVar2;
    in_t0 = uVar2;
  }
  if (((-(uVar2 - 1) & 0xff) == 0) ||
     (uVar4 = CONCAT44(param_1[0xc],param_1[0xd]), (uint)param_1[0xd] <= uVar1)) {
    uVar1 = in_t0;
    uVar4 = FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x11b,
                         PTR_s_prvCheckItemFitsDefault_40374b04,
                         PTR_s_pxRingbuffer_>pucAcquire_>__pxRi_40374aa8);
  }
  uVar2 = param_2 + 3U & 0xfffffffc;
  uVar3 = param_1[0xb];
  if (uVar1 == uVar3) {
    uVar1 = (uint)((param_1[2] & 4U) == 0);
  }
  else if (uVar1 < uVar3) {
    uVar1 = -((uVar3 - uVar1) + -1);
  }
  else if ((int)uVar4 - uVar1 < uVar2 + 8) {
    if ((param_1[2] & 1U) == 0) {
      uVar1 = -((uVar3 - (int)((ulonglong)uVar4 >> 0x20)) + -1);
    }
    else {
      uVar2 = uVar2 + 0x10;
      uVar1 = -((*param_1 - (uVar1 - uVar3)) + -1);
    }
  }
  else {
    uVar1 = 1;
  }
  return CONCAT44(uVar2,uVar1);
}


