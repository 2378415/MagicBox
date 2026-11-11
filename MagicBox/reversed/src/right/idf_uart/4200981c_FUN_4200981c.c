undefined4 FUN_4200981c(undefined4 param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_2 == 3) {
    if (PTR_DAT_42000920[0xc] == '\0') {
      uVar1 = 2;
    }
    else {
      uVar1 = DAT_420007f0;
    }
  }
  else if (param_2 == 4) {
    PTR_DAT_42000920[0xc] = (byte)(param_3 >> 0xe) & 1;
    uVar1 = 0;
  }
  else {
    puVar2 = (undefined4 *)FUN_420180e4();
    *puVar2 = 0x58;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}