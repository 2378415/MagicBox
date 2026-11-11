// 4200851c  FUN_4200851c  FUN_4200851c  size=47

undefined4 FUN_4200851c(uint param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_1 < 3) {
    if ((param_2 == 0) && (iVar2 = FUN_4200af94(param_1), iVar2 == 0)) {
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


