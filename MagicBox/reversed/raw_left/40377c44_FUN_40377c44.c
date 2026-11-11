// 40377c44  FUN_40377c44  FUN_40377c44  size=53

uint FUN_40377c44(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = FUN_403779d0(0x9f,0,0,0,0,0,0x18);
  uVar1 = (undefined4)(CONCAT44((uVar2 & 0xffffff) >> 0x10,uVar2) >> 8);
  uVar1 = (undefined4)(CONCAT44(uVar2,(int)(CONCAT44(uVar1,uVar1) >> 8)) >> 8);
  return (uint)(CONCAT44(uVar1,uVar1) >> 8) & 0xffffff;
}


