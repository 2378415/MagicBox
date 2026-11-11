int FUN_4201c520(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_30 [12];
  
  *param_2 = 0;
  iVar1 = DAT_42001a44;
  if ((*(char *)(param_1 + 0x12) != '\0') &&
     (iVar1 = FUN_4201c48c(*(undefined4 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0x10),local_30),
     iVar1 == 0)) {
    *param_2 = local_30[0];
  }
  return iVar1;
}