// strings: 0 && 'invalid handle, or handle already unmapped | spi_flash_munmap

void FUN_420128d0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  for (iVar2 = 0; iVar2 < param_1[1]; iVar2 = iVar2 + 1) {
    iVar1 = FUN_420126d8(*(undefined4 *)(iVar2 * 4 + *param_1));
    if (iVar1 == 0x105) {
      (*(code *)PTR_FUN_42000044)
                (PTR_s_flash_mmap_c_3c034264_0x1b_42000f08,0xf4,PTR_s_spi_flash_munmap_42000f04,
                 PTR_s_0_____invalid_handle__or_handle_a_42000f00);
    }
  }
  (*(code *)PTR_FUN_420004c0)(*param_1);
  (*(code *)PTR_FUN_420004c0)(param_1);
  return;
}