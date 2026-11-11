// 4200ac78  FUN_4200ac78  FUN_4200ac78  size=33
// strings: hi7@hi

undefined4 FUN_4200ac78(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_FUN_42000300)();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if (*DAT_420009d4 == '\0') {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


