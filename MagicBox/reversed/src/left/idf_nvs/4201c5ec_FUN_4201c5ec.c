undefined4 FUN_4201c5ec(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_42001a44;
  if ((*(char *)(param_1 + 0x12) != '\0') &&
     (uVar2 = DAT_42001a7c, *(char *)(param_1 + 0x11) == '\0')) {
    iVar1 = (*DAT_4200030c)(param_3);
    uVar2 = FUN_4201c0ec(*(undefined4 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0x10),0x21,param_2
                         ,param_3,iVar1 + 1);
  }
  return uVar2;
}