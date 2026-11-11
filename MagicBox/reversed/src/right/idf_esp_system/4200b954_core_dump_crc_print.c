// strings: checksum != ((void *)0) | '%08lx' | core_dump_crc_print

void FUN_4200b954(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_core_dump_crc_c_3c033334_0x21_42000a58,0x19,PTR_s_core_dump_crc_print_42000a54,
               PTR_s_checksum______void___0__42000a50);
  }
  if (param_1 != 0) {
    (*DAT_42000634)(PTR_DAT_42000a5c,param_1);
  }
  (*DAT_42000634)(PTR_s___08lx__42000a60,*param_2);
  return;
}