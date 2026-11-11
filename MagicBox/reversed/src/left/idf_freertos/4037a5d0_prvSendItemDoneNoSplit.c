// strings: ( ( ( UBaseType_t ) ( pucItem ) & (0x03) ) == 0  | pucItem >= pxRingbuffer->pucHead | ringbuf.c | prvSendItemDoneNoSplit | pucItem <= pxRingbuffer->pucTail | pxCurHeader->xItemLen <= pxRingbuffer->xMaxItemS | (pxCurHeader->uxItemFlags & ( ( UBaseType_t ) 2  | (pxCurHeader->uxItemFlags & ( ( UBaseType_t ) 8 

void FUN_4037a5d0(int *param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  undefined *puVar6;
  undefined *puVar7;
  uint uVar8;
  int *in_t0;
  undefined8 uVar9;
  
  if ((param_2 & 3) != 0) {
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x16e,PTR_s_prvSendItemDoneNoSplit_40374bb4,
                 PTR_s_______UBaseType_t_____pucItem_____40374b6c);
  }
  uVar4 = param_1[0xc];
  if (param_2 < uVar4) {
    uVar4 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x16f,
                         PTR_s_prvSendItemDoneNoSplit_40374bb4,
                         PTR_s_pucItem_>__pxRingbuffer_>pucHead_40374b74);
  }
  uVar9 = CONCAT44(param_1[0xd],uVar4);
  if ((uint)param_1[0xd] < param_2) {
    uVar9 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x170,
                         PTR_s_prvSendItemDoneNoSplit_40374bb4,
                         PTR_s_pucItem_<__pxRingbuffer_>pucTail_40374b78);
  }
  if ((uint)param_1[1] < *(uint *)(param_2 - 8)) {
    uVar9 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x174,
                         PTR_s_prvSendItemDoneNoSplit_40374bb4,
                         PTR_s_pxCurHeader_>xItemLen_<__pxRingb_40374b7c);
  }
  piVar1 = *(int **)(param_2 - 4);
  puVar6 = (undefined *)0x2;
  if (((uint)piVar1 & 2) != 0) {
    puVar6 = PTR_s_prvSendItemDoneNoSplit_40374bb4;
    piVar1 = in_t0;
    uVar9 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x175,
                         PTR_s_prvSendItemDoneNoSplit_40374bb4,
                         PTR_s__pxCurHeader_>uxItemFlags_______U_40374b80);
    in_t0 = piVar1;
  }
  uVar4 = 8;
  if (((uint)piVar1 & 8) != 0) {
    puVar6 = PTR_s_prvSendItemDoneNoSplit_40374bb4;
    piVar1 = in_t0;
    uVar9 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x176,
                         PTR_s_prvSendItemDoneNoSplit_40374bb4,
                         PTR_s__pxCurHeader_>uxItemFlags_______U_40374bb8);
    in_t0 = piVar1;
  }
  iVar2 = param_1[0xe];
  *(uint *)(param_2 - 4) = (uint)piVar1 & 0xfffffffb | uVar4;
  piVar1 = (int *)param_1[9];
  param_1[0xe] = iVar2 + 1;
  puVar7 = (undefined *)0xa;
  uVar8 = 0xfffffffc;
  do {
    piVar5 = (int *)uVar9;
    uVar3 = piVar1[1];
    if ((uVar3 & (uint)puVar7) == 0) {
      return;
    }
    if ((uVar3 & (uint)puVar6) == 0) {
      piVar1 = (int *)(param_1[9] + (*piVar1 + 3U & uVar8) + 8);
      param_1[9] = (int)piVar1;
      if ((int *)((int)piVar5 + *param_1) < piVar1) {
        puVar6 = PTR_s_prvSendItemDoneNoSplit_40374bb4;
        puVar7 = PTR_s_pxRingbuffer_>pucWrite_<__pxRing_40374bbc;
        piVar1 = in_t0;
        uVar9 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x18e);
        in_t0 = piVar1;
      }
    }
    else {
      piVar1[1] = uVar3 | uVar4;
      param_1[9] = (int)piVar5;
      piVar1 = piVar5;
    }
    if ((uint)((int)((ulonglong)uVar9 >> 0x20) - (int)piVar1) < 8) {
      param_1[9] = (int)(int *)uVar9;
      piVar1 = (int *)uVar9;
    }
  } while (piVar1 != (int *)param_1[8]);
  return;
}