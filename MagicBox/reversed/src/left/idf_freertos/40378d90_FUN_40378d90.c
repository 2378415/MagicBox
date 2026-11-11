void FUN_40378d90(uint *param_1)

{
  undefined *puVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  uVar2 = rsr(in_PRID);
  if ((uVar2 >> 0xd & 1) == 0) {
    memw();
    *DAT_40374988 = 0;
  }
  else {
    memw();
    *DAT_4037498c = 0;
  }
  FUN_4037bf44(PTR_DAT_40374990,0xffffffff);
  puVar1 = PTR_DAT_40374990;
  memw();
  uVar2 = *param_1;
  memw();
  *param_1 = 0;
  FUN_4037c094(puVar1);
  if ((uVar2 & 1) != 0) {
    FUN_4037c210();
  }
  if ((uVar2 & 4) != 0) {
    FUN_403760e0(100);
  }
  if ((uVar2 & 0x10) != 0) {
    (*(code *)PTR_FUN_40374994)(0);
  }
  return;
}