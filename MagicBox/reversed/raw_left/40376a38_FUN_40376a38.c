// 40376a38  FUN_40376a38  FUN_40376a38  size=79

void FUN_40376a38(void)

{
  undefined *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar1 = PTR_DAT_4037472c;
  memw();
  uVar2 = *DAT_40374728;
  FUN_4037bf44(PTR_DAT_4037472c,0xffffffff);
  for (puVar3 = *(uint **)PTR_DAT_40374730; puVar3 != (uint *)0x0; puVar3 = (uint *)puVar3[4]) {
    if ((uVar2 & *puVar3) != 0) {
      FUN_4037c094(puVar1);
      (*(code *)puVar3[1])(puVar3[2]);
      FUN_4037bf44(puVar1,0xffffffff);
    }
  }
  FUN_4037c094(puVar1);
  memw();
  *DAT_40374734 = uVar2;
  return;
}


