void FUN_4200f8e0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_4200e4b8(0,1);
  iVar2 = FUN_4200df94(uVar1,param_1,0);
  *(undefined2 *)(param_2 + 2) = 1;
  if (iVar2 < 1) {
    *(undefined1 *)(param_2 + 4) = 0xff;
  }
  return;
}