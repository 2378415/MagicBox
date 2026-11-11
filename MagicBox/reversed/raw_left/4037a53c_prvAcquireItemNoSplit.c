// 4037a53c  prvAcquireItemNoSplit  FUN_4037a53c  size=146
// strings: ( ( ( UBaseType_t ) ( pxRingbuffer->pucAcquire ) | pxRingbuffer->pucAcquire >= pxRingbuffer->pucHea | ringbuf.c | prvAcquireItemNoSplit | xRemLen >= sizeof(ItemHeader_t)

int * FUN_4037a53c(int *param_1,int param_2)

{
  char cVar1;
  int extraout_a3;
  int extraout_a3_00;
  int *piVar2;
  int *piVar3;
  undefined *puVar4;
  int *piVar5;
  int iVar6;
  undefined *puVar7;
  undefined *puVar8;
  int *piVar9;
  int *in_t0;
  
  piVar2 = (int *)param_1[8];
  puVar7 = (undefined *)param_1[0xd];
  cVar1 = '\0';
  piVar3 = param_1;
  if (((uint)piVar2 & 3) != 0) {
    puVar7 = PTR_s_prvAcquireItemNoSplit_40374bac;
    piVar2 = in_t0;
    cVar1 = FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x149,
                         PTR_s_prvAcquireItemNoSplit_40374bac,
                         PTR_s_______UBaseType_t_____pxRingbuff_40374ba8);
    piVar3 = piVar2;
    in_t0 = piVar2;
  }
  piVar9 = (int *)param_1[0xc];
  if ((piVar2 < piVar9) || (iVar6 = 0, cVar1 != '\x01')) {
    puVar7 = PTR_s_prvAcquireItemNoSplit_40374bac;
    piVar2 = in_t0;
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x14a,PTR_s_prvAcquireItemNoSplit_40374bac,
                 PTR_s_pxRingbuffer_>pucAcquire_>__pxRi_40374b64);
    piVar3 = piVar2;
    iVar6 = extraout_a3;
    in_t0 = piVar2;
  }
  puVar8 = puVar7 + -(int)piVar2;
  if ((int)puVar8 < 8) {
    puVar7 = PTR_s_prvAcquireItemNoSplit_40374bac;
    puVar8 = PTR_s_xRemLen_>__sizeof_ItemHeader_t__40374bb0;
    piVar2 = in_t0;
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x14b);
    piVar3 = piVar2;
    iVar6 = extraout_a3_00;
  }
  puVar4 = (undefined *)((param_2 + 3U & 0xfffffffc) + 8);
  if (puVar8 < puVar4) {
    piVar2[1] = 2;
    *piVar2 = iVar6;
    piVar2 = piVar9;
  }
  piVar5 = (int *)((int)piVar2 + (int)puVar4);
  *piVar2 = param_2;
  piVar2[1] = 0;
  if ((uint)((int)puVar7 - (int)piVar5) < 8) {
    piVar5 = piVar9;
  }
  piVar3[8] = (int)piVar5;
  if (piVar5 == (int *)piVar3[0xb]) {
    piVar3[2] = piVar3[2] | 4;
  }
  return piVar2 + 2;
}


