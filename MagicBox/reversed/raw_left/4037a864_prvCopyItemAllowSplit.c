// 4037a864  prvCopyItemAllowSplit  FUN_4037a864  size=218
// strings: ( ( ( UBaseType_t ) ( pxRingbuffer->pucAcquire ) | pxRingbuffer->pucAcquire >= pxRingbuffer->pucHea | ringbuf.c | prvCopyItemAllowSplit | xRemLen >= sizeof(ItemHeader_t) | opyItemAllowSplit | temAllowSplit

void FUN_4037a864(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  undefined *in_a13;
  uint in_t0;
  
  piVar3 = *(int **)(param_1 + 0x20);
  uVar1 = 0;
  uVar4 = *(uint *)(param_1 + 0x34);
  if (((uint)piVar3 & 3) != 0) {
    in_a13 = PTR_s_______UBaseType_t_____pxRingbuff_40374ba8;
    uVar1 = in_t0;
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x1aa,PTR_s_prvCopyItemAllowSplit_40374bfc);
    uVar4 = uVar1;
    in_t0 = uVar1;
  }
  piVar5 = *(int **)(param_1 + 0x30);
  if (((-(uVar1 - 1) & 0xff) != 0) || (piVar3 < piVar5)) {
    piVar5 = (int *)PTR_s_prvCopyItemAllowSplit_40374bfc;
    in_a13 = PTR_s_pxRingbuffer_>pucAcquire_>__pxRi_40374b64;
    uVar4 = in_t0;
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x1ab);
    in_t0 = uVar4;
  }
  uVar4 = uVar4 - (int)piVar3;
  if ((int)uVar4 < 8) {
    piVar5 = (int *)PTR_s_prvCopyItemAllowSplit_40374bfc;
    in_a13 = PTR_s_xRemLen_>__sizeof_ItemHeader_t__40374bb0;
    uVar4 = in_t0;
    FUN_40381ce4(PTR_s_ringbuf_c_3c03b768_0x1d_40374b58,0x1ac);
  }
  uVar1 = param_3 + 3U & 0xfffffffc;
  if (uVar4 < uVar1 + 8) {
    iVar2 = uVar4 - 8;
    piVar3[1] = (int)in_a13;
    *piVar3 = iVar2;
    *(int **)(param_1 + 0x20) = piVar3 + 2;
    if (iVar2 == 0) {
      piVar3[1] = 2;
      piVar3 = piVar5;
    }
    else {
      (*DAT_4037450c)(piVar3 + 2,param_2,iVar2);
      uVar4 = piVar3[1];
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
      piVar3[1] = uVar4 | 4;
      param_2 = param_2 + iVar2;
      param_3 = param_3 - iVar2;
      uVar1 = uVar1 - iVar2;
      piVar3 = *(int **)(param_1 + 0x30);
    }
  }
  piVar3[1] = 0;
  *piVar3 = param_3;
  *(int **)(param_1 + 0x20) = piVar3 + 2;
  (*DAT_4037450c)(piVar3 + 2,param_2,param_3);
  iVar2 = *(int *)(param_1 + 0x20) + uVar1;
  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
  *(int *)(param_1 + 0x20) = iVar2;
  if ((uint)(*(int *)(param_1 + 0x34) - iVar2) < 8) {
    iVar2 = *(int *)(param_1 + 0x30);
    *(int *)(param_1 + 0x20) = iVar2;
  }
  if (iVar2 == *(int *)(param_1 + 0x2c)) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 4;
  }
  *(int *)(param_1 + 0x24) = iVar2;
  return;
}


