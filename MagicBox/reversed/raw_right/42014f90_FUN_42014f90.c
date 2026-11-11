// 42014f90  FUN_42014f90  FUN_42014f90  size=60

undefined4 FUN_42014f90(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(char *)(param_1 + 0x12) == '\0') {
    uVar3 = DAT_4200108c;
  }
  else if (*(char *)(param_1 + 0x11) == '\0') {
    uVar3 = *(undefined4 *)(param_1 + 0xc);
    uVar1 = *(undefined1 *)(param_1 + 0x10);
    iVar2 = (*DAT_420001e4)(param_3);
    uVar3 = FUN_42014b48(uVar3,uVar1,0x21,param_2,param_3,iVar2 + 1);
  }
  else {
    uVar3 = DAT_420010c0;
  }
  return uVar3;
}


