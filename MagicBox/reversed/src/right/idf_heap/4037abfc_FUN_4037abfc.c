int FUN_4037abfc(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 != 2) {
    param_1 = param_1 + 3 & 0xfffffffc;
  }
  iVar1 = FUN_40376004(0x70,param_3);
  iVar2 = FUN_40376004(param_1,param_3);
  if ((iVar1 == 0 || iVar2 == 0) || (iVar3 = FUN_4037a788(param_1,param_2,iVar2,iVar1), iVar3 == 0))
  {
    FUN_40376244(iVar1);
    FUN_40376244(iVar2);
    iVar3 = 0;
  }
  return iVar3;
}