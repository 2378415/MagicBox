// 403767c4  FUN_403767c4  FUN_403767c4  size=76

void FUN_403767c4(void)

{
  uint uVar1;
  uint *puVar2;
  
  memw();
  uVar1 = *DAT_403746ec;
  FUN_4037bbe8(PTR_DAT_403746f0,0xffffffff);
  for (puVar2 = *(uint **)PTR_DAT_403746f4; puVar2 != (uint *)0x0; puVar2 = (uint *)puVar2[4]) {
    if ((*puVar2 & uVar1) != 0) {
      FUN_4037bd38(PTR_DAT_403746f0);
      (*(code *)puVar2[1])(puVar2[2]);
      FUN_4037bbe8(PTR_DAT_403746f0,0xffffffff);
    }
  }
  FUN_4037bd38(PTR_DAT_403746f0);
  memw();
  *DAT_403746f8 = uVar1;
  return;
}


