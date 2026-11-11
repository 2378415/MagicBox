void FUN_420145cc(void)

{
  int *piVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_4200133c;
  piVar1 = DAT_42001330;
  if (0 < *DAT_42001330) {
    *DAT_4200133c = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 4;
  }
  *piVar1 = 0;
  return;
}