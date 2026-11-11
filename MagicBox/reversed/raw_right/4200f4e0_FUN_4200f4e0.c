// 4200f4e0  FUN_4200f4e0  FUN_4200f4e0  size=50

undefined4 FUN_4200f4e0(undefined2 param_1,undefined2 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_4200f3ac(param_1,param_2);
  if (iVar1 == -1) {
    uVar2 = 0x105;
  }
  else {
    (*DAT_420002fc)(param_3,iVar1 * 0x46 + DAT_42000cec,0x46);
    uVar2 = 0;
  }
  return uVar2;
}


