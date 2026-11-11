// 42002d94  heap_caps_init  FUN_42002d94  size=578
// strings: heap_idx <= num_heaps | lock | heap_idx == num_heaps | SLIST_EMPTY(&registered_heaps) | heap_caps_init.c | heap_caps_init | heaps_array != NULL

void FUN_42002d94(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int extraout_a3;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int in_WindowStart;
  int local_40;
  uint uStack_3c;
  uint uStack_38;
  int iStack_34;
  int iStack_30;
  
  iVar2 = FUN_42003090();
  iVar4 = (uint)(in_WindowStart == 0) * (int)&local_40;
  iVar2 = (uint)(in_WindowStart != 0) * ((int)&local_40 - (iVar2 * 0x14 + 0xfU & 0xfffffff0));
  uVar3 = FUN_420030a4(iVar4 + iVar2);
  uStack_3c = uVar3;
  for (uVar6 = 1; uVar6 < uVar3; uVar6 = uVar6 + 1) {
    iVar9 = uVar6 - 1;
    piVar8 = (int *)(iVar9 * 0x14 + iVar4 + iVar2);
    iVar10 = *piVar8;
    iVar7 = piVar8[1];
    if (((*(int *)(uVar6 * 0x14 + iVar4 + iVar2) == iVar10 + iVar7) &&
        (*(int *)(uVar6 * 0x14 + iVar4 + iVar2 + 8) == *(int *)(iVar9 * 0x14 + iVar4 + iVar2 + 8)))
       && (*(char *)(uVar6 * 0x14 + iVar4 + iVar2 + 0x10) ==
           *(char *)(iVar9 * 0x14 + iVar4 + iVar2 + 0x10))) {
      *(undefined4 *)(iVar9 * 0x14 + iVar4 + iVar2 + 8) = 0xffffffff;
      piVar8 = (int *)(uVar6 * 0x14 + iVar4 + iVar2);
      *piVar8 = iVar10;
      piVar8[1] = iVar7 + piVar8[1];
      uStack_3c = uStack_3c - 1;
    }
  }
  iStack_30 = uStack_3c * 0x24;
  iVar7 = (uint)(in_WindowStart == 0) * (iVar4 + iVar2);
  iVar9 = (uint)(in_WindowStart != 0) * ((iVar4 + iVar2) - (iStack_30 + 0xfU & 0xfffffff0));
  uVar6 = 0;
  for (uVar5 = 0; uVar5 < uVar3; uVar5 = uVar5 + 1) {
    iVar10 = *(int *)(uVar5 * 0x14 + iVar4 + iVar2 + 8);
    iStack_34 = uVar6 * 0x24 + iVar7 + iVar9;
    if (iVar10 == -1) {
      (*DAT_42000240)(iStack_34,0,0x24);
    }
    else {
      uStack_38 = uVar6 + 1;
      if (uStack_3c < uStack_38) {
        (*(code *)PTR_FUN_42000044)
                  (PTR_s_heap_caps_init_c_3c030b38_0x16_420003f8,0x6c,PTR_s_heap_caps_init_42000404,
                   PTR_s_heap_idx_<__num_heaps_42000400);
        iVar10 = extraout_a3;
      }
      local_40 = uVar6 * 0x24 + iVar7 + iVar9;
      (*DAT_420002fc)(local_40,PTR_PTR_42000408 + iVar10 * 0x10 + 4,0xc);
      piVar8 = (int *)(uVar5 * 0x14 + iVar4 + iVar2);
      iVar10 = *piVar8;
      *(int *)(local_40 + 0xc) = iVar10;
      *(int *)(local_40 + 0x10) = iVar10 + piVar8[1];
      if (iVar7 + iVar9 + uVar6 * 0x24 == -0x14) {
        (*(code *)PTR_FUN_42000044)
                  (PTR_s_spinlock_h_3c030b80_0x28_42000414,0x35,PTR_s_spinlock_initialize_42000410,
                   PTR_DAT_4200040c);
      }
      iVar10 = uVar6 * 0x24 + iVar7 + iVar9;
      *(undefined4 *)(iVar10 + 0x14) = DAT_42000418;
      *(undefined4 *)(iVar10 + 0x18) = 0;
      if (*(char *)(uVar5 * 0x14 + iVar4 + iVar2 + 0x10) == '\0') {
        FUN_42002d40(iStack_34);
      }
      else {
        *(undefined4 *)(uVar6 * 0x24 + iVar7 + iVar9 + 0x1c) = 0;
      }
      *(undefined4 *)(uVar6 * 0x24 + iVar7 + iVar9 + 0x20) = 0;
      uVar6 = uStack_38;
    }
  }
  if (uStack_3c != uVar6) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_heap_caps_init_c_3c030b38_0x16_420003f8,0x7e,PTR_s_heap_caps_init_42000404,
               PTR_s_heap_idx____num_heaps_4200041c);
  }
  if (*DAT_420003e8 == 0) {
    uVar6 = 0;
    uVar5 = 0;
    goto LAB_42002f7c;
  }
  (*(code *)PTR_FUN_42000044)
            (PTR_s_heap_caps_init_c_3c030b38_0x16_420003f8,0x83,PTR_s_heap_caps_init_42000404,
             PTR_s_SLIST_EMPTY__registered_heaps__42000420);
  do {
    iVar4 = FUN_4202454c(uVar6 * 0x24 + iVar7 + iVar9,DAT_42000424);
    if ((iVar4 != 0) &&
       (uVar5 = (*(code *)PTR_FUN_4200042c)
                          (*(undefined4 *)(uVar6 * 0x24 + iVar7 + iVar9 + 0x1c),iStack_30),
       uVar5 != 0)) break;
    uVar6 = uVar6 + 1;
LAB_42002f7c:
  } while (uVar6 < uStack_3c);
  if (uVar5 == 0) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_heap_caps_init_c_3c030b38_0x16_420003f8,0x92,PTR_s_heap_caps_init_42000404,
               PTR_s_heaps_array____NULL_42000428);
  }
  (*DAT_420002fc)(uVar5,iVar7 + iVar9,iStack_30);
  for (uVar3 = 0; uVar3 < uStack_3c; uVar3 = uVar3 + 1) {
    iVar4 = uVar3 * 0x24 + uVar5;
    if (*(int *)(iVar4 + 0x1c) != 0) {
      (*(code *)PTR_FUN_420003fc)(*(int *)(iVar4 + 0x1c),iVar4 + 0x14);
    }
    puVar1 = DAT_420003e8;
    if (uVar3 == 0) {
      *(uint *)(uVar5 + 0x20) = *DAT_420003e8;
      *puVar1 = uVar5;
    }
    else {
      iVar2 = uVar5 + uVar3 * 0x24 + -0x24;
      *(undefined4 *)(iVar4 + 0x20) = *(undefined4 *)(iVar2 + 0x20);
      *(int *)(iVar2 + 0x20) = iVar4;
    }
  }
  return;
}


