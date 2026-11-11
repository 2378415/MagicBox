// 4037a410  prvCopyItemAllowSplit  FUN_4037a410  size=233
// strings: ( ( ( UBaseType_t ) ( pxRingbuffer->pucAcquire ) | pxRingbuffer->pucAcquire >= pxRingbuffer->pucHea | ringbuf.c | prvCopyItemAllowSplit | xRemLen >= sizeof(ItemHeader_t) | ault

/* WARNING: Type propagation algorithm not settling */

void FUN_4037a410(int param_1,undefined *param_2,int param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined *puVar6;
  undefined4 *in_t0;
  
  uVar1 = param_3 + 3U & 0xfffffffc;
  puVar4 = *(undefined4 **)(param_1 + 0x34);
  puVar2 = *(undefined4 **)(param_1 + 0x20);
  puVar6 = (undefined *)((int)puVar4 - (int)puVar2);
  if (((uint)puVar2 & 3) != 0) {
    puVar6 = PTR_s_prvCopyItemAllowSplit_40374b4c;
    puVar4 = in_t0;
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x1aa,PTR_s_prvCopyItemAllowSplit_40374b4c,
                 PTR_s_______UBaseType_t_____pxRingbuff_40374aec);
  }
  if (((-(*(int *)(param_1 + 0x30) + -1) & 0xffU) == 0) || (puVar4 <= puVar2)) {
    puVar6 = PTR_s_prvCopyItemAllowSplit_40374b4c;
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x1ab,PTR_s_prvCopyItemAllowSplit_40374b4c,
                 PTR_s_pxRingbuffer_>pucAcquire_>__pxRi_40374aa8);
  }
  if (puVar6 < (undefined *)0x8) {
    puVar6 = PTR_s_prvCopyItemAllowSplit_40374b4c;
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x1ac,PTR_s_prvCopyItemAllowSplit_40374b4c,
                 PTR_s_xRemLen_>__sizeof_ItemHeader_t__40374af4);
  }
  if (puVar6 < (undefined *)(uVar1 + 8)) {
    puVar2[1] = 0;
    puVar6 = puVar6 + -8;
    *puVar2 = puVar6;
    iVar5 = *(int *)(param_1 + 0x20) + 8;
    *(int *)(param_1 + 0x20) = iVar5;
    if (puVar6 == (undefined *)0x0) {
      puVar2[1] = puVar2[1] | 2;
    }
    else {
      (*DAT_403744d4)(iVar5,param_2,puVar6);
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
      param_2 = param_2 + (int)puVar6;
      param_3 = param_3 - (int)puVar6;
      uVar1 = uVar1 - (int)puVar6;
      puVar2[1] = puVar2[1] | 4;
    }
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x30);
  }
  piVar3 = *(int **)(param_1 + 0x20);
  *piVar3 = param_3;
  piVar3[1] = 0;
  iVar5 = *(int *)(param_1 + 0x20) + 8;
  *(int *)(param_1 + 0x20) = iVar5;
  (*DAT_403744d4)(iVar5,param_2,param_3);
  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
  iVar5 = *(int *)(param_1 + 0x20) + uVar1;
  *(int *)(param_1 + 0x20) = iVar5;
  if ((uint)(*(int *)(param_1 + 0x34) - iVar5) < 8) {
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x30);
  }
  if (*(int *)(param_1 + 0x20) == *(int *)(param_1 + 0x2c)) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 4;
  }
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x20);
  return;
}


