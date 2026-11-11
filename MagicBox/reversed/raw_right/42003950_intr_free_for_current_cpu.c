// 42003950  intr_free_for_current_cpu  FUN_42003950  size=236
// strings: intr_free_for_current_cpu

undefined4 FUN_42003950(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  bool bVar4;
  ushort *puVar5;
  int in_t0;
  longlong lVar6;
  
  (*(code *)PTR_FUN_420003a8)(PTR_DAT_420004a0,0xffffffff);
  (*(code *)PTR_FUN_420004c8)(param_1);
  puVar5 = (ushort *)*param_1;
  if ((*puVar5 & 4) == 0) {
    bVar4 = false;
  }
  else {
    iVar1 = *(int *)(puVar5 + 2);
    if (iVar1 != 0) {
      lVar6 = ZEXT48(puVar5) << 0x20;
      goto LAB_420039b2;
    }
    lVar6 = (*(code *)PTR_FUN_42000044)
                      (PTR_s_intr_alloc_c_3c031654_0x20_42000490,0x300,
                       PTR_s_intr_free_for_current_cpu_420004d0,PTR_DAT_420004cc);
    do {
      iVar1 = (int)lVar6;
      if (param_1[1] == iVar1) {
        if (in_t0 == 0) {
          *(undefined4 *)((int)((ulonglong)lVar6 >> 0x20) + 4) = *(undefined4 *)(iVar1 + 0x14);
        }
        else {
          *(undefined4 *)(in_t0 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
        }
        (*(code *)PTR_FUN_420004c0)();
        break;
      }
      iVar1 = *(int *)(iVar1 + 0x14);
LAB_420039b2:
      in_t0 = (int)lVar6;
      lVar6 = CONCAT44((int)((ulonglong)lVar6 >> 0x20),iVar1);
    } while (iVar1 != 0);
    if (*(int *)(*param_1 + 4) == 0) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
  }
  if (((*(uint *)*param_1 & 8) != 0) || (bVar4)) {
    uVar2 = *(uint *)*param_1 >> 0x11 & 0x1f;
    FUN_42026a8c(uVar2,0,uVar2);
    *(ushort *)*param_1 = *(ushort *)*param_1 & 0xfff2;
    *(uint *)*param_1 = *(uint *)*param_1 & DAT_420004b8 | DAT_420004d4;
    puVar3 = (uint *)((*(uint *)*param_1 >> 0x10 & 1) * 4 + DAT_420004bc);
    uVar2 = *puVar3;
    *puVar3 = 1 << 0x20 - (0x20 - (*(uint *)*param_1 >> 0x11 & 0x1f)) & uVar2 ^ uVar2;
  }
  (*(code *)PTR_FUN_420003ac)(PTR_DAT_420004a0);
  (*(code *)PTR_FUN_420004c0)(param_1);
  return 0;
}


