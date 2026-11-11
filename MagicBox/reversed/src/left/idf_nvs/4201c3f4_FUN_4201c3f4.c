undefined4
FUN_4201c3f4(int param_1,undefined1 param_2,uint param_3,undefined4 param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_60 [24];
  uint uStack_48;
  int aiStack_40 [4];
  uint uStack_30;
  uint *puStack_2c;
  
  uStack_30 = param_3 & 0xff;
  uVar3 = DAT_42001a70;
  if (*(int *)(param_1 + 100) == 1) {
    iVar4 = *(int *)(param_1 + 0x10);
    puStack_2c = param_5;
    if (iVar4 != 0) {
      do {
        aiStack_40[0] = 0;
        iVar1 = FUN_4201d244(iVar4,param_2,uStack_30,param_4,aiStack_40,auStack_60,0xff,0xff);
        if (iVar1 == 0) {
          uStack_48 = uStack_48 & 0xffff;
          goto LAB_4201c476;
        }
        iVar4 = *(int *)(iVar4 + 4);
      } while (iVar4 != 0);
      if (uStack_30 == 0x41) {
        uStack_30 = 0x41;
        for (iVar1 = *(int *)(param_1 + 0x10); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
          aiStack_40[0] = iVar4;
          iVar2 = FUN_4201d244(iVar1,param_2,0x48,param_4,aiStack_40,auStack_60,0xff,0xff);
          if (iVar2 == 0) {
LAB_4201c476:
            *puStack_2c = uStack_48;
            return 0;
          }
        }
      }
    }
    uVar3 = DAT_420011bc;
  }
  return uVar3;
}