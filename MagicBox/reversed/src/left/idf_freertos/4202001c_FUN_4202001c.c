void FUN_4202001c(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  FUN_4201fffc();
  if (*DAT_42001c6c == 0) {
    FUN_4201ffd0();
  }
  puVar2 = (undefined4 *)PTR_DAT_420008ac;
  do {
    puVar1 = (undefined4 *)puVar2[2];
    iVar3 = puVar2[1];
    while (iVar3 = iVar3 + -1, -1 < iVar3) {
      if (*(short *)(puVar1 + 3) == 0) {
        puVar1[3] = DAT_42001c74;
        puVar1[0x19] = 0;
        (*(code *)PTR_FUN_42001c64)(puVar1 + 0x16);
        FUN_4202000c();
        *puVar1 = 0;
        puVar1[2] = 0;
        puVar1[1] = 0;
        puVar1[4] = 0;
        puVar1[5] = 0;
        puVar1[6] = 0;
        (*DAT_42000094)(puVar1 + 0x17,0,8);
        puVar1[0xd] = 0;
        puVar1[0xe] = 0;
        puVar1[0x12] = 0;
        puVar1[0x13] = 0;
        return;
      }
      puVar1 = puVar1 + 0x1a;
    }
    puVar1 = (undefined4 *)*puVar2;
    if ((undefined4 *)*puVar2 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)(*(code *)PTR_FUN_42001c78)(param_1,0x1ac);
      if (puVar1 == (undefined4 *)0x0) {
        *puVar2 = 0;
        FUN_4202000c();
        *param_1 = 0xc;
        return;
      }
      *puVar1 = 0;
      puVar1[1] = 4;
      puVar1[2] = puVar1 + 3;
      (*DAT_42000094)(puVar1 + 3,0,0x1a0);
      *puVar2 = puVar1;
    }
    puVar2 = puVar1;
  } while( true );
}