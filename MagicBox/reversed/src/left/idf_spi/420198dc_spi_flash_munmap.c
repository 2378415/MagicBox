// strings: spi_flash_munmap | 0 && 'invalid handle, or handle already unmapped

void FUN_420198dc(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (0 < param_1[1]) {
    iVar2 = 0;
    do {
      iVar1 = FUN_42019660(*(undefined4 *)(iVar2 * 4 + *param_1));
      if (iVar1 == 0x105) {
        (*(code *)PTR_FUN_420000a8)
                  (PTR_s_flash_mmap_c_3c03a408_0x1b_420017d8,0xf4,PTR_s_spi_flash_munmap_420017d4,
                   PTR_s_0_____invalid_handle__or_handle_a_420017d0);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[1]);
  }
  (*(code *)PTR_FUN_42000570)(*param_1);
  (*(code *)PTR_FUN_42000570)(param_1);
  return;
}