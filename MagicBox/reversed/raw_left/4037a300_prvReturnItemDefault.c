// 4037a300  prvReturnItemDefault  FUN_4037a300  size=284
// strings: ( ( ( UBaseType_t ) ( pucItem ) & (0x03) ) == 0  | pucItem >= pxRingbuffer->pucHead | ringbuf.c | prvReturnItemDefault | pucItem <= pxRingbuffer->pucTail | pxCurHeader->xItemLen <= pxRingbuffer->xMaxItemS | (pxCurHeader->uxItemFlags & ( ( UBaseType_t ) 2  | (pxCurHeader->uxItemFlags & ( ( UBaseType_t ) 1 

void FUN_4037a300(int *param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;
  int *in_t0;
  undefined8 uVar8;
  
  if ((param_2 & 3) != 0) {
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x265,PTR_s_prvReturnItemDefault_40374b70,
                 PTR_s_______UBaseType_t_____pucItem_____40374b6c);
  }
  uVar3 = param_1[0xc];
  if (param_2 < uVar3) {
    uVar3 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x266,
                         PTR_s_prvReturnItemDefault_40374b70,
                         PTR_s_pucItem_>__pxRingbuffer_>pucHead_40374b74);
  }
  uVar8 = CONCAT44(param_1[0xd],uVar3);
  if ((uint)param_1[0xd] < param_2) {
    uVar8 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x267,
                         PTR_s_prvReturnItemDefault_40374b70,
                         PTR_s_pucItem_<__pxRingbuffer_>pucTail_40374b78);
  }
  if ((uint)param_1[1] < *(uint *)(param_2 - 8)) {
    uVar8 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x26b,
                         PTR_s_prvReturnItemDefault_40374b70,
                         PTR_s_pxCurHeader_>xItemLen_<__pxRingb_40374b7c);
  }
  piVar1 = *(int **)(param_2 - 4);
  puVar5 = (undefined *)0x2;
  if (((uint)piVar1 & 2) != 0) {
    puVar5 = PTR_s_prvReturnItemDefault_40374b70;
    piVar1 = in_t0;
    uVar8 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x26c,
                         PTR_s_prvReturnItemDefault_40374b70,
                         PTR_s__pxCurHeader_>uxItemFlags_______U_40374b80);
    in_t0 = piVar1;
  }
  if (((uint)piVar1 & 1) != 0) {
    puVar5 = PTR_s_prvReturnItemDefault_40374b70;
    piVar1 = in_t0;
    uVar8 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x26d,
                         PTR_s_prvReturnItemDefault_40374b70,
                         PTR_s__pxCurHeader_>uxItemFlags_______U_40374b84);
    in_t0 = piVar1;
  }
  uVar6 = 1;
  piVar2 = (int *)param_1[0xb];
  *(uint *)(param_2 - 4) = (uint)piVar1 & 0xfffffffb | 1;
  uVar3 = piVar2[1];
  if ((uVar3 & 3) != 0) {
    piVar1 = (int *)param_1[10];
    uVar7 = 0xfffffffc;
    do {
      piVar4 = (int *)uVar8;
      if (piVar2 == piVar1) break;
      if ((uVar3 & (uint)puVar5) == 0) {
        piVar2 = (int *)((int)piVar2 + (*piVar2 + 3U & uVar7) + 8);
        param_1[0xb] = (int)piVar2;
        if ((int *)((int)piVar4 + *param_1) < piVar2) {
          puVar5 = PTR_s_prvReturnItemDefault_40374b70;
          piVar1 = (int *)PTR_s_pxRingbuffer_>pucFree_<__pxRingb_40374b88;
          piVar2 = in_t0;
          uVar8 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x282);
          in_t0 = piVar2;
        }
      }
      else {
        piVar2[1] = uVar3 | uVar6;
        param_1[0xb] = (int)piVar4;
        piVar2 = piVar4;
      }
      if ((uint)((int)((ulonglong)uVar8 >> 0x20) - (int)piVar2) < 8) {
        param_1[0xb] = (int)(int *)uVar8;
        piVar2 = (int *)uVar8;
      }
      uVar3 = piVar2[1];
    } while ((uVar3 & 3) != 0);
  }
  if (((param_1[2] & 4U) != 0) && ((param_1[0xb] != param_1[8] || (param_1[0xb] == param_1[10])))) {
    param_1[2] = param_1[2] & 0xfffffffb;
  }
  return;
}


