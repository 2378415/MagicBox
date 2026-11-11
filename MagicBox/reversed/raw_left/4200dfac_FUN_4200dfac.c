// 4200dfac  FUN_4200dfac  FUN_4200dfac  size=66

void FUN_4200dfac(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char acStack_40 [64];
  
  if (param_3 != 0) {
    iVar2 = param_4[1];
    uVar3 = *param_4;
    cVar1 = FUN_4202d26c(param_3,param_4[3]);
    if (iVar2 + 2U < 0x21) {
      (*DAT_42000064)(acStack_40,uVar3,iVar2);
      acStack_40[iVar2 + 1] = cVar1 + '0';
      acStack_40[iVar2] = '\n';
      FUN_420143e8(acStack_40,iVar2 + 2U,0);
    }
  }
  return;
}


