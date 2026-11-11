// 42003ac4  FUN_42003ac4  FUN_42003ac4  size=90

int FUN_42003ac4(void)

{
  int iVar1;
  undefined4 uVar2;
  
  (*(code *)PTR_FUN_420003a8)(PTR_DAT_420004e4,0xffffffff);
  if (*DAT_420004e8 == 0) {
    memw();
    *DAT_420004ec = 0;
    memw();
    *DAT_420004f0 = 0xffffffff;
    iVar1 = FUN_42003938(0x27,0x400,PTR_FUN_420004f4,0,DAT_420004e8);
    if (iVar1 == 0) {
      uVar2 = FUN_42024594(*DAT_420004e8);
      *(undefined4 *)PTR_DAT_420004f8 = uVar2;
    }
  }
  else {
    iVar1 = 0;
  }
  (*(code *)PTR_FUN_420003ac)(PTR_DAT_420004e4);
  return iVar1;
}


