// 4200854c  FUN_4200854c  FUN_4200854c  size=44

undefined4 FUN_4200854c(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_1 < 3) {
    iVar2 = FUN_4200abe0(param_1,0xffffffff);
    if (iVar2 == 0) {
      return 0;
    }
    puVar1 = (undefined4 *)FUN_42020b54();
    *puVar1 = 0x16;
  }
  else {
    puVar1 = (undefined4 *)FUN_42020b54();
    *puVar1 = 9;
  }
  return 0xffffffff;
}


