// 420128fc  FUN_420128fc  FUN_420128fc  size=370

void FUN_420128fc(void)

{
  char cVar1;
  uint uVar2;
  undefined4 *puVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  uint local_30;
  int iStack_2c;
  
  pcVar5 = DAT_420010f0;
  pcVar4 = DAT_420010e8;
  puVar3 = DAT_420010e4;
  uVar2 = DAT_420002d0;
  do {
    do {
      iVar6 = (*(code *)PTR_FUN_420010f8)(*puVar3,&local_30,0xffffffff);
    } while (iVar6 == 0);
    memw();
    memw();
    cVar1 = *pcVar4;
    memw();
    uVar7 = 0;
    if (local_30 != 0) {
      do {
        if (cVar1 == '\0') {
          if (*pcVar5 != '\0') {
            (*(code *)PTR_FUN_420004dc)(PTR_DAT_420010f4,0xffffffff);
            FUN_42017f70(9,1);
            memw();
            memw();
            *pcVar4 = '\x01';
            memw();
            (*(code *)PTR_FUN_420004e0)(PTR_DAT_420010f4);
          }
          (*(code *)PTR_FUN_42000098)
                    ((uint)((ulonglong)(uint)(iStack_2c * 1000) * (ulonglong)uVar2 >> 0x26));
          if (*pcVar5 != '\0') {
            (*(code *)PTR_FUN_420004dc)(PTR_DAT_420010f4,0xffffffff);
            FUN_42017f70(9,0);
            memw();
            memw();
            *pcVar4 = '\0';
            memw();
            (*(code *)PTR_FUN_420004e0)(PTR_DAT_420010f4);
          }
        }
        else {
          if (*pcVar5 != '\0') {
            (*(code *)PTR_FUN_420004dc)(PTR_DAT_420010f4,0xffffffff);
            FUN_42017f70(9,0);
            memw();
            memw();
            *pcVar4 = '\0';
            memw();
            (*(code *)PTR_FUN_420004e0)(PTR_DAT_420010f4);
          }
          (*(code *)PTR_FUN_42000098)
                    ((uint)((ulonglong)(uint)(iStack_2c * 1000) * (ulonglong)uVar2 >> 0x26));
          if (*pcVar5 != '\0') {
            (*(code *)PTR_FUN_420004dc)(PTR_DAT_420010f4,0xffffffff);
            FUN_42017f70(9,1);
            memw();
            memw();
            *pcVar4 = '\x01';
            memw();
            (*(code *)PTR_FUN_420004e0)(PTR_DAT_420010f4);
          }
        }
        uVar7 = uVar7 + 1;
        (*(code *)PTR_FUN_42000098)
                  ((uint)((ulonglong)(uint)(iStack_2c * 1000) * (ulonglong)uVar2 >> 0x26));
      } while (uVar7 < local_30);
    }
    memw();
    memw();
    *DAT_420010ec = 0;
    memw();
  } while( true );
}


