// strings: heap != NULL && 'realloc() pointer is outside he | heap_caps_base.c | heap_caps_realloc_base | old_size > 0

int FUN_40376384(int param_1,uint param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint local_40 [4];
  uint local_30;
  uint local_2c [11];
  
  local_40[0] = 4;
  local_30 = param_2;
  local_2c[0] = param_3;
  FUN_40377900(local_40,&local_30,local_2c);
  if (param_1 == 0) {
    iVar2 = FUN_40376294(local_40[0],local_30,local_2c[0]);
    return iVar2;
  }
  if (local_30 == 0) {
    FUN_40376244(param_1);
    return 0;
  }
  if (DAT_403746a8 < local_30) {
    return 0;
  }
  if (DAT_40374670 < (uint)(param_1 + DAT_40374698)) {
LAB_4037640a:
    for (iVar2 = *DAT_4037469c;
        (iVar2 != 0 &&
        (((*(int *)(iVar2 + 0x1c) == 0 || (param_1 < *(int *)(iVar2 + 0xc))) ||
         (*(int *)(iVar2 + 0x10) <= param_1)))); iVar2 = *(int *)(iVar2 + 0x20)) {
    }
    if (iVar2 != 0) {
      param_3 = 0;
      bVar1 = false;
      goto LAB_40376446;
    }
    FUN_40381d9c(PTR_s_heap_caps_base_c_3c0314cc_0x16_4037467c,0xe1,
                 PTR_s_heap_caps_realloc_base_403746b0,
                 PTR_s_heap____NULL_____realloc___point_403746ac);
  }
  else {
    param_3 = *(uint *)(param_1 + -4);
    for (iVar2 = *DAT_4037469c;
        (iVar2 != 0 &&
        (((*(int *)(iVar2 + 0x1c) == 0 || ((int)param_3 < *(int *)(iVar2 + 0xc))) ||
         (*(int *)(iVar2 + 0x10) <= (int)param_3)))); iVar2 = *(int *)(iVar2 + 0x20)) {
    }
    if (iVar2 == 0) {
      FUN_40381d9c(PTR_s_heap_caps_base_c_3c0314cc_0x16_4037467c,0xd8,
                   PTR_s_heap_caps_realloc_base_403746b0,
                   PTR_s_heap____NULL_____realloc___point_403746ac);
      goto LAB_4037640a;
    }
  }
  bVar1 = true;
LAB_40376446:
  if (*(int *)(iVar2 + 0x1c) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0;
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      uVar3 = uVar3 | *(uint *)(iVar4 * 4 + iVar2);
    }
  }
  if ((((!(bool)((bVar1 ^ 1U) & (uVar3 & local_2c[0]) == local_2c[0])) || (4 < local_40[0])) ||
      (iVar4 = FUN_403808e8(*(int *)(iVar2 + 0x1c),param_1), iVar4 == 0)) &&
     (iVar4 = FUN_40376294(local_40[0],local_30,local_2c[0]), iVar4 != 0)) {
    if (bVar1) {
      uVar3 = FUN_40380848(*(undefined4 *)(iVar2 + 0x1c),param_3);
    }
    else {
      uVar3 = FUN_40380848(*(undefined4 *)(iVar2 + 0x1c),param_1);
    }
    if (uVar3 == 0) {
      uVar3 = FUN_40381d9c(PTR_s_heap_caps_base_c_3c0314cc_0x16_4037467c,0x10a,
                           PTR_s_heap_caps_realloc_base_403746b0,PTR_s_old_size_>_0_403746b4);
    }
    (*DAT_403744d4)(iVar4,param_1,(uVar3 < local_30) * uVar3 + (uVar3 >= local_30) * local_30);
    FUN_40376244(param_1);
  }
  return iVar4;
}