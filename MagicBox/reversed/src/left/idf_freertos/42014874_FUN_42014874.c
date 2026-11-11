void FUN_42014874(uint param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_3 != 0) {
    iVar1 = DAT_4200135c + (param_1 & 0xff) * DAT_42001360;
    iVar2 = *(int *)(iVar1 + 0xc) - param_3;
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + param_3;
    *(int *)(iVar1 + 0xc) = iVar2;
    if (iVar2 == 0) {
      FUN_42016af0(*(undefined4 *)(iVar1 + DAT_4200137c),2);
    }
    else {
      FUN_42016068(param_1 & 0xff,0);
    }
  }
  return;
}