// 42012b38  crash_dump  FUN_42012b38  size=875
// strings: crash_dump |          (((((                   | coreCOREIDLEipc0ipc1\ | COREIDLEipc0ipc1\ | IDLEipc0ipc1\ | ipc0ipc1\ | ipc1\ | COREDUMP_STRINGS_END

void FUN_42012b38(void)

{
  byte bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbStack_240;
  short sStack_23c;
  undefined1 uStack_141;
  byte local_140 [256];
  byte *apbStack_40 [4];
  byte *pbStack_30;
  byte *pbStack_2c;
  byte *pbStack_28;
  byte *pbStack_24;
  
  pbStack_30 = (byte *)FUN_42018d80(1,3,0);
  if (pbStack_30 == (byte *)0x0) {
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (2,PTR_s_crash_dump_42001124,PTR_DAT_42001128,uVar3,PTR_s_crash_dump_42001124);
  }
  else {
    apbStack_40[0] = (byte *)0x0;
    iVar4 = FUN_42018f70(pbStack_30,0,apbStack_40,4);
    if (iVar4 == 0) {
      if ((apbStack_40[0] == (byte *)0x0) || (*(byte **)((int)pbStack_30 + 0x10) < apbStack_40[0]))
      {
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (3,PTR_s_crash_dump_42001124,PTR_DAT_42001130,uVar3,PTR_s_crash_dump_42001124);
      }
      else {
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (2,PTR_s_crash_dump_42001124,PTR_DAT_42001134,uVar3,PTR_s_crash_dump_42001124,
                   apbStack_40[0]);
        FUN_4200ad84(0,PTR_s_COREDUMP_STRINGS_START_42001138,0x17);
        if (apbStack_40[0] != (byte *)0x0) {
          pbVar11 = local_140;
          uVar7 = 0;
          pbVar12 = (byte *)0x0;
          do {
            uVar9 = (int)apbStack_40[0] - (int)pbVar12;
            pbStack_24 = (byte *)((uVar9 < 0x100) * uVar9 + (uint)(uVar9 >= 0x100) * 0x100);
            pbStack_2c = pbVar12;
            pbStack_28 = pbVar11;
            iVar4 = FUN_42018f70(pbStack_30,pbVar12,pbVar11);
            puVar2 = PTR_DAT_42001140;
            if (iVar4 != 0) {
              pbStack_30 = pbStack_2c;
              uVar3 = (*(code *)PTR_FUN_4200005c)();
              uVar5 = FUN_42004180(iVar4);
              (*(code *)PTR_FUN_42000118)
                        (1,PTR_s_crash_dump_42001124,PTR_DAT_4200113c,uVar3,
                         PTR_s_crash_dump_42001124,pbStack_30,uVar5);
              return;
            }
            pbVar6 = pbStack_28 + (int)pbStack_24;
            pbVar8 = pbStack_28;
            pbVar10 = pbStack_24;
            pbVar11 = pbStack_28;
            pbVar12 = pbStack_2c;
            do {
              bVar1 = *pbVar8;
              if (((puVar2[bVar1] & 0x97) == 0) || (bVar1 == 0x3f)) {
                if (3 < uVar7) {
                  *(undefined1 *)((int)&pbStack_240 + uVar7) = 0;
                  if (((((((pbStack_240 != DAT_42001144) || ((char)sStack_23c != '\0')) &&
                         ((pbStack_240 != DAT_42001148 || ((char)sStack_23c != '\0')))) &&
                        ((pbStack_240 != DAT_4200114c || ((char)sStack_23c != '\0')))) &&
                       ((pbStack_2c = pbStack_240, pbStack_240 != DAT_4200114c ||
                        ((sStack_23c != 0x30 &&
                         ((pbStack_240 != DAT_4200114c || (sStack_23c != 0x31)))))))) &&
                      ((pbStack_240 != DAT_42001150 || ((char)sStack_23c != '\0')))) &&
                     ((pbStack_240 != DAT_42001154 || ((char)sStack_23c != '\0')))) {
                    pbStack_2c = pbVar12;
                    pbStack_28 = pbVar10;
                    pbStack_24 = pbVar11;
                    FUN_4200ad84(0,&pbStack_240,uVar7);
                    FUN_4200ad84(0,PTR_s__3c031018_0x44_42001158,1);
                    pbVar10 = pbStack_28;
                    pbVar11 = pbStack_24;
                    pbVar12 = pbStack_2c;
                  }
                }
LAB_42012d18:
                uVar7 = 0;
              }
              else {
                *(byte *)((int)&pbStack_240 + uVar7) = bVar1;
                uVar7 = uVar7 + 1;
                if (uVar7 == 0xff) {
                  uStack_141 = 0;
                  if ((((((pbStack_240 != DAT_42001144) || ((char)sStack_23c != '\0')) &&
                        ((pbStack_240 != DAT_42001148 || ((char)sStack_23c != '\0')))) &&
                       (((pbStack_240 != DAT_4200114c || ((char)sStack_23c != '\0')) &&
                        ((pbStack_2c = pbStack_240, pbStack_240 != DAT_4200114c ||
                         ((sStack_23c != 0x30 &&
                          ((pbStack_240 != DAT_4200114c || (sStack_23c != 0x31)))))))))) &&
                      ((pbStack_240 != DAT_42001150 || ((char)sStack_23c != '\0')))) &&
                     ((pbStack_240 != DAT_42001154 || ((char)sStack_23c != '\0')))) {
                    pbStack_2c = pbVar12;
                    pbStack_28 = pbVar10;
                    pbStack_24 = pbVar11;
                    FUN_4200ad84(0,&pbStack_240,0xff);
                    FUN_4200ad84(0,PTR_s__3c031018_0x44_42001158,1);
                    pbVar10 = pbStack_28;
                    pbVar11 = pbStack_24;
                    pbVar12 = pbStack_2c;
                  }
                  goto LAB_42012d18;
                }
              }
              pbVar8 = pbVar8 + 1;
            } while (pbVar6 != pbVar8);
            pbVar12 = pbVar12 + (int)pbVar10;
          } while (pbVar12 < apbStack_40[0]);
          if (3 < uVar7) {
            *(undefined1 *)((int)&pbStack_240 + uVar7) = 0;
            if (((((pbStack_240 != DAT_42001144) || ((char)sStack_23c != '\0')) &&
                 ((pbStack_240 != DAT_42001148 || ((char)sStack_23c != '\0')))) &&
                (((pbStack_240 != DAT_4200114c || ((char)sStack_23c != '\0')) &&
                 ((pbStack_240 != DAT_4200114c ||
                  ((sStack_23c != 0x30 && ((pbStack_240 != DAT_4200114c || (sStack_23c != 0x31))))))
                 )))) && (((pbStack_240 != DAT_42001150 || ((char)sStack_23c != '\0')) &&
                          ((pbStack_240 != DAT_42001154 || ((char)sStack_23c != '\0')))))) {
              FUN_4200ad84(0,&pbStack_240,uVar7);
              FUN_4200ad84(0,PTR_s__3c031018_0x44_42001158,1);
            }
          }
        }
        FUN_4200ad84(0,PTR_s_COREDUMP_STRINGS_END_4200115c,0x15);
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)(2,PTR_s_crash_dump_42001124,PTR_DAT_42001160,uVar3);
        iVar4 = FUN_42018ec0(pbStack_30,0,*(undefined4 *)((int)pbStack_30 + 0x10));
        if (iVar4 == 0) {
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          (*(code *)PTR_FUN_42000118)(3,PTR_s_crash_dump_42001124,PTR_DAT_42001168,uVar3);
        }
        else {
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          uVar5 = FUN_42004180(iVar4);
          (*(code *)PTR_FUN_42000118)
                    (1,PTR_s_crash_dump_42001124,PTR_DAT_42001164,uVar3,PTR_s_crash_dump_42001124,
                     uVar5);
        }
      }
    }
    else {
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      uVar5 = FUN_42004180(iVar4);
      (*(code *)PTR_FUN_42000118)
                (1,PTR_s_crash_dump_42001124,PTR_DAT_4200112c,uVar3,PTR_s_crash_dump_42001124,uVar5)
      ;
    }
  }
  return;
}


