// strings: uart_events

/* WARNING: Control flow encountered bad instruction data */
/* (4 unreachable decompiler blocks omitted) */

undefined4 uart_events(void)

{
  byte *pbVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint local_50;
  int iStack_4c;
  byte abStack_40 [16];
  undefined4 uStack_30;
  
  puVar2 = DAT_42001240;
  pbVar1 = DAT_42001220;
  iVar6 = 0;
  uStack_30 = 0;
  uVar5 = 0;
  while( true ) {
    do {
      iVar3 = (*(code *)PTR_FUN_420010f8)(*puVar2,&local_50,0xffffffff);
    } while (iVar3 == 0);
    if (local_50 == 3) break;
    if (local_50 < 4) {
      if (local_50 == 0) {
        while (iStack_4c != 0) {
          FUN_4200ae00(1,abStack_40,1,0xffffffff);
          iStack_4c = iStack_4c + -1;
          if (iVar6 == 3) {
            uVar5 = uVar5 | (uint)abStack_40[0] << 8;
            if (uVar5 < 0x201) {
              *(short *)(pbVar1 + 2) = (short)uVar5;
              if (uVar5 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
                halt_baddata();
              }
              (*DAT_42000064)(iRam00000003 + ((uVar5 & 0xfff) >> 6),pbVar1,0);
              uRam0000000b = uRam0000000b % uRam00000007;
              return 1;
            }
            uVar4 = (*(code *)PTR_FUN_4200005c)();
            (*(code *)PTR_FUN_42000118)
                      (1,PTR_s_uart_events_4200120c,PTR_DAT_42001244,uVar4,
                       PTR_s_uart_events_4200120c,uVar5);
            iVar6 = 0;
          }
          else {
            if (iVar6 == 4) {
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            }
            if (iVar6 == 1) {
              pbVar1[1] = abStack_40[0];
              iVar6 = 2;
            }
            else if (iVar6 == 2) {
              uVar5 = (uint)abStack_40[0];
              iVar6 = 3;
            }
            else {
              iVar6 = 0;
              if (abStack_40[0] == 0x5a) {
                (*DAT_42000094)(pbVar1,0,DAT_420005d8);
                *pbVar1 = abStack_40[0];
                iVar6 = 1;
              }
            }
          }
        }
      }
      else if (local_50 == 2) {
        uVar4 = FUN_420139b2();
        return uVar4;
      }
    }
    else if (local_50 == 7) {
      uVar4 = FUN_420139c8();
      return uVar4;
    }
  }
  uVar4 = FUN_420139b2();
  return uVar4;
}