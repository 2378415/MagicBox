// strings: ESP_FAIL | ERROR

undefined * FUN_42004180(int param_1)

{
  undefined *puVar1;
  
  if (*(int *)PTR_DAT_420004ec == param_1) {
    puVar1 = *(undefined **)(PTR_DAT_420004ec + 4);
  }
  else {
    puVar1 = PTR_s_ERROR_420004e8;
  }
  return puVar1;
}