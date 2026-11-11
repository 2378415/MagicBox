// strings: pxIsSplit != ((void *)0) | (pxRingbuffer->xItemsWaiting > 0) && ((pxRingbuf | ringbuf.c | prvGetItemDefault | ( ( ( UBaseType_t ) ( pxRingbuffer->pucRead ) &  | pxRingbuffer->pucRead >= pxRingbuffer->pucHead & | (pxHeader->xItemLen <= pxRingbuffer->xMaxItemSiz | pxHeader->xItemLen <= pxRingbuffer->xMaxItemSize | pcReturn >= pxRingbuffer->pucHead && pcReturn <= | pcReturn >= pxRingbuffer->pucHead && pcReturn < 

void FUN_4037a420(uint *param_1,uint *param_2,undefined4 param_3,undefined4 *param_4)

{
  uint *extraout_a3;
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  undefined *puVar6;
  uint uVar7;
  uint *in_t0;
  undefined8 uVar8;
  
  puVar1 = param_1;
  if (param_2 == (uint *)0x0) {
    puVar1 = in_t0;
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x217,PTR_s_prvGetItemDefault_40374b90,
                 PTR_s_pxIsSplit______void___0__40374b8c);
    in_t0 = puVar1;
  }
  if (((int)param_1[0xe] < 1) ||
     ((puVar2 = (uint *)param_1[10], (uint *)param_1[9] == puVar2 && ((param_1[2] & 4) == 0)))) {
    puVar1 = in_t0;
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x218,PTR_s_prvGetItemDefault_40374b90,
                 PTR_s__pxRingbuffer_>xItemsWaiting_>_0_40374b50);
    puVar2 = puVar1;
    in_t0 = puVar1;
  }
  if (((uint)puVar2 & 3) != 0) {
    puVar1 = in_t0;
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x219,PTR_s_prvGetItemDefault_40374b90,
                 PTR_s_______UBaseType_t_____pxRingbuff_40374b94);
    puVar2 = puVar1;
    in_t0 = puVar1;
  }
  puVar5 = (uint *)puVar1[0xc];
  if ((puVar2 < puVar5) || (puVar4 = (uint *)puVar1[0xd], puVar4 <= puVar2)) {
    puVar5 = (uint *)PTR_s_prvGetItemDefault_40374b90;
    puVar1 = in_t0;
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x21a,PTR_s_prvGetItemDefault_40374b90,
                 PTR_s_pxRingbuffer_>pucRead_>__pxRingb_40374b5c);
    puVar2 = puVar1;
    puVar4 = extraout_a3;
    in_t0 = puVar1;
  }
  uVar8 = CONCAT44(puVar4,*puVar2);
  uVar7 = puVar1[1];
  puVar6 = (undefined *)(puVar2[1] & 2);
  if (uVar7 < *puVar2) {
    if (puVar6 == (undefined *)0x0) {
      puVar5 = (uint *)PTR_s_prvGetItemDefault_40374b90;
      puVar6 = PTR_s__pxHeader_>xItemLen_<__pxRingbuf_40374b98;
      puVar1 = in_t0;
      uVar8 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x21b);
      puVar2 = puVar1;
      in_t0 = puVar1;
      goto LAB_4037a4b4;
    }
LAB_4037a4b6:
    uVar3 = *puVar5;
    uVar8 = CONCAT44(puVar4,uVar3);
    puVar1[10] = (uint)puVar5;
    puVar2 = puVar5;
    if (uVar7 < uVar3) {
      puVar5 = (uint *)PTR_s_prvGetItemDefault_40374b90;
      puVar6 = PTR_s_pxHeader_>xItemLen_<__pxRingbuff_40374b9c;
      puVar1 = in_t0;
      uVar8 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x223);
      puVar2 = puVar1;
      in_t0 = puVar1;
    }
  }
  else {
LAB_4037a4b4:
    puVar4 = (uint *)((ulonglong)uVar8 >> 0x20);
    if (puVar6 != (undefined *)0x0) goto LAB_4037a4b6;
  }
  if ((int)uVar8 == 0) {
    if ((puVar2 + 2 <= (uint *)((ulonglong)uVar8 >> 0x20)) && (uVar7 == 0)) goto LAB_4037a512;
    puVar5 = (uint *)PTR_s_prvGetItemDefault_40374b90;
    puVar6 = PTR_s_pcReturn_>__pxRingbuffer_>pucHea_40374ba0;
    puVar1 = in_t0;
    uVar8 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x228);
    puVar2 = puVar1;
    in_t0 = puVar1;
  }
  if (((-(int)(puVar6 + -1) & 0xffU) != 0) || (uVar7 != 0)) {
    puVar5 = (uint *)PTR_s_prvGetItemDefault_40374b90;
    puVar1 = in_t0;
    uVar8 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x22b,
                         PTR_s_prvGetItemDefault_40374b90,
                         PTR_s_pcReturn_>__pxRingbuffer_>pucHea_40374ba4);
    puVar2 = puVar1;
  }
LAB_4037a512:
  *param_4 = (int)uVar8;
  uVar7 = puVar2[1];
  puVar1[0xe] = puVar1[0xe] - 1;
  *param_2 = uVar7 >> 2 & 1;
  puVar2 = (uint *)((int)puVar2 + (*puVar2 + 3 & 0xfffffffc) + 8);
  if ((uint)((int)((ulonglong)uVar8 >> 0x20) - (int)puVar2) < 8) {
    puVar2 = puVar5;
  }
  puVar1[10] = (uint)puVar2;
  return;
}