int FUN_40377be0(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int local_30 [12];
  
  uVar3 = param_1 & DAT_4037486c;
  uVar4 = (param_1 - uVar3) + param_2 + DAT_40374460 & DAT_4037486c;
  iVar1 = 0;
  uVar5 = uVar3;
  while( true ) {
    if (uVar3 + uVar4 <= uVar5) {
      return iVar1;
    }
    if (*(uint *)(*DAT_403747dc + 4) <= uVar5) break;
    local_30[0] = 0;
    iVar2 = FUN_40377b94(uVar5,local_30);
    if ((iVar2 != 0) && (local_30[0] != 0)) {
      FUN_4037ecdc(local_30[0],DAT_40374870);
      iVar1 = iVar2;
    }
    uVar5 = uVar5 + DAT_40374870;
  }
  return 0;
}