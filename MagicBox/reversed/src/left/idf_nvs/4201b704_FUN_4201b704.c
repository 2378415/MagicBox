void FUN_4201b704(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char acStack_100 [3];
  byte bStack_fd;
  undefined1 auStack_f8 [24];
  undefined1 auStack_e0 [32];
  undefined1 auStack_c0 [32];
  undefined1 auStack_a0 [32];
  undefined1 auStack_80 [32];
  undefined1 uStack_60;
  undefined1 uStack_5f;
  byte bStack_5e;
  undefined1 uStack_5d;
  undefined1 auStack_58 [24];
  int aiStack_40 [4];
  int *piStack_30;
  int *piStack_2c;
  undefined1 *puStack_28;
  
  iVar2 = *(int *)(param_1 + 0x10);
  if (iVar2 != 0) {
    puStack_28 = auStack_58;
    piStack_2c = param_2;
    do {
      aiStack_40[0] = 0;
      piStack_30 = aiStack_40;
      while( true ) {
        iVar5 = FUN_4201d244(iVar2,0xff,0x42,0,piStack_30,&uStack_60,0xff,0xff);
        if (iVar5 != 0) break;
        iVar5 = *piStack_2c;
        uVar3 = (*DAT_42000064)(auStack_80,&uStack_60,0x20);
        (*DAT_42000064)(auStack_a0,uVar3,0x20);
        (*DAT_42000064)(auStack_e0,auStack_a0,0x20);
        (*DAT_42000064)(acStack_100,auStack_e0,0x20);
        (*DAT_42000064)(auStack_c0,acStack_100,0x20);
        (*DAT_42000064)(auStack_e0,auStack_c0,0x20);
        (*DAT_42000064)(acStack_100,auStack_e0,0x20);
        cVar1 = acStack_100[0];
        if (iVar5 != 0) {
          uVar6 = (uint)bStack_fd;
          do {
            iVar4 = (*DAT_42000c68)(auStack_f8,iVar5 + 8,0xf);
            if ((((iVar4 == 0) && (*(char *)(iVar5 + 0x18) == cVar1)) &&
                (*(byte *)(iVar5 + 0x1a) <= uVar6)) &&
               (uVar6 < (uint)*(byte *)(iVar5 + 0x19) + (uint)*(byte *)(iVar5 + 0x1a)))
            goto LAB_4201b7e4;
            iVar5 = *(int *)(iVar5 + 4);
          } while (iVar5 != 0);
        }
        FUN_4201d70c(iVar2,uStack_60,uStack_5f,puStack_28,uStack_5d,0xff);
LAB_4201b7e4:
        aiStack_40[0] = aiStack_40[0] + (uint)bStack_5e;
      }
      iVar2 = *(int *)(iVar2 + 4);
    } while (iVar2 != 0);
  }
  return;
}