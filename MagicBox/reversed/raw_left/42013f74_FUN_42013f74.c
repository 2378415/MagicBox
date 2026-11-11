// 42013f74  FUN_42013f74  FUN_42013f74  size=234

undefined4 FUN_42013f74(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  char local_2a0 [604];
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 uStack_3c;
  undefined4 uStack_30;
  
  uVar2 = FUN_4202d60c(PTR_DAT_4200129c);
  if (2 < uVar2) {
    iVar3 = (uVar2 < 0x25a) * uVar2 + (uint)(uVar2 >= 0x25a) * 0x25a + -2;
    FUN_42013408(PTR_DAT_4200129c,2,local_2a0,iVar3);
    uStack_44 = DAT_420012a4;
    puVar1 = DAT_420012a0;
    if (((local_2a0[0] != '\r' && local_2a0[0] != '\n') &&
        (local_2a0[0] != ';' && (local_2a0[0] != '\r' && local_2a0[0] != '\n'))) || (uVar2 != 2)) {
      uVar2 = *DAT_420012a0;
      if ((uVar2 & 1) == 0) {
        *DAT_420012a0 = uVar2 | 1;
        uStack_30 = 0;
        (*DAT_42000064)(uStack_44,local_2a0,0,iVar3);
        uStack_3c = 0;
        uStack_40 = uStack_30;
        iVar3 = (*(code *)PTR_FUN_42000488)(*DAT_420012a8,&uStack_44,0xffffffff,uVar2 & 1);
        if (iVar3 != 1) {
          uVar2 = *puVar1;
          *puVar1 = uVar2 & 1 ^ uVar2;
        }
      }
      return 3;
    }
  }
  return 0;
}


