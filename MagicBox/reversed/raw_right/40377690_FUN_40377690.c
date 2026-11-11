// 40377690  FUN_40377690  FUN_40377690  size=42

uint FUN_40377690(void)

{
  uint uVar1;
  
  uVar1 = FUN_40377670(0x9f,0,0,0x18);
  return (uVar1 & 0xff) << 0x10 | uVar1 >> 0x10 & 0xff | (uVar1 >> 8 & 0xff) << 8;
}


