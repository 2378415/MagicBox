// 4037c82c  prvProcessReceivedCommands  FUN_4037c82c  size=352
// strings: ( pxTimer->xTimerPeriodInTicks > 0 )

/* WARNING: Control flow encountered bad instruction data */

void FUN_4037c82c(void)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  uint *puVar5;
  int iVar6;
  int unaff_retaddr;
  uint uVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int in_t0;
  int local_40;
  int iStack_3c;
  int iStack_38;
  
  puVar5 = DAT_40374e94;
  piVar4 = DAT_40374e88;
  piVar3 = DAT_40374e84;
  puVar2 = DAT_40374e78;
  while( true ) {
    memw();
    if (*(int *)*piVar3 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    memw();
    memw();
    FUN_4037bf44(PTR_DAT_40374e74,0xffffffff);
    uVar7 = FUN_4037d560();
    if (*puVar5 <= uVar7) break;
    while( true ) {
      puVar1 = PTR_DAT_40374e74;
      piVar10 = (int *)*piVar3;
      memw();
      if (*piVar10 == 0) break;
      memw();
      memw();
      FUN_4037c7b0(*(undefined4 *)piVar10[3],0xffffffff);
    }
    *piVar3 = *piVar4;
    *piVar4 = (int)piVar10;
    *puVar5 = uVar7;
    FUN_4037c094(puVar1);
    while (iVar9 = FUN_4037bafc(*puVar2,&local_40,0), iVar6 = iStack_38, iVar9 != 0) {
      if (local_40 < 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      memw();
      iVar9 = iStack_38;
      if (*(int *)(iStack_38 + 0x14) != 0) {
        iVar9 = FUN_4037cc94(iStack_38 + 4);
      }
      piVar8 = (int *)FUN_4037d560(iVar9);
      piVar10 = piVar8;
      if (piVar8 < (int *)*puVar5) {
        while( true ) {
          piVar10 = DAT_40374e88;
          piVar11 = (int *)*piVar3;
          memw();
          if (*piVar11 == 0) break;
          memw();
          memw();
          FUN_4037c7b0(*(undefined4 *)piVar11[3],0xffffffff);
        }
        iVar9 = *DAT_40374e88;
        *DAT_40374e88 = (int)piVar11;
        *piVar3 = iVar9;
      }
      *puVar5 = (uint)piVar8;
      if (local_40 == 5) {
        if ((*(byte *)(iVar6 + 0x24) & 2) == 0) {
          FUN_4037c43c(iVar6);
        }
        else {
          *(byte *)(iVar6 + 0x24) = *(byte *)(iVar6 + 0x24) & 0xfe;
        }
      }
      else if ((local_40 < 6) && (local_40 != 3)) {
        if (local_40 == 4) {
          *(byte *)(iVar6 + 0x24) = *(byte *)(iVar6 + 0x24) | 1;
          *(int *)(iVar6 + 0x18) = iStack_3c;
          iVar9 = iStack_3c;
          if (iStack_3c == 0) {
            iVar9 = in_t0;
            FUN_40381ce4(PTR_s_timers_c_3c03b500_0x2a_40374ea0,0x3b7,
                         PTR_s_prvProcessReceivedCommands_40374e9c,
                         PTR_s___pxTimer_>xTimerPeriodInTicks_>_40374e98);
            in_t0 = iVar9;
          }
          memw();
          *(int **)(iVar6 + 4) = (int *)(iVar9 + (int)piVar8);
          *(int *)(iVar6 + 0x10) = iVar6;
          if (piVar8 < (int *)(iVar9 + (int)piVar8)) {
            FUN_4037cc28(*piVar3,iVar6 + 4);
          }
          else {
            FUN_4037cc28(*DAT_40374e88,iVar6 + 4);
          }
        }
        else if (local_40 - 1U < 2) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
      else {
        *(int *)(unaff_retaddr + 4) = local_40;
        *(byte *)(iVar6 + 0x24) = (byte)local_40 & (byte)piVar10;
      }
    }
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


