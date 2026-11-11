void FUN_4200f854(int param_1)

{
  uint uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
  memw();
  memw();
  if ((*(char *)(DAT_42000d28 + 4) == '\0') || ((*DAT_42000d2c & 0xff) == 0)) {
    *(undefined2 *)(param_1 + 2) = 1;
    *(undefined1 *)(param_1 + 4) = 0xff;
  }
  else {
    if ((*(char *)(DAT_42000d28 + 8) == '\0') || (*(char *)(DAT_42000d28 + 0xc9) == '\0')) {
      if ((*(char *)(DAT_42000d28 + 7) == '\0') || (*(char *)(DAT_42000d28 + 0x89) == '\0')) {
        *(undefined2 *)(param_1 + 2) = 1;
        *(undefined1 *)(param_1 + 4) = 0xff;
        return;
      }
      uVar2 = 0;
      uVar3 = DAT_42000d34;
    }
    else {
      uVar2 = 1;
      uVar3 = DAT_42000d30;
    }
    uVar1 = (*DAT_420001e4)(uVar3);
    if (0x14 < uVar1) {
      uVar1 = 0x14;
    }
    *(short *)(param_1 + 2) = (short)uVar1 + 1;
    *(undefined1 *)(param_1 + 4) = uVar2;
    (*DAT_420002fc)(param_1 + 5,uVar3);
  }
  return;
}