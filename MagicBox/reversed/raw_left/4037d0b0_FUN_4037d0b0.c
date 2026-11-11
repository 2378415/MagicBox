// 4037d0b0  FUN_4037d0b0  FUN_4037d0b0  size=144

void FUN_4037d0b0(void)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar6 = DAT_40374f30;
  piVar5 = DAT_40374f2c;
  piVar4 = DAT_40374ef8;
  piVar2 = DAT_40374ee0;
  piVar1 = DAT_40374e18;
LAB_4037d135:
  do {
    memw();
    if (*piVar5 != 0) {
      FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
      memw();
      if (*piVar2 != 0) {
        memw();
        for (iVar8 = piVar2[3]; iVar8 != iVar6; iVar8 = *(int *)(iVar8 + 4)) {
          memw();
          iVar7 = *(int *)(iVar8 + 0xc);
          if ((iVar7 != *piVar1) && (memw(), iVar7 != piVar1[1])) {
            FUN_4037cc94(iVar7 + 4);
            puVar3 = PTR_DAT_40374ef4;
            memw();
            memw();
            *piVar4 = *piVar4 + -1;
            memw();
            memw();
            *piVar5 = *piVar5 + -1;
            FUN_4037c094(puVar3);
            if (iVar7 == 0) goto LAB_4037d13d;
            FUN_4037d068(iVar7);
            goto LAB_4037d135;
          }
          memw();
        }
      }
      FUN_4037c094(PTR_DAT_40374ef4);
    }
LAB_4037d13d:
    (*(code *)PTR_FUN_40374f34)();
  } while( true );
}


