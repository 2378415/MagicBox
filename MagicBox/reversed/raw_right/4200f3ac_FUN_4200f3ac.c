// 4200f3ac  FUN_4200f3ac  FUN_4200f3ac  size=61

uint FUN_4200f3ac(short param_1,short param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (*DAT_42000ce8 <= uVar1) {
      return 0xffffffff;
    }
    if ((*(short *)(uVar1 * 0x46 + DAT_42000cec) == param_1) &&
       (*(short *)(uVar1 * 0x46 + DAT_42000cec + 2) == param_2)) break;
    uVar1 = uVar1 + 1;
  }
  return uVar1;
}


