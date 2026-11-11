void FUN_4200fa0c(int param_1,undefined4 param_2,undefined2 *param_3)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_1 + 2);
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  if ((uVar1 == (*DAT_42000d38 & 0xff)) && (*(char *)(DAT_42000d28 + 5) == '\0')) {
    FUN_42024898(param_2,*param_3,DAT_42000d40,0x40);
    *(undefined1 *)(DAT_42000d28 + 5) = 1;
  }
  else if ((uVar1 == (*DAT_42000d3c & 0xff)) && (*(char *)(DAT_42000d28 + 6) == '\0')) {
    FUN_42024898(param_2,*param_3,DAT_42000d44,0x40);
    *(undefined1 *)(DAT_42000d28 + 6) = 1;
  }
  else if ((uVar1 == (*DAT_42000d2c & 0xff) && (*DAT_42000d2c & 0xff) != 0) &&
          (*(char *)(DAT_42000d28 + 7) == '\0')) {
    FUN_42024898(param_2,*param_3,DAT_42000d34,0x40);
    FUN_4200f9e4();
    *(undefined1 *)(DAT_42000d28 + 7) = 1;
  }
  return;
}