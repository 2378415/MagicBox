// strings: %s(%d)

void FUN_420109ec(void)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  undefined1 auStack_50 [32];
  uint uStack_30;
  uint uStack_2c;
  
  piVar1 = DAT_42000dc0;
  do {
    do {
      do {
        (*(code *)PTR_FUN_42000eb8)(0,1,0xffffffff);
        memw();
        iVar6 = *piVar1;
      } while (iVar6 == 0);
    } while (*(int *)(iVar6 + 0x210) == 0);
    memw();
    memw();
    memw();
    if (*DAT_42000e04 != '\0') goto LAB_42010a28;
    memw();
    memw();
    memw();
    if (*(char *)(iVar6 + 0x52d) != '\0') goto LAB_42010a28;
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    if (*DAT_42000dfc < *DAT_42000e00) {
LAB_42010a28:
      (*(code *)PTR_FUN_420004dc)(PTR_DAT_42000e50,0xffffffff);
      memw();
      memw();
      memw();
      if (*(char *)(iVar6 + 0x52d) == '\0') {
        uVar3 = *(undefined4 *)(iVar6 + 0x31c);
        iVar5 = iVar6 + 0x219;
      }
      else {
        uVar3 = *(undefined4 *)(iVar6 + 0x630);
        memw();
        memw();
        *(char *)(iVar6 + 0x52d) = '\0';
        iVar5 = iVar6 + 0x52e;
        memw();
      }
      (*(code *)PTR_FUN_420004e0)(PTR_DAT_42000e50);
      FUN_420106bc(0,*(undefined1 *)(iVar6 + 3),iVar6,iVar5,uVar3);
      if (*DAT_42000dac != '\0') {
        piVar7 = (int *)(*(int *)(iVar6 + 0x210) + 0x58);
        iVar6 = 0;
        pbVar4 = DAT_42000eb0;
        do {
          iVar6 = iVar6 + 1;
          if (((*piVar7 != 0) && (uStack_30 = piVar7[0x45], uStack_30 == 0)) &&
             (uStack_2c = (uint)*(byte *)(piVar7 + 0x34), *pbVar4 != uStack_2c)) {
            uVar3 = FUN_4200efb0(iVar6);
            iVar5 = FUN_4202058c(auStack_50,0x20,PTR_s__s__d__42000eb4,uVar3,
                                 (uStack_2c == 0) + '\x01');
            uVar2 = uStack_30;
            uVar8 = uStack_2c;
            if (iVar5 - 1U < 0x1f) {
              uStack_30 = uStack_2c;
              uart0_reply(auStack_50,iVar5,uVar2);
              uVar8 = uStack_30;
            }
            *pbVar4 = (byte)uVar8;
          }
          piVar7 = piVar7 + 1;
          pbVar4 = pbVar4 + 1;
        } while (iVar6 != 5);
      }
      uVar3 = (*(code *)PTR_FUN_42000b70)();
      memw();
      memw();
      *DAT_42000ea8 = uVar3;
      memw();
      memw();
      memw();
      *DAT_42000eac = 1;
      memw();
    }
  } while( true );
}