/* WARNING: Control flow encountered bad instruction data */

undefined4
FUN_420139c8(undefined4 param_1,byte *param_2,uint param_3,undefined4 *param_4,uint param_5,
            int param_6,uint param_7,int param_8,undefined4 param_9,undefined1 param_10,
            byte param_11)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  FUN_4200af20(1,&param_10);
  iVar3 = FUN_42009f34(1);
  if (iVar3 == -1) {
    FUN_4200af94(1);
  }
  while( true ) {
    do {
      iVar3 = (*(code *)PTR_FUN_420010f8)(*param_4);
    } while (iVar3 == 0);
    if (param_7 == 3) break;
    if (param_7 < 4) {
      if (param_7 == 0) {
        while (param_8 != 0) {
          FUN_4200ae00(1,&param_11,1,0xffffffff);
          param_8 = param_8 + -1;
          iVar3 = 0;
          if (param_6 == 3) {
            param_5 = param_5 | (uint)param_11 << 8;
            if (param_5 < 0x201) {
              *(short *)(param_2 + 2) = (short)param_5;
              if (param_5 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
                halt_baddata();
              }
              uVar4 = (param_5 & 0xfff) >> 6;
              uVar2 = 0;
              if (param_3 <= (uint)((int)param_4 - (0x200 - param_8))) {
                uVar1 = (int)param_4 - uVar4;
                if (uVar1 < param_3) {
                  (*DAT_42000064)(iRam00000003 + uVar4,param_2,uVar1);
                  uVar4 = (uVar4 + param_3) - (int)param_4;
                  (*DAT_42000064)(iRam00000003,param_2 + uVar1,uVar4);
                  uRam0000000b = uVar4;
                }
                else {
                  (*DAT_42000064)(iRam00000003 + uVar4,param_2,param_3);
                  uRam0000000b = (param_3 + uRam0000000b) % uRam00000007;
                }
                uVar2 = 1;
              }
              return uVar2;
            }
            uVar2 = (*(code *)PTR_FUN_4200005c)();
            (*(code *)PTR_FUN_42000118)
                      (1,PTR_s_uart_events_4200120c,PTR_DAT_42001244,uVar2,
                       PTR_s_uart_events_4200120c,param_5);
            param_6 = iVar3;
          }
          else if (param_6 == 4) {
            if (param_3 < 0x800) {
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            }
            if (param_3 == param_5) {
              uart1_frame_parse();
              param_6 = iVar3;
            }
            else {
              param_6 = -0xc;
            }
          }
          else if (param_6 == 1) {
            param_2[1] = param_11;
            param_6 = 2;
          }
          else if (param_6 == 2) {
            param_5 = (uint)param_11;
            param_6 = 3;
          }
          else {
            param_6 = iVar3;
            if (param_11 == 0x5a) {
              (*DAT_42000094)(param_2,0,DAT_420005d8);
              *param_2 = param_11;
              param_6 = 1;
            }
          }
        }
      }
      else if (param_7 == 2) {
        uVar2 = FUN_420139b2();
        return uVar2;
      }
    }
    else if (param_7 == 7) {
      uVar2 = FUN_420139c8();
      return uVar2;
    }
  }
  uVar2 = FUN_420139b2();
  return uVar2;
}