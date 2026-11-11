// 4200a934  FUN_4200a934  FUN_4200a934  size=27

undefined4 FUN_4200a934(uint param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 < 0x10) {
    uVar2 = 0;
  }
  else {
    puVar1 = (undefined4 *)FUN_420180e4();
    *puVar1 = 9;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


