undefined4 FUN_42016768(uint *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint local_30 [12];
  
  iVar1 = FUN_42015770(param_2,local_30);
  if (iVar1 == 0) {
    if (*param_1 < local_30[0]) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}