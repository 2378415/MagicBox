// strings: ( ( ( UBaseType_t ) ( pucItem ) & (0x03) ) == 0  | pucItem >= pxRingbuffer->pucHead | ringbuf.c | prvReturnItemDefault | pucItem <= pxRingbuffer->pucTail | pxCurHeader->xItemLen <= pxRingbuffer->xMaxItemS | (pxCurHeader->uxItemFlags & ( ( UBaseType_t ) 2  | (pxCurHeader->uxItemFlags & ( ( UBaseType_t ) 1  | pxRingbuffer->pucFree <= pxRingbuffer->pucHead +

void FUN_40379e18(int *param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  uint in_t0;
  
  if ((param_2 & 3) != 0) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x265,PTR_s_prvReturnItemDefault_40374ab4,
                 PTR_s_______UBaseType_t_____pucItem_____40374ab0);
  }
  if (param_2 < (uint)param_1[0xc]) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x266,PTR_s_prvReturnItemDefault_40374ab4,
                 PTR_s_pucItem_>__pxRingbuffer_>pucHead_40374ab8);
  }
  if ((uint)param_1[0xd] < param_2) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x267,PTR_s_prvReturnItemDefault_40374ab4,
                 PTR_s_pucItem_<__pxRingbuffer_>pucTail_40374abc);
  }
  if ((uint)param_1[1] < *(uint *)(param_2 - 8)) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x26b,PTR_s_prvReturnItemDefault_40374ab4,
                 PTR_s_pxCurHeader_>xItemLen_<__pxRingb_40374ac0);
  }
  uVar1 = *(uint *)(param_2 - 4);
  if ((uVar1 & 2) != 0) {
    uVar1 = in_t0;
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x26c,PTR_s_prvReturnItemDefault_40374ab4,
                 PTR_s__pxCurHeader_>uxItemFlags_______U_40374ac4);
    in_t0 = uVar1;
  }
  if ((uVar1 & 1) != 0) {
    uVar1 = in_t0;
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x26d,PTR_s_prvReturnItemDefault_40374ab4,
                 PTR_s__pxCurHeader_>uxItemFlags_______U_40374ac8);
  }
  *(uint *)(param_2 - 4) = uVar1 & 0xfffffffb;
  *(uint *)(param_2 - 4) = uVar1 & 0xfffffffb | 1;
  piVar2 = (int *)param_1[0xb];
  while ((uVar1 = piVar2[1], (uVar1 & 3) != 0 && (param_1[0xb] != param_1[10]))) {
    if ((uVar1 & 2) == 0) {
      uVar1 = param_1[0xb] + (*piVar2 + 3U & 0xfffffffc) + 8;
      param_1[0xb] = uVar1;
      if ((uint)(param_1[0xc] + *param_1) < uVar1) {
        FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x282,
                     PTR_s_prvReturnItemDefault_40374ab4,
                     PTR_s_pxRingbuffer_>pucFree_<__pxRingb_40374acc);
      }
    }
    else {
      piVar2[1] = uVar1 | 1;
      param_1[0xb] = param_1[0xc];
    }
    if ((uint)(param_1[0xd] - param_1[0xb]) < 8) {
      param_1[0xb] = param_1[0xc];
    }
    piVar2 = (int *)param_1[0xb];
  }
  uVar1 = param_1[2];
  if ((uVar1 & 4) != 0) {
    if (param_1[0xb] == param_1[8]) {
      if (param_1[0xb] == param_1[10]) {
        param_1[2] = uVar1 & 0xfffffffb;
      }
    }
    else {
      param_1[2] = uVar1 & 0xfffffffb;
    }
  }
  return;
}