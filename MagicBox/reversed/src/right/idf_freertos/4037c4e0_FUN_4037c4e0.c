void FUN_4037c4e0(void)

{
  int *piVar1;
  int *piVar2;
  
  while( true ) {
    piVar1 = DAT_40374dc4;
    piVar2 = (int *)*DAT_40374dc0;
    memw();
    if (*piVar2 == 0) break;
    memw();
    memw();
    FUN_4037c4a4(*(undefined4 *)piVar2[3],0xffffffff);
  }
  *DAT_40374dc0 = *DAT_40374dc4;
  *piVar1 = (int)piVar2;
  return;
}