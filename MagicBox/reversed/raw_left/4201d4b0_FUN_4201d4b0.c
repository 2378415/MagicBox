// 4201d4b0  FUN_4201d4b0  FUN_4201d4b0  size=286

/* WARNING: Control flow encountered bad instruction data */

int FUN_4201d4b0(int param_1,undefined1 param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                uint param_6,undefined1 param_7,undefined1 param_8)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_80 [32];
  undefined1 auStack_60 [2];
  byte bStack_5e;
  ushort uStack_48;
  int iStack_44;
  int aiStack_40 [4];
  int iStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  
  aiStack_40[0] = 0;
  iVar1 = DAT_42001a94;
  if ((*(int *)(param_1 + 0xc) != 0) &&
     (iStack_2c = FUN_4201d244(param_1,param_2,param_3 & 0xff,param_4,aiStack_40,auStack_60,param_7,
                               param_8), iVar1 = iStack_2c, iStack_2c == 0)) {
    if ((param_3 & 0xff) == 0x21) {
      uVar3 = (uint)uStack_48;
      if (param_6 < uVar3) {
        iVar1 = DAT_42001a64;
      }
      else {
        uVar4 = aiStack_40[0] + 1;
        iVar1 = aiStack_40[0];
        if (uVar4 < (uint)bStack_5e + aiStack_40[0]) {
          iStack_30 = aiStack_40[0];
          uStack_28 = param_5;
          do {
            if (0x7d < uVar4) {
              return -1;
            }
            iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x10))
                              (*(int **)(param_1 + 0x50),*(int *)(param_1 + 8) + 0x40 + uVar4 * 0x20
                               ,auStack_80,0x20);
            if (iVar1 != 0) {
              return iVar1;
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < (uint)bStack_5e + iStack_30);
          uVar3 = (uint)uStack_48;
          param_5 = uStack_28;
          iVar1 = iStack_30;
        }
        iStack_30 = iStack_2c;
        iStack_2c = iVar1;
        iVar2 = FUN_4201e2c0(param_5,uVar3);
        iVar1 = iStack_30;
        if ((iVar2 != iStack_44) &&
           (iVar2 = FUN_4201d0e8(param_1,iStack_2c), iVar1 = DAT_420011bc, iVar2 != 0)) {
          iVar1 = iVar2;
        }
      }
    }
    else {
      if (param_6 == (param_3 & 0xf)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      iVar1 = DAT_42001aa0;
    }
  }
  return iVar1;
}


