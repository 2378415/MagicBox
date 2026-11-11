char FUN_4200f804(int param_1,int param_2)

{
  char cVar1;
  
  if (*(ushort *)(param_1 + 2) < 0x15) {
    cVar1 = *(char *)(DAT_42000d28 + 4);
    if (cVar1 == '\0') {
      *(undefined2 *)(param_2 + 2) = 1;
      *(undefined1 *)(param_2 + 4) = 0xff;
    }
    else {
      memw();
      memw();
      if ((*DAT_42000d2c & 0xff) == 0) {
        *(undefined2 *)(param_2 + 2) = 1;
        *(undefined1 *)(param_2 + 4) = 0xff;
        cVar1 = '\0';
      }
    }
  }
  else {
    *(undefined2 *)(param_2 + 2) = 1;
    *(undefined1 *)(param_2 + 4) = 0xff;
    cVar1 = '\0';
  }
  return cVar1;
}