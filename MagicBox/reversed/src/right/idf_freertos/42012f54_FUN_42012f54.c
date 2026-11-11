undefined4 FUN_42012f54(void)

{
  undefined4 uVar1;
  int iVar2;
  char local_30 [48];
  
  if (*DAT_42000f78 == 0) {
    uVar1 = 0x103;
  }
  else {
    uVar1 = (*(code *)PTR_FUN_42000344)();
    (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000f7c,0xffffffff);
    iVar2 = FUN_42012c40(uVar1,local_30);
    if (iVar2 == 0) {
      uVar1 = 0x105;
    }
    else {
      *(undefined1 *)(iVar2 + 0xc) = 1;
      if (local_30[0] == '\0') {
        uVar1 = 0;
      }
      else {
        FUN_42012c78();
        uVar1 = 0;
      }
    }
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000f7c);
  }
  return uVar1;
}