void FUN_4037c514(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = FUN_4037d1c4();
  if (uVar1 < *DAT_40374dc8) {
    FUN_4037c4e0();
    *param_1 = 1;
  }
  else {
    *param_1 = 0;
  }
  *DAT_40374dc8 = uVar1;
  return;
}