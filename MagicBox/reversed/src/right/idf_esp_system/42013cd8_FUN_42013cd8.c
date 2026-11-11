undefined4 FUN_42013cd8(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_42013c34(*DAT_42001090,0,param_1);
  while (puVar1 = DAT_42001090, iVar2 != 0) {
    FUN_42024be8(DAT_42001090);
    iVar2 = FUN_42013c34(*puVar1,0,param_1);
  }
  uVar3 = FUN_4201523c();
  uVar3 = FUN_420153bc(uVar3,param_1);
  return uVar3;
}