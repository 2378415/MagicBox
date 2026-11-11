int FUN_42002190(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = DAT_42000090;
  puVar1 = PTR_FUN_4200008c;
  while( true ) {
    uVar3 = FUN_4202ce14(param_3,8);
    (*DAT_42000094)(param_2,0,uVar3);
    iVar4 = FUN_420023d0(param_1,param_2,param_3,puVar1);
    if (iVar4 != iVar2) break;
    (*(code *)PTR_FUN_42000098)(1);
  }
  return iVar4;
}