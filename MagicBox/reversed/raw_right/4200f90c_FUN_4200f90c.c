// 4200f90c  FUN_4200f90c  FUN_4200f90c  size=47

void FUN_4200f90c(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_4200e4b8(0,1);
  uVar2 = FUN_4200df94(uVar1,param_1,param_2 + 0xc);
  *(ushort *)(param_3 + 2) = (ushort)(*(ushort *)(param_2 + 2) != uVar2);
  if (*(ushort *)(param_2 + 2) != uVar2) {
    *(undefined1 *)(param_3 + 4) = 0xff;
  }
  return;
}


