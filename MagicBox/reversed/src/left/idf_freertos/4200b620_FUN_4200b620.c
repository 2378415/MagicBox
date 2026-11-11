void FUN_4200b620(uint param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((param_1 < 3) && (iVar1 = *(int *)(param_1 * 4 + DAT_42000a40), iVar1 != 0)) {
    *(undefined4 *)(iVar1 + 0x58) = param_2;
  }
  return;
}