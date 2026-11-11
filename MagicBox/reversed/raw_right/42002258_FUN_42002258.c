// 42002258  FUN_42002258  FUN_42002258  size=119

/* WARNING: Control flow encountered bad instruction data */

void FUN_42002258(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 in_PRID;
  undefined1 auStack_50 [80];
  
  (*DAT_42000240)(auStack_50,0,0x24);
  uVar3 = rsr(in_PRID);
  uVar3 = uVar3 >> 0xd & 1;
  *(undefined4 *)(uVar3 * 4 + DAT_42000210) = param_1;
  if (param_2 != 0) {
    iVar1 = FUN_42024474(param_1);
    if ((iVar1 == 5) && (uVar3 == 1)) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    iVar1 = FUN_42024474(param_1);
    if ((iVar1 == 6) && (uVar3 == 0)) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    iVar1 = FUN_42024474(param_1);
    if (iVar1 == 7) {
      iVar1 = FUN_42001c04();
      if (iVar1 == -1) {
        if (uVar3 != 0) {
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
      }
      else {
        uVar2 = FUN_42001c04();
        if (uVar2 != uVar3) {
          *(undefined4 *)(uVar3 * 4 + DAT_42000210) = 0;
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
      }
    }
  }
  FUN_42001ec0(1000);
  (*DAT_42000078)(1);
  cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


