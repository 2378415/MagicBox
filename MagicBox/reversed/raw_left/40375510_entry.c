// 40375510  entry  entry  size=883
// strings: cpu_start

/* WARNING: Control flow encountered bad instruction data */

void entry(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  undefined *puVar4;
  undefined *puVar5;
  uint *puVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  char *pcVar15;
  int iVar16;
  undefined1 in_VECBASE;
  undefined1 in_PRID;
  undefined8 uVar17;
  char local_70 [24];
  undefined1 auStack_58 [24];
  undefined1 auStack_40 [10];
  byte bStack_36;
  uint uStack_34;
  char acStack_30 [48];
  
  pcVar15 = local_70;
  wsr(in_VECBASE,PTR_LAB_40374404);
  iVar7 = (*DAT_403744c0)(0);
  (*DAT_403744c0)(1);
  (*DAT_403744c4)(DAT_40374454,0,DAT_40374450 - DAT_40374454);
  if (iVar7 != 5) {
    (*DAT_403744c4)(DAT_4037445c,0,DAT_40374458 - DAT_4037445c);
  }
  FUN_403754ac();
  FUN_4037edd8();
  (*DAT_403744c8)(DAT_40374460,8,0x20);
  FUN_4037b1cc();
  (*DAT_403744cc)(DAT_40374464,8,0x20);
  (*DAT_403744d0)(0);
  uVar12 = DAT_403744b4 - (int)PTR_PTR_40374468;
  iVar16 = (uVar12 >> 0x10) * 4;
  uVar11 = DAT_403744b8 - (int)PTR_DAT_40374470;
  (*DAT_403744d4)(iVar16,-(iVar16 + -0x400));
  FUN_40378188();
  (*(code *)PTR_FUN_403744d8)();
  (*(code *)PTR_FUN_403744dc)();
  FUN_403781a0();
  FUN_40379260();
  (*(code *)PTR_FUN_403744e0)();
  (*(code *)PTR_FUN_403744e4)();
  puVar4 = PTR_DAT_40374414;
  if (2 < *(uint *)PTR_DAT_40374414) {
    uVar8 = FUN_40381bb0();
    (*DAT_40374438)(PTR_DAT_40374474,uVar8,PTR_s_cpu_start_40374418);
  }
  (*(code *)PTR_FUN_40374430)();
  pbVar3 = DAT_40374410;
  uVar14 = *(uint *)puVar4;
  memw();
  *DAT_40374410 = 1;
  if (3 < uVar14) {
    uVar8 = FUN_40381bb0();
    (*DAT_40374438)(PTR_DAT_40374478,uVar8,PTR_s_cpu_start_40374418);
  }
  (*(code *)PTR_FUN_403744e8)(auStack_40);
  if (bStack_36 < 2) {
    if (*(uint *)puVar4 != 0) {
      uVar8 = FUN_40381bb0();
      puVar5 = PTR_s_cpu_start_40374418;
      (*DAT_40374438)(PTR_DAT_4037447c,uVar8,PTR_s_cpu_start_40374418);
      if (*(int *)puVar4 != 0) {
        uVar8 = FUN_40381bb0();
        (*DAT_40374438)(PTR_DAT_40374480,uVar8,puVar5);
      }
    }
  }
  else {
    if (3 < *(uint *)puVar4) {
      uVar8 = FUN_40381bb0();
      (*DAT_40374438)(PTR_DAT_40374488,uVar8,PTR_s_cpu_start_40374418,PTR_LAB_40374484);
    }
    FUN_40379064(1);
    puVar6 = DAT_4037448c;
    memw();
    if ((*DAT_4037448c & 2) == 0) {
      memw();
      memw();
      *DAT_4037448c = *DAT_4037448c | 2;
      memw();
      memw();
      *puVar6 = *puVar6 & 0xfffffffe;
      memw();
      memw();
      *puVar6 = *puVar6 | 4;
      memw();
      memw();
      *puVar6 = *puVar6 & 0xfffffffb;
    }
    (*DAT_4037442c)(PTR_LAB_40374484);
    do {
      memw();
      bVar1 = *pbVar3;
      memw();
      bVar2 = pbVar3[1];
      (*DAT_40374444)(100);
    } while ((bVar2 & bVar1) == 0);
    (*DAT_403744ec)(uVar12 >> 0x10,uVar11 >> 0x10,PTR_DAT_40374470,DAT_4037446c,0);
    (*(code *)PTR_FUN_403744f0)();
    (*(code *)PTR_FUN_403744f4)();
    uVar17 = (*(code *)PTR_FUN_403744f8)();
    *DAT_40374490 = uVar17;
    uVar11 = rsr(in_PRID);
    iVar16 = 0;
    do {
      iVar13 = iVar16 + 1;
      (*DAT_4037443c)(uVar11 >> 0xd & 1,iVar16,6);
      iVar16 = iVar13;
    } while (iVar13 != 99);
    FUN_4037679c();
    iVar13 = FUN_403767c0();
    (*DAT_403744fc)(0);
    iVar9 = (*DAT_40374500)(iVar13 + DAT_403744b0,DAT_403744b0,DAT_403744bc,0);
    iVar16 = DAT_40374494;
    if (iVar9 != 0) {
      memw();
      uVar11 = (uint)(iVar13 << 4) / (uint)(iVar9 * 0x1c200);
      memw();
      *(uint *)(DAT_40374494 + 0x14) =
           *(uint *)(DAT_40374494 + 0x14) & 0xfffff000 | uVar11 >> 4 & 0xfff;
      memw();
      memw();
      *(uint *)(iVar16 + 0x14) = *(uint *)(iVar16 + 0x14) & DAT_40374498 | (uVar11 & 0xf) << 0x14;
      memw();
      memw();
      memw();
      uStack_34 = *(uint *)(iVar16 + 0x78) & DAT_4037449c | (iVar9 - 1U & 0xff) << 0xc;
      memw();
      memw();
      memw();
      *(uint *)(iVar16 + 0x78) = uStack_34;
      if (iVar7 == 5) {
        (*(code *)PTR_FUN_40374504)();
      }
      (*(code *)PTR_FUN_40374440)();
      acStack_30[0] = '\0';
      iVar7 = (*(code *)PTR_FUN_40374508)(acStack_30);
      if ((iVar7 == 0) && (acStack_30[0] == '\0')) goto LAB_403757fe;
      if (*(int *)puVar4 != 0) {
        uVar8 = FUN_40381bb0();
        (*DAT_40374438)(PTR_DAT_403744a0,uVar8,PTR_s_cpu_start_40374418);
      }
      while( true ) {
        FUN_40375b88();
LAB_403757fe:
        (*DAT_4037450c)(auStack_58,PTR_DAT_403744a4);
        iVar7 = (*(code *)PTR_FUN_40374510)(auStack_58);
        iVar16 = 6;
        if (iVar7 == 0) break;
        if (*(int *)puVar4 != 0) {
          uVar8 = FUN_40381bb0();
          uVar10 = (*(code *)PTR_FUN_40374514)(iVar7);
          (*DAT_40374438)(PTR_DAT_403744a8,uVar8,PTR_s_cpu_start_40374418,iVar7,uVar10);
        }
      }
      do {
        *(undefined4 *)pcVar15 = 0;
        pcVar15 = (char *)((int)pcVar15 + 4);
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
      (*DAT_4037450c)(local_70,PTR_DAT_40374470 + -0x20,0x18);
      if (local_70[0] == -0x17) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if (*(int *)puVar4 != 0) {
        uVar8 = FUN_40381bb0();
        (*DAT_40374438)(PTR_DAT_403744ac,uVar8,PTR_s_cpu_start_40374418);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40381c60();
}


