// 4037a6c8  prvCheckItemFitsDefault  FUN_4037a6c8  size=150
// strings: ( ( ( UBaseType_t ) ( pxRingbuffer->pucAcquire ) | pxRingbuffer->pucAcquire >= pxRingbuffer->pucHea | ringbuf.c | prvCheckItemFitsDefault

undefined8 FUN_4037a6c8(int *param_1,int param_2)

{
  uint uVar1;
  undefined *extraout_a3;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  undefined *puVar7;
  int *in_t0;
  undefined8 uVar8;
  
  puVar5 = (undefined *)param_1[8];
  piVar3 = param_1;
  if (((uint)puVar5 & 3) != 0) {
    piVar3 = in_t0;
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x11a,PTR_s_prvCheckItemFitsDefault_40374bc0
                 ,PTR_s_______UBaseType_t_____pxRingbuff_40374ba8);
    puVar5 = extraout_a3;
    in_t0 = piVar3;
  }
  puVar7 = (undefined *)param_1[0xc];
  if ((puVar5 < puVar7) ||
     (uVar8 = CONCAT44(puVar5,(undefined *)param_1[0xd]), (undefined *)param_1[0xd] <= puVar5)) {
    puVar7 = PTR_s_prvCheckItemFitsDefault_40374bc0;
    piVar3 = in_t0;
    uVar8 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x11b,
                         PTR_s_prvCheckItemFitsDefault_40374bc0,
                         PTR_s_pxRingbuffer_>pucAcquire_>__pxRi_40374b64);
  }
  uVar6 = (uint)((ulonglong)uVar8 >> 0x20);
  uVar4 = param_1[0xb];
  uVar2 = param_2 + 3U & 0xfffffffc;
  if (uVar6 == uVar4) {
    uVar1 = (uint)param_1[2] >> 2 & 1 ^ 1;
  }
  else if (uVar6 < uVar4) {
    uVar1 = -(uVar4 + (-1 - uVar6));
  }
  else {
    uVar1 = 1;
    if ((int)uVar8 - uVar6 < uVar2 + 8) {
      if ((piVar3[2] & 1U) == 0) {
        uVar1 = -(uVar4 + (-1 - (int)puVar7));
      }
      else {
        uVar2 = uVar2 + 0x10;
        uVar1 = -((*piVar3 - (uVar6 - uVar4)) + -1);
      }
    }
  }
  return CONCAT44(uVar2,uVar1);
}


