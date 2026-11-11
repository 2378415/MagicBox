// 4037c5bc  prvProcessReceivedCommands  FUN_4037c5bc  size=282
// strings: ( pxTimer->xTimerPeriodInTicks > 0 ) | timers.c | prvProcessReceivedCommands

void FUN_4037c5bc(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *extraout_a3;
  uint uVar4;
  code *pcVar5;
  int local_40;
  code *pcStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  undefined1 auStack_30 [48];
  
  do {
    while( true ) {
      while( true ) {
        do {
          iVar3 = FUN_4037b720(*DAT_40374dd0,&local_40,0);
          if (iVar3 == 0) {
            return;
          }
          if (local_40 < 0) {
            (*pcStack_3c)(iStack_38,uStack_34);
          }
          iVar3 = iStack_38;
        } while (local_40 < 0);
        memw();
        if (*(int *)(iStack_38 + 0x14) != 0) {
          FUN_4037c980(iStack_38 + 4);
        }
        iVar1 = FUN_4037c514(auStack_30);
        if (local_40 != 5) break;
        if ((*(byte *)(iVar3 + 0x24) & 2) == 0) {
          FUN_4037c060(iVar3);
        }
        else {
          *(byte *)(iVar3 + 0x24) = *(byte *)(iVar3 + 0x24) & 0xfe;
        }
      }
      if (local_40 < 6) break;
      if (local_40 == 8) {
LAB_4037c670:
        *(byte *)(iVar3 + 0x24) = *(byte *)(iVar3 + 0x24) & 0xfe;
      }
      else if (local_40 < 9) {
        uVar4 = local_40 - 6;
joined_r0x4037c61b:
        if (uVar4 < 2) {
          *(byte *)(iVar3 + 0x24) = *(byte *)(iVar3 + 0x24) | 1;
          iVar2 = FUN_4037c428(iVar3,pcStack_3c + *(int *)(iVar3 + 0x18),iVar1);
          if (iVar2 != 0) {
            if ((*(byte *)(iVar3 + 0x24) & 4) == 0) {
              *(byte *)(iVar3 + 0x24) = *(byte *)(iVar3 + 0x24) & 0xfe;
            }
            else {
              FUN_4037c47c(iVar3,pcStack_3c + *(int *)(iVar3 + 0x18),iVar1);
            }
            (**(code **)(iVar3 + 0x20))(iVar3);
          }
        }
      }
      else if (local_40 == 9) goto LAB_4037c681;
    }
    if (local_40 == 3) goto LAB_4037c670;
    if (local_40 < 4) {
      uVar4 = local_40 - 1;
      goto joined_r0x4037c61b;
    }
    if (local_40 == 4) {
LAB_4037c681:
      *(byte *)(iVar3 + 0x24) = *(byte *)(iVar3 + 0x24) | 1;
      *(code **)(iVar3 + 0x18) = pcStack_3c;
      pcVar5 = pcStack_3c;
      if (pcStack_3c == (code *)0x0) {
        FUN_40381d9c(PTR_s_timers_c_3c035ea0_0x2a_40374ddc,0x3b7,
                     PTR_s_prvProcessReceivedCommands_40374dd8,
                     PTR_s___pxTimer_>xTimerPeriodInTicks_>_40374dd4);
        pcVar5 = extraout_a3;
      }
      FUN_4037c428(iVar3,pcVar5 + iVar1,iVar1,iVar1);
    }
  } while( true );
}


