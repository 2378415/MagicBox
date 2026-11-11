undefined4 FUN_42006930(uint param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 < 3) {
    if (param_2 == 0) {
      iVar3 = FUN_420090ec();
      uVar2 = 0;
      if (iVar3 != 0) {
        puVar1 = (undefined4 *)FUN_420180e4();
        *puVar1 = 0x16;
        uVar2 = 0xffffffff;
      }
    }
    else {
      puVar1 = (undefined4 *)FUN_420180e4(param_1);
      *puVar1 = 0x16;
      uVar2 = 0xffffffff;
    }
  }
  else {
    puVar1 = (undefined4 *)FUN_420180e4(param_1);
    *puVar1 = 9;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}