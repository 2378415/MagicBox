// strings: reserved[i].start <= reserved[i].end | reserved[i + 1].start > reserved[i].start | memory_layout_utils.c | s_prepare_reserved_regions

void FUN_42003000(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint in_t0;
  undefined8 uVar5;
  
  *param_1 = *(undefined4 *)(*DAT_42000438 + 4);
  param_1[1] = DAT_4200043c;
  (*DAT_420002fc)(param_1 + 2,PTR_DAT_42000434,(param_2 - 1) * 8);
  (*DAT_42000454)(param_1,param_2,8,PTR_FUN_42000440);
  for (uVar3 = 0; uVar3 < param_2; uVar3 = uVar3 + 1) {
    puVar4 = param_1 + uVar3 * 2;
    uVar2 = *puVar4 & 0xfffffffc;
    *puVar4 = uVar2;
    uVar1 = puVar4[1] + 3 & 0xfffffffc;
    puVar4[1] = uVar1;
    if ((int)uVar1 < (int)uVar2) {
      uVar1 = in_t0;
      uVar3 = (*(code *)PTR_FUN_42000044)
                        (PTR_s_memory_layout_utils_c_3c0313f4_0x1b_4200044c,0x66,
                         PTR_s_s_prepare_reserved_regions_42000448,
                         PTR_s_reserved_i__start_<__reserved[i]_42000444);
      uVar2 = uVar1;
      in_t0 = uVar1;
    }
    if (uVar3 < param_2 - 1) {
      uVar5 = CONCAT44(param_1[(uVar3 + 1) * 2],uVar3);
      if ((int)param_1[(uVar3 + 1) * 2] <= (int)uVar2) {
        uVar1 = in_t0;
        uVar5 = (*(code *)PTR_FUN_42000044)
                          (PTR_s_memory_layout_utils_c_3c0313f4_0x1b_4200044c,0x68,
                           PTR_s_s_prepare_reserved_regions_42000448,
                           PTR_s_reserved_i___1__start_>_reserved_42000450);
        in_t0 = uVar1;
      }
      uVar3 = (uint)uVar5;
      if ((int)((ulonglong)uVar5 >> 0x20) < (int)uVar1) {
        uVar3 = (*(code *)PTR_FUN_4200006c)();
      }
    }
  }
  return;
}