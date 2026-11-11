// 4037a120  prvSendItemDoneNoSplit  FUN_4037a120  size=257
// strings: ( ( ( UBaseType_t ) ( pucItem ) & (0x03) ) == 0  | pucItem >= pxRingbuffer->pucHead | ringbuf.c | prvSendItemDoneNoSplit | pucItem <= pxRingbuffer->pucTail | pxCurHeader->xItemLen <= pxRingbuffer->xMaxItemS | (pxCurHeader->uxItemFlags & ( ( UBaseType_t ) 2  | (pxCurHeader->uxItemFlags & ( ( UBaseType_t ) 8  | pxRingbuffer->pucWrite <= pxRingbuffer->pucHead 

void FUN_4037a120(int *param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  uint in_t0;
  
  if ((param_2 & 3) != 0) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x16e,PTR_s_prvSendItemDoneNoSplit_40374af8,
                 PTR_s_______UBaseType_t_____pucItem_____40374ab0);
  }
  if (param_2 < (uint)param_1[0xc]) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x16f,PTR_s_prvSendItemDoneNoSplit_40374af8,
                 PTR_s_pucItem_>__pxRingbuffer_>pucHead_40374ab8);
  }
  if ((uint)param_1[0xd] < param_2) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x170,PTR_s_prvSendItemDoneNoSplit_40374af8,
                 PTR_s_pucItem_<__pxRingbuffer_>pucTail_40374abc);
  }
  if ((uint)param_1[1] < *(uint *)(param_2 - 8)) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x174,PTR_s_prvSendItemDoneNoSplit_40374af8,
                 PTR_s_pxCurHeader_>xItemLen_<__pxRingb_40374ac0);
  }
  uVar1 = *(uint *)(param_2 - 4);
  if ((uVar1 & 2) != 0) {
    uVar1 = in_t0;
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x175,PTR_s_prvSendItemDoneNoSplit_40374af8,
                 PTR_s__pxCurHeader_>uxItemFlags_______U_40374ac4);
    in_t0 = uVar1;
  }
  if ((uVar1 & 8) != 0) {
    uVar1 = in_t0;
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x176,PTR_s_prvSendItemDoneNoSplit_40374af8,
                 PTR_s__pxCurHeader_>uxItemFlags_______U_40374afc);
  }
  *(uint *)(param_2 - 4) = uVar1 & 0xfffffffb;
  *(uint *)(param_2 - 4) = uVar1 & 0xfffffffb | 8;
  param_1[0xe] = param_1[0xe] + 1;
  piVar2 = (int *)param_1[9];
  do {
    uVar1 = piVar2[1];
    if ((uVar1 & 10) == 0) {
      return;
    }
    if ((uVar1 & 2) == 0) {
      uVar1 = param_1[9] + (*piVar2 + 3U & 0xfffffffc) + 8;
      param_1[9] = uVar1;
      if ((uint)(param_1[0xc] + *param_1) < uVar1) {
        FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x18e,
                     PTR_s_prvSendItemDoneNoSplit_40374af8,
                     PTR_s_pxRingbuffer_>pucWrite_<__pxRing_40374b00);
      }
    }
    else {
      piVar2[1] = uVar1 | 8;
      param_1[9] = param_1[0xc];
    }
    if ((uint)(param_1[0xd] - param_1[9]) < 8) {
      param_1[9] = param_1[0xc];
    }
    piVar2 = (int *)param_1[9];
  } while (piVar2 != (int *)param_1[8]);
  return;
}


