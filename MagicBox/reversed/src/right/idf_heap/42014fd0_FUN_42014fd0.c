undefined4 FUN_42014fd0(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x12) == '\0') {
    uVar1 = DAT_4200108c;
  }
  else {
    uVar1 = FUN_42014544(*(undefined4 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0x10),param_2,
                         param_3,param_4);
  }
  return uVar1;
}