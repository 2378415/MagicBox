bool FUN_42013bfc(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_42024d40(*(undefined4 *)(param_2 + 8));
  iVar2 = (*DAT_4200099c)(uVar1,*param_1,0x10);
  return iVar2 == 0;
}