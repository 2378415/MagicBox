// 40376128  FUN_40376128  FUN_40376128  size=221
// strings: cpuid == xPortGetCoreID()

void FUN_40376128(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  code *pcVar10;
  undefined4 uVar11;
  undefined1 in_PRID;
  
  uVar5 = rsr(in_PRID);
  if (param_1 != (uVar5 >> 0xd & 1)) {
    FUN_40381ce4(PTR_s_esp_ipc_c_3c031674_0x1c_40374658,0x38,PTR_s_ipc_task_40374654,
                 PTR_s_cpuid____xPortGetCoreID___40374650);
  }
  (*(code *)PTR_FUN_40374678)();
  iVar2 = DAT_40374668;
  iVar1 = DAT_4037465c;
  iVar3 = param_1 * 4;
  piVar4 = (int *)(param_1 * 4 + DAT_40374660);
  while( true ) {
    while( true ) {
      puVar6 = (undefined4 *)(DAT_40374664 + iVar3);
      do {
        FUN_4037e3f0(0,1,0xffffffff);
        memw();
        if ((*(char *)(iVar1 + param_1) != '\0') && (memw(), *piVar4 != 0)) {
          memw();
          memw();
          (*(code *)*piVar4)(*puVar6);
          memw();
          *(char *)(iVar1 + param_1) = '\0';
          memw();
          *piVar4 = 0;
        }
        piVar7 = (int *)(iVar2 + iVar3);
        memw();
      } while (*piVar7 == 0);
      memw();
      pcVar10 = (code *)*piVar7;
      memw();
      uVar11 = *(undefined4 *)(DAT_4037466c + iVar3);
      memw();
      iVar9 = *(int *)(DAT_40374670 + iVar3);
      puVar6 = (undefined4 *)(DAT_40374674 + iVar3);
      memw();
      *piVar7 = 0;
      uVar8 = *puVar6;
      if (iVar9 != 1) break;
      FUN_4037b768(uVar8,0,0,0);
      (*pcVar10)(uVar11);
    }
    if (iVar9 != 2) break;
    (*pcVar10)(uVar11);
    FUN_4037b768(uVar8,0,0,0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40381c60();
}


