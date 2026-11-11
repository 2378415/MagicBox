undefined4 FUN_420130b8(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  char cVar5;
  
  if (param_1 == (int *)0x0 || param_3 == (undefined4 *)0x0) {
    uVar3 = 0x103;
  }
  else {
    FUN_42003938(0x34,0,param_2,0,DAT_42000fe0);
    for (cVar5 = '\x01'; uVar3 = DAT_42000fe8, cVar5 != '\0'; cVar5 = cVar5 + -1) {
      iVar4 = FUN_420257f8(10);
      uVar2 = DAT_42000804;
      iVar1 = DAT_4200015c;
      if (iVar4 == 0) {
        memw();
        memw();
        *(uint *)(DAT_4200015c + 0x18) = *(uint *)(DAT_4200015c + 0x18) | DAT_42000804;
        memw();
        memw();
        *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | uVar2;
        memw();
        memw();
        *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & DAT_4200088c;
        memw();
        memw();
        *(uint *)(DAT_42000fe4 + 0x48) = *(uint *)(DAT_42000fe4 + 0x48) & DAT_4200016c;
      }
      FUN_4202580c(10,iVar4);
    }
    (*DAT_4200017c)(DAT_42000fe8,1,DAT_42000170);
    (*DAT_42000050)(uVar3);
    (*DAT_420000d8)(uVar3,0,*param_1 * 2,1);
    (*DAT_420000d8)(uVar3,1,*param_1 << 2,3);
    (*DAT_42000058)(uVar3);
    *param_3 = uVar3;
    uVar3 = 0;
  }
  return uVar3;
}