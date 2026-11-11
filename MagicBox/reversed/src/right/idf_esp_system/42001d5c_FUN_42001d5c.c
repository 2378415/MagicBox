/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_42001d5c(byte param_1)

{
  bool bVar1;
  
  while ((memw(), (DAT_42000190[1] & 2) == 0 && (*DAT_4200018c < 500))) {
    (*DAT_42000078)(100);
    *DAT_4200018c = *DAT_4200018c + 1;
  }
  memw();
  if ((DAT_42000190[1] & 2) != 0) {
    bVar1 = false;
    while ((!bVar1 && (memw(), (DAT_42000190[1] & 2) != 0))) {
      memw();
      *DAT_42000190 = (uint)param_1;
      bVar1 = true;
    }
    *DAT_4200018c = 0;
  }
  return;
}