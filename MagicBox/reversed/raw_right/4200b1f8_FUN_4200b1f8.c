// 4200b1f8  FUN_4200b1f8  FUN_4200b1f8  size=36

undefined4 FUN_4200b1f8(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0x4c);
    iVar1 = FUN_4200aed4(param_1 + 0x54,param_2,0x20);
    if (iVar1 == 0) {
      uVar2 = 0x20;
    }
    else {
      uVar2 = 0xfffffffe;
    }
  }
  return uVar2;
}


