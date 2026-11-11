void FUN_40378744(uint *param_1)

{
  uint uVar1;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  if ((uVar1 >> 0xd & 1) == 0) {
    memw();
    *DAT_403748d8 = 0;
  }
  else {
    memw();
    *DAT_403748dc = 0;
  }
  FUN_4037bbe8(PTR_DAT_403748e0,0xffffffff);
  memw();
  uVar1 = *param_1;
  memw();
  *param_1 = 0;
  FUN_4037bd38(PTR_DAT_403748e0);
  if ((uVar1 & 1) != 0) {
    FUN_4037be34();
  }
  if ((uVar1 & 4) != 0) {
    FUN_40375e0c(100);
  }
  if ((uVar1 & 0x10) != 0) {
    (*(code *)PTR_FUN_403748e4)(0);
  }
  return;
}