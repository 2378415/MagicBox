void entry(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  undefined1 in_VECBASE;
  undefined1 in_PRID;
  undefined8 uVar8;
  char acStack_68 [4];
  undefined1 auStack_64 [24];
  char acStack_4c [24];
  byte bStack_34;
  uint uStack_30;
  
  wsr(in_VECBASE,PTR_LAB_40374404);
  iVar2 = (*DAT_40374488)(0);
  (*DAT_40374488)(1);
  (*DAT_4037448c)(DAT_40374444,0,DAT_40374440 - DAT_40374444);
  if (iVar2 != 5) {
    (*DAT_4037448c)(DAT_4037444c,0,DAT_40374448 - DAT_4037444c);
  }
  FUN_40375370();
  FUN_4037ea38();
  (*DAT_40374490)(DAT_40374450,8,0x20);
  FUN_4037ada4();
  (*DAT_40374494)(DAT_40374454,8,0x20);
  (*DAT_40374498)(0);
  puVar1 = PTR_DAT_40374468;
  iVar6 = DAT_40374464;
  puVar5 = PTR_DAT_40374458 + (DAT_40374460 - (int)PTR_DAT_4037445c);
  iVar7 = ((uint)puVar5 >> 0x10) * 4;
  uVar4 = (DAT_40374464 - (int)PTR_DAT_40374468) + DAT_40374460;
  (*DAT_4037449c)(iVar7,-(iVar7 + -0x400));
  FUN_40377c44();
  (*(code *)PTR_FUN_403744a0)();
  (*(code *)PTR_FUN_403744a4)();
  FUN_40377c5c();
  FUN_40378c94();
  (*(code *)PTR_FUN_403744a8)();
  (*(code *)PTR_FUN_403744ac)();
  (*(code *)PTR_FUN_40374424)();
  memw();
  *DAT_40374410 = 1;
  (*(code *)PTR_FUN_403744b0)();
  (*DAT_403744b4)((uint)puVar5 >> 0x10,uVar4 >> 0x10,puVar1,iVar6,0);
  (*(code *)PTR_FUN_403744b8)();
  (*(code *)PTR_FUN_403744bc)();
  uVar8 = (*(code *)PTR_FUN_403744c0)();
  *DAT_4037446c = uVar8;
  (*(code *)PTR_FUN_4037442c)();
  FUN_40376520();
  iVar7 = FUN_4037654c();
  (*DAT_403744c4)(0);
  iVar3 = (*DAT_403744c8)(iVar7 + DAT_40374480,iVar7 + DAT_40374480 < DAT_40374480,DAT_40374484,0);
  iVar6 = DAT_40374470;
  if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_40381ce0();
  }
  uVar4 = (uint)(iVar7 << 4) / (uint)(iVar3 * 0x1c200);
  memw();
  memw();
  *(uint *)(DAT_40374470 + 0x14) = *(uint *)(DAT_40374470 + 0x14) & 0xfffff000 | uVar4 >> 4 & 0xfff;
  memw();
  memw();
  *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) & DAT_40374474 | (uVar4 & 0xf) << 0x14;
  memw();
  memw();
  memw();
  uStack_30 = *(uint *)(iVar6 + 0x78) & DAT_40374478 | (iVar3 - 1U & 0xff) << 0xc;
  memw();
  memw();
  memw();
  *(uint *)(iVar6 + 0x78) = uStack_30;
  if (iVar2 == 5) {
    (*(code *)PTR_FUN_403744cc)();
  }
  (*(code *)PTR_FUN_40374430)();
  acStack_68[0] = '\0';
  iVar2 = (*(code *)PTR_FUN_403744d0)(acStack_68);
  if ((iVar2 != 0) || (acStack_68[0] != '\0')) {
    FUN_403758d0();
  }
  (*DAT_403744d4)(auStack_64,PTR_DAT_4037447c,0x18);
  iVar2 = (*(code *)PTR_FUN_403744d8)(auStack_64);
  if (iVar2 != 0) {
    FUN_403758d0();
  }
  (*DAT_4037448c)(acStack_4c,0,0x18);
  (*DAT_403744d4)(acStack_4c,puVar1 + -0x20,0x18);
  if (acStack_4c[0] != -0x17) {
                    /* WARNING: Subroutine does not return */
    FUN_40381ce0();
  }
  memw();
  *DAT_40374414 = 1;
  memw();
  bStack_34 = 0;
  while (memw(), bStack_34 == 0) {
    memw();
    bStack_34 = 1;
    for (iVar6 = iVar2; iVar6 < 2; iVar6 = iVar6 + 1) {
      memw();
      memw();
      bStack_34 = bStack_34 & DAT_40374414[iVar6];
      memw();
    }
    (*DAT_40374434)(100);
  }
  uVar4 = rsr(in_PRID);
  (**(code **)(PTR_PTR_4037441c + (uVar4 >> 0xd & 1) * 4))();
  return;
}