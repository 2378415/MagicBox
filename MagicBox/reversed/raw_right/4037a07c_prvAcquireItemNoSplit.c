// 4037a07c  prvAcquireItemNoSplit  FUN_4037a07c  size=164
// strings: ( ( ( UBaseType_t ) ( pxRingbuffer->pucAcquire ) | pxRingbuffer->pucAcquire >= pxRingbuffer->pucHea | ringbuf.c | prvAcquireItemNoSplit | xRemLen >= sizeof(ItemHeader_t)

int FUN_4037a07c(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  int in_t0;
  ulonglong uVar8;
  
  puVar6 = *(undefined **)(param_1 + 0x34);
  uVar4 = *(uint *)(param_1 + 0x20);
  uVar8 = CONCAT44(uVar4,param_2 + 3) & 0xfffffffffffffffc;
  puVar7 = puVar6 + -uVar4;
  iVar1 = param_1;
  if ((uVar4 & 3) != 0) {
    puVar6 = PTR_s_prvAcquireItemNoSplit_40374af0;
    puVar7 = PTR_s_______UBaseType_t_____pxRingbuff_40374aec;
    iVar1 = in_t0;
    uVar8 = FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x149);
    in_t0 = iVar1;
  }
  if (((-(*(int *)(param_1 + 0x30) + -1) & 0xffU) == 0) || (puVar6 <= (undefined *)(uVar8 >> 0x20)))
  {
    puVar7 = PTR_s_pxRingbuffer_>pucAcquire_>__pxRi_40374aa8;
    iVar1 = in_t0;
    uVar8 = FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x14a,
                         PTR_s_prvAcquireItemNoSplit_40374af0);
    in_t0 = iVar1;
  }
  if (puVar7 < (undefined *)0x8) {
    puVar7 = PTR_s_xRemLen_>__sizeof_ItemHeader_t__40374af4;
    iVar1 = in_t0;
    uVar8 = FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x14b,
                         PTR_s_prvAcquireItemNoSplit_40374af0);
  }
  puVar5 = (undefined4 *)(uVar8 >> 0x20);
  puVar6 = (undefined *)((int)uVar8 + 8);
  if (puVar7 < puVar6) {
    puVar5[1] = 2;
    *puVar5 = 0;
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x30);
  }
  piVar2 = *(int **)(iVar1 + 0x20);
  *piVar2 = param_2;
  piVar2[1] = 0;
  iVar3 = *(int *)(iVar1 + 0x20);
  puVar6 = puVar6 + iVar3;
  *(undefined **)(iVar1 + 0x20) = puVar6;
  if ((uint)(*(int *)(iVar1 + 0x34) - (int)puVar6) < 8) {
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar1 + 0x30);
  }
  if (*(int *)(iVar1 + 0x20) == *(int *)(iVar1 + 0x2c)) {
    *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 4;
  }
  return iVar3 + 8;
}


