// 4200ae8c  FUN_4200ae8c  FUN_4200ae8c  size=71
// strings: 8|7@(

undefined4 FUN_4200ae8c(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = DAT_420009f8;
  iVar2 = (*DAT_42000a0c)(0,DAT_420009f8,0xc);
  if (piVar1[3] == iVar2) {
    if (*DAT_420009f8 == 0) {
      uVar3 = 0xffffffff;
    }
    else if ((uint)DAT_420009f8[1] < 4) {
      uVar3 = 0xffffffff;
    }
    else {
      (*(code *)PTR_FUN_42000a14)(PTR_PTR_42000a10);
      FUN_42012a24(1);
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


