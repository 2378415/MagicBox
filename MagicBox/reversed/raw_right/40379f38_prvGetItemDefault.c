// 40379f38  prvGetItemDefault  FUN_40379f38  size=324
// strings: pxIsSplit != ((void *)0) | (pxRingbuffer->xItemsWaiting > 0) && ((pxRingbuf | ringbuf.c | prvGetItemDefault | ( ( ( UBaseType_t ) ( pxRingbuffer->pucRead ) &  | pxRingbuffer->pucRead >= pxRingbuffer->pucHead & | (pxHeader->xItemLen <= pxRingbuffer->xMaxItemSiz | pxHeader->xItemLen <= pxRingbuffer->xMaxItemSize | pcReturn >= pxRingbuffer->pucHead && pcReturn <= | pcReturn >= pxRingbuffer->pucHead && pcReturn < 

void FUN_40379f38(int *param_1,uint *param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  uint extraout_a3;
  int *extraout_a3_00;
  int *extraout_a3_01;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  undefined *puVar7;
  int *in_t0;
  ulonglong uVar8;
  undefined8 uVar9;
  
  uVar4 = param_1[10];
  piVar2 = param_1;
  if (param_2 == (uint *)0x0) {
    piVar2 = in_t0;
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x217,PTR_s_prvGetItemDefault_40374ad4,
                 PTR_s_pxIsSplit______void___0__40374ad0);
    uVar4 = extraout_a3;
    in_t0 = piVar2;
  }
  if ((param_1[0xe] < 1) ||
     ((uVar8 = (ulonglong)uVar4 << 0x20, param_1[9] == uVar4 &&
      (uVar8 = (ulonglong)uVar4 << 0x20, (param_1[2] & 4U) == 0)))) {
    piVar2 = in_t0;
    uVar8 = FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x218,
                         PTR_s_prvGetItemDefault_40374ad4,
                         PTR_s__pxRingbuffer_>xItemsWaiting_>_0_40374a98);
    in_t0 = piVar2;
  }
  if ((uVar8 & 0x300000000) != 0) {
    piVar2 = in_t0;
    uVar8 = FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x219,
                         PTR_s_prvGetItemDefault_40374ad4,
                         PTR_s_______UBaseType_t_____pxRingbuff_40374ad8);
    in_t0 = piVar2;
  }
  piVar5 = (int *)(uVar8 >> 0x20);
  if (((-((int)uVar8 + -1) & 0xffU) == 0) ||
     (piVar6 = (int *)piVar2[0xd], piVar3 = (int *)piVar2[0xc], piVar6 <= piVar5)) {
    piVar6 = (int *)PTR_s_prvGetItemDefault_40374ad4;
    piVar2 = in_t0;
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x21a,PTR_s_prvGetItemDefault_40374ad4,
                 PTR_s_pxRingbuffer_>pucRead_>__pxRingb_40374aa0);
    piVar3 = piVar2;
    piVar5 = extraout_a3_00;
    in_t0 = piVar2;
  }
  puVar7 = (undefined *)piVar2[1];
  if (((-(*piVar5 + -1) & 0xffU) == 0) && ((piVar5[1] & 2U) == 0)) {
    piVar6 = (int *)PTR_s_prvGetItemDefault_40374ad4;
    puVar7 = PTR_s__pxHeader_>xItemLen_<__pxRingbuf_40374adc;
    piVar2 = in_t0;
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x21b);
    piVar3 = piVar2;
    piVar5 = extraout_a3_01;
    in_t0 = piVar2;
  }
  if ((piVar5[1] & 2U) != 0) {
    piVar2[10] = (int)piVar3;
    if (puVar7 < (undefined *)*piVar3) {
      piVar6 = (int *)PTR_s_prvGetItemDefault_40374ad4;
      piVar2 = in_t0;
      FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x223,PTR_s_prvGetItemDefault_40374ad4,
                   PTR_s_pxHeader_>xItemLen_<__pxRingbuff_40374ae0);
      piVar3 = piVar2;
      in_t0 = piVar2;
    }
    piVar5 = piVar3;
  }
  iVar1 = piVar2[10];
  uVar9 = CONCAT44(piVar5,*piVar5);
  if (*piVar5 == 0) {
    if (((-(int)((int)piVar3 + -1) & 0xffU) != 0) && ((-(int)((int)piVar6 + -1) & 0xffU) != 0))
    goto LAB_4037a04e;
    piVar6 = (int *)PTR_s_prvGetItemDefault_40374ad4;
    piVar2 = in_t0;
    uVar9 = FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x228,
                         PTR_s_prvGetItemDefault_40374ad4,
                         PTR_s_pcReturn_>__pxRingbuffer_>pucHea_40374ae4);
    piVar3 = piVar2;
    in_t0 = piVar2;
  }
  if (((-(int)((int)piVar3 + -1) & 0xffU) == 0) || (piVar6 <= (int *)(iVar1 + 8))) {
    piVar2 = in_t0;
    uVar9 = FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x22b,
                         PTR_s_prvGetItemDefault_40374ad4,
                         PTR_s_pcReturn_>__pxRingbuffer_>pucHea_40374ae8);
  }
LAB_4037a04e:
  piVar5 = (int *)((ulonglong)uVar9 >> 0x20);
  *param_4 = (int)uVar9;
  piVar2[0xe] = piVar2[0xe] + -1;
  *param_2 = (uint)piVar5[1] >> 2 & 1;
  iVar1 = piVar2[10] + (*piVar5 + 3U & 0xfffffffc) + 8;
  piVar2[10] = iVar1;
  if ((uint)(piVar2[0xd] - iVar1) < 8) {
    piVar2[10] = piVar2[0xc];
  }
  return;
}


