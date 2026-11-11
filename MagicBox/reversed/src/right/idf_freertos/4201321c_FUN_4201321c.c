// strings: ESP_FAIL | ERROR

undefined * FUN_4201321c(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (0xda < uVar1) {
      return PTR_s_ERROR_42000fec;
    }
    if (*(int *)(PTR_DAT_42000ff0 + uVar1 * 8) == param_1) break;
    uVar1 = uVar1 + 1;
  }
  return *(undefined **)(PTR_DAT_42000ff0 + uVar1 * 8 + 4);
}