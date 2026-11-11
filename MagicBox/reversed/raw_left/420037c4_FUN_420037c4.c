// 420037c4  FUN_420037c4  FUN_420037c4  size=185
// strings: cpu_start | D (%lu) %s: calling init function: %p

void FUN_420037c4(void)

{
  byte bVar1;
  byte bVar2;
  undefined *puVar3;
  byte *pbVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  
  func_0x4200373c(0);
  puVar6 = PTR_DAT_4200033c;
  puVar5 = PTR_PTR_42000338;
  puVar3 = PTR_s_cpu_start_42000320;
  for (puVar8 = (undefined4 *)PTR_PTR_42000334; puVar5 <= puVar8; puVar8 = puVar8 + -1) {
    uVar7 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(4,puVar3,puVar6,uVar7,puVar3,*puVar8);
    (*(code *)*puVar8)();
  }
  FUN_42002c88();
  func_0x4200373c(1);
  pbVar4 = DAT_4200032c;
  memw();
  memw();
  do {
    memw();
    memw();
    bVar1 = *pbVar4;
    memw();
    memw();
    memw();
    bVar2 = pbVar4[1];
    memw();
    memw();
    (*DAT_420002b8)(100);
    memw();
  } while ((bVar1 & 1 & bVar2) == 0);
  memw();
  *DAT_42000340 = 1;
  FUN_4202e834();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


