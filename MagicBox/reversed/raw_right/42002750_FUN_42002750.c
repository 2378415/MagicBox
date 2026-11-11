// 42002750  FUN_42002750  FUN_42002750  size=97
// strings: Unknown reason

void FUN_42002750(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x50);
  if (iVar2 == 5) {
    *param_2 = 0;
    param_2[1] = 1;
  }
  else if (iVar2 == 6) {
    *param_2 = 1;
    param_2[1] = 1;
  }
  else if (iVar2 == 7) {
    uVar1 = FUN_42001c04();
    *param_2 = uVar1;
  }
  param_2[2] = PTR_s_Unknown_reason_42000314;
  param_2[3] = 0;
  if (*(int *)(param_1 + 0x50) < 8) {
    param_2[2] = *(undefined4 *)(PTR_PTR_42000318 + *(int *)(param_1 + 0x50) * 4);
  }
  if (*(int *)(param_1 + 0x50) == 1) {
    param_2[4] = PTR_FUN_4200031c;
    param_2[1] = 0;
  }
  if (*(int *)(param_1 + 0x50) == 7) {
    param_2[4] = PTR_FUN_42000320;
  }
  return;
}


