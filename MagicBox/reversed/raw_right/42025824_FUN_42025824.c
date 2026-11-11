// 42025824  FUN_42025824  FUN_42025824  size=120
// strings: periph < PERIPH_MODULE_MAX | periph_module_enable

void FUN_42025824(uint param_1)

{
  int iVar1;
  
  if (0x28 < param_1) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_periph_ctrl_c_3c031754_0x20_42001370,0x3d,PTR_s_periph_module_enable_4200136c,
               PTR_s_periph_<_PERIPH_MODULE_MAX_42001368);
  }
  iVar1 = (*(code *)PTR_FUN_42000394)();
  if (iVar1 == 0) {
    (*(code *)PTR_FUN_420003a8)(PTR_DAT_42001374,0xffffffff);
  }
  else {
    (*(code *)PTR_FUN_420003a8)(PTR_DAT_42001374,0xffffffff);
  }
  if (*(char *)(DAT_42001364 + param_1) == '\0') {
    FUN_420257b8(param_1);
  }
  *(char *)(DAT_42001364 + param_1) = *(char *)(DAT_42001364 + param_1) + '\x01';
  iVar1 = (*(code *)PTR_FUN_42000394)();
  if (iVar1 == 0) {
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_42001374);
  }
  else {
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_42001374);
  }
  return;
}


