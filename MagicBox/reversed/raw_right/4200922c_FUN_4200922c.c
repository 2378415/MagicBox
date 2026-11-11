// 4200922c  FUN_4200922c  FUN_4200922c  size=101

undefined4 FUN_4200922c(uint param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int local_30 [12];
  
  if (param_1 < 3) {
    iVar3 = *(int *)(param_1 * 4 + DAT_42000844);
    if (iVar3 == 0) {
      uVar1 = 0;
    }
    else {
      FUN_42003a40(*(undefined4 *)(iVar3 + 8));
      FUN_4200863c(param_1);
      FUN_42008650(param_1);
      FUN_42007664(param_1);
      puVar2 = (undefined4 *)(param_1 * 4 + DAT_42000844);
      FUN_4200817c(*puVar2);
      *puVar2 = 0;
      local_30[0] = 0;
      FUN_42024a10(PTR_DAT_42000848 + param_1 * 0x18 + 8,local_30);
      if (local_30[0] == 9) {
        FUN_4201395c();
      }
      FUN_4200778c(param_1);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


