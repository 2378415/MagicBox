void FUN_420017d8(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_1 & 3;
  iVar2 = 1;
  do {
    iVar4 = iVar2;
    if (uVar3 == 1) {
      if (param_1 == 1) {
        (*(code *)PTR_FUN_42000088)(1);
      }
      else if (param_1 == 9) {
        (*(code *)PTR_FUN_4200008c)();
      }
      iVar1 = (*(code *)PTR_FUN_42000090)(2,0x400);
      if (iVar1 != 0) goto LAB_42001825;
      iVar4 = iVar2 + -1;
      if (iVar2 < 1) {
        uVar3 = 0;
        goto LAB_42001825;
      }
      iVar1 = 0;
    }
    else {
      if (uVar3 == 2) {
        (*(code *)PTR_FUN_42000094)(1);
      }
LAB_42001825:
      (*(code *)PTR_FUN_42000098)(uVar3);
      iVar1 = (*(code *)PTR_FUN_42000090)(0,0x400);
    }
    iVar2 = iVar4;
    if (iVar1 != 0) {
      FUN_420032d0();
      return;
    }
  } while( true );
}