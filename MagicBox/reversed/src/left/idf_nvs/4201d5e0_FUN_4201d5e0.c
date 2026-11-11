/* WARNING: Instruction at (ram,0x4201d60e) overlaps instruction at (ram,0x4201d60d)
    */
/* WARNING: Control flow encountered bad instruction data */

int FUN_4201d5e0(uint param_1,undefined1 param_2,uint param_3,int param_4,int param_5,uint param_6,
                undefined1 param_7,undefined1 param_8)

{
  uint unaff_retaddr;
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_80 [32];
  undefined1 auStack_60 [2];
  byte bStack_5e;
  ushort uStack_48;
  int iStack_44;
  int aiStack_40 [4];
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  
  aiStack_40[0] = 0;
  iVar1 = DAT_42001a94;
  if ((*(int *)(param_1 + 0xc) != 0) &&
     (iVar1 = FUN_4201d244(param_1,param_2,param_3 & 0xff,param_4,aiStack_40,auStack_60,param_7,
                           param_8), iVar1 == 0)) {
    if ((param_3 & 0xff) == 0x21) {
      uVar2 = (uint)uStack_48;
      if (param_6 < uVar2) {
        return 0x102;
      }
      uVar3 = aiStack_40[0] + 1;
      iStack_30 = iVar1;
      if (uVar3 < (uint)bStack_5e + aiStack_40[0]) {
        iStack_30 = aiStack_40[0];
        iStack_2c = iVar1;
        iStack_28 = param_5;
        do {
          if (0x7d < uVar3) {
            return -1;
          }
          iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x10))
                            (*(int **)(param_1 + 0x50),*(int *)(param_1 + 8) + 0x40 + uVar3 * 0x20,
                             auStack_80,0x20);
          iVar4 = (uVar2 < 0x20) * uVar2 + (uint)(uVar2 >= 0x20) * 0x20;
          if (iVar1 != 0) {
            return iVar1;
          }
          iVar1 = (*DAT_42000114)(param_5,auStack_80,iVar4);
          uVar3 = uVar3 + 1;
          if (iVar1 != 0) {
            return DAT_42001a68;
          }
          uVar2 = uVar2 - iVar4;
          param_5 = param_5 + iVar4;
        } while (uVar3 < (uint)bStack_5e + iStack_30);
        uVar2 = (uint)uStack_48;
        param_5 = iStack_28;
        iStack_30 = iStack_2c;
      }
      iVar4 = FUN_4201e2c0(param_5,uVar2);
      iVar1 = iStack_30;
      if (iVar4 != iStack_44) {
        iVar1 = DAT_420011bc;
      }
    }
    else {
      if (param_6 == (param_3 & 0xf)) {
        if (unaff_retaddr <= param_1) {
          *(uint *)(param_4 + 0x30c) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        (*(code *)PTR_FUN_420004e0)();
        return 0;
      }
      iVar1 = DAT_42001aa0;
    }
  }
  return iVar1;
}