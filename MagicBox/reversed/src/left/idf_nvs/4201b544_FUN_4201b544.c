void FUN_4201b544(int param_1,int *param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  byte bVar7;
  char acStack_100 [3];
  byte bStack_fd;
  undefined1 auStack_f8 [24];
  undefined1 auStack_e0 [32];
  undefined1 auStack_c0 [32];
  undefined1 auStack_a0 [32];
  undefined1 auStack_80 [32];
  undefined1 auStack_60 [2];
  byte bStack_5e;
  ushort uStack_48;
  int aiStack_40 [4];
  undefined1 *puStack_30;
  int iStack_2c;
  int *piStack_28;
  int iStack_24;
  
  iStack_2c = *(int *)(param_1 + 0x10);
  iStack_24 = param_1;
  if (iStack_2c != 0) {
    puStack_30 = auStack_60;
    piStack_28 = aiStack_40;
    do {
      aiStack_40[0] = 0;
      while (iVar3 = FUN_4201d244(iStack_2c,0xff,0x42,0,piStack_28,puStack_30,0xff,0xff), iVar3 == 0
            ) {
        iVar3 = *param_2;
        (*DAT_42000064)(auStack_80,puStack_30,0x20);
        (*DAT_42000064)(auStack_a0,auStack_80,0x20);
        (*DAT_42000064)(auStack_e0,auStack_a0,0x20);
        (*DAT_42000064)(acStack_100,auStack_e0,0x20);
        (*DAT_42000064)(auStack_c0,acStack_100,0x20);
        (*DAT_42000064)(auStack_e0,auStack_c0,0x20);
        (*DAT_42000064)(acStack_100,auStack_e0,0x20);
        bVar2 = bStack_fd;
        cVar1 = acStack_100[0];
        for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
          iVar6 = (*DAT_42000c68)(auStack_f8,iVar3 + 8,0xf);
          if ((iVar6 == 0) && (*(char *)(iVar3 + 0x18) == cVar1)) {
            bVar7 = 0xff;
            if (*(byte *)(iVar3 + 0x1a) == 0) {
              bVar7 = 0x80;
            }
            if ((*(byte *)(iVar3 + 0x1a) <= bVar2) && (bVar2 < bVar7)) {
              *(uint *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + (uint)uStack_48;
              *(int *)(iVar3 + 0x24) = *(int *)(iVar3 + 0x24) + 1;
              break;
            }
          }
        }
        aiStack_40[0] = aiStack_40[0] + (uint)bStack_5e;
      }
      iStack_2c = *(int *)(iStack_2c + 4);
    } while (iStack_2c != 0);
    iStack_2c = 0;
  }
  piVar4 = (int *)*param_2;
  do {
    if (piVar4 == (int *)0x0) {
      return;
    }
    while ((piVar4[8] != piVar4[7] || (piVar4[9] != (uint)*(byte *)((int)piVar4 + 0x19)))) {
      for (iVar3 = *(int *)(iStack_24 + 0x10); iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
        iVar6 = *(int *)(iVar3 + 0xc);
        if (((iVar6 != -0x10 && iVar6 != 0) && (iVar6 != -1 && (iVar6 != -0x10 && iVar6 != 0))) &&
           (iVar6 = FUN_4201d70c(iVar3,(char)piVar4[6],0x48,piVar4 + 2,0xff,
                                 *(undefined1 *)((int)piVar4 + 0x1a)), iVar6 == 0)) break;
      }
      iVar3 = *piVar4;
      piVar5 = (int *)piVar4[1];
      if (iVar3 == 0) {
        *param_2 = (int)piVar5;
      }
      else {
        *(int **)(iVar3 + 4) = piVar5;
      }
      iVar6 = param_2[2];
      if (piVar5 == (int *)0x0) {
        param_2[1] = iVar3;
        param_2[2] = iVar6 + -1;
        (*(code *)PTR_FUN_42000570)(piVar4);
        return;
      }
      *piVar5 = iVar3;
      param_2[2] = iVar6 + -1;
      (*(code *)PTR_FUN_42000570)(piVar4);
      piVar4 = piVar5;
    }
    piVar4 = (int *)piVar4[1];
  } while( true );
}