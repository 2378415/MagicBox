undefined4 FUN_42006970(uint param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 < 3) {
    iVar3 = FUN_42008df4(param_1,0xffffffff);
    uVar2 = 0;
    if (iVar3 != 0) {
      puVar1 = (undefined4 *)FUN_420180e4();
      *puVar1 = 0x16;
      uVar2 = 0xffffffff;
    }
  }
  else {
    puVar1 = (undefined4 *)FUN_420180e4();
    *puVar1 = 9;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}