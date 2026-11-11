void FUN_42012dcc(uint param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  uVar2 = rsr(in_PRID);
  uVar2 = uVar2 >> 0xd & 1;
  if (param_2 == 0) {
    if ((param_1 & 1 << (sbyte)uVar2) != 0) {
      (*(code *)PTR_FUN_42000f90)(100);
    }
    if ((param_1 & 1 << (uVar2 == 0)) != 0) {
      (*(code *)PTR_FUN_42000f98)();
    }
  }
  else {
    bVar1 = uVar2 == 0;
    if ((~param_1 & 3) == 0) {
      (*(code *)PTR_FUN_42000f90)(100);
      (*(code *)PTR_FUN_42000f94)(bVar1);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    if ((param_1 & 1 << bVar1) != 0) {
      (*(code *)PTR_FUN_42000f94)(bVar1);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    FUN_42012d78(1);
  }
  return;
}