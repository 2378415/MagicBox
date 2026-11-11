// 4037cd24  FUN_4037cd24  FUN_4037cd24  size=148

void FUN_4037cd24(void)

{
  int iVar1;
  int iVar2;
  
  do {
    memw();
    if (*DAT_40374e60 == 0) {
      return;
    }
    FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
    memw();
    if (*DAT_40374e58 == 0) {
      iVar1 = 0;
    }
    else {
      memw();
      for (iVar2 = DAT_40374e58[3]; iVar2 != DAT_40374e64; iVar2 = *(int *)(iVar2 + 4)) {
        iVar1 = *(int *)(iVar2 + 0xc);
        memw();
        if ((iVar1 != *DAT_40374d64) && (memw(), iVar1 != DAT_40374d64[1])) {
          FUN_4037c980(iVar1 + 4);
          memw();
          memw();
          *DAT_40374e5c = *DAT_40374e5c + -1;
          memw();
          memw();
          *DAT_40374e60 = *DAT_40374e60 + -1;
          goto LAB_4037cda0;
        }
        memw();
      }
      iVar1 = 0;
    }
LAB_4037cda0:
    FUN_4037bd38(PTR_DAT_40374e54);
    if (iVar1 == 0) {
      return;
    }
    FUN_4037ccdc(iVar1);
  } while( true );
}


