undefined4 FUN_4037b048(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 != 2) {
    param_1 = param_1 + 3 & 0xfffffffc;
  }
  iVar1 = FUN_40376314(0x70,param_3);
  iVar2 = FUN_40376314(param_1,param_3);
  if ((iVar1 == 0) || (iVar2 == 0 || iVar1 == 0)) {
    FUN_4037645c(iVar1);
    FUN_4037645c(iVar2);
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_4037ac84(param_1,param_2,iVar2,iVar1);
  }
  return uVar3;
}