int FUN_42016634(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int local_40;
  undefined4 uStack_3c;
  byte bStack_38;
  int local_37 [4];
  int aiStack_24 [9];
  
  if (param_2 == 0) {
    iVar1 = 0x102;
  }
  else {
    *(int *)(param_1 + 0x50) = param_2;
    *(uint *)(param_1 + 8) = *DAT_420010dc * param_3;
    *(undefined2 *)(param_1 + 0x40) = 0;
    *(undefined2 *)(param_1 + 0x42) = 0;
    for (piVar5 = local_37; piVar5 != aiStack_24; piVar5 = (int *)((int)piVar5 + 1)) {
      *(undefined1 *)piVar5 = 0xff;
    }
    iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0xc))
                      (*(int **)(param_1 + 0x50),*(undefined4 *)(param_1 + 8),&local_40,0x20);
    if (iVar1 == 0) {
      if (local_40 == -1) {
        *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
        iVar2 = FUN_42016d78(0x200,PTR_DAT_420010f0);
        if (iVar2 == 0) {
          return 0x101;
        }
        for (uVar4 = 0; uVar4 < *DAT_420010dc; uVar4 = uVar4 + 0x200) {
          iVar3 = (**(code **)(**(int **)(param_1 + 0x50) + 0xc))
                            (*(int **)(param_1 + 0x50),*(int *)(param_1 + 8) + uVar4,iVar2,0x200);
          if (iVar3 != 0) {
            *(undefined4 *)(param_1 + 0xc) = 0;
            FUN_42016d58(iVar2);
            return iVar3;
          }
          iVar3 = FUN_42024ee4(iVar2,iVar2 + 0x200,0);
          if (iVar2 + 0x200 != iVar3) {
            *(undefined4 *)(param_1 + 0xc) = 0xfffffff0;
            break;
          }
        }
        FUN_42016d58(iVar2);
      }
      else {
        iVar2 = FUN_420156e8(&local_40);
        if (aiStack_24[0] == iVar2) {
          *(int *)(param_1 + 0xc) = local_40;
          *(undefined4 *)(param_1 + 0x10) = uStack_3c;
          if (bStack_38 < 0xfe) {
            return DAT_42000ce4;
          }
          *(byte *)(param_1 + 0x14) = bStack_38;
        }
        else {
          local_40 = -0x10;
        }
      }
      iVar2 = *(int *)(param_1 + 0xc);
      if (iVar2 != -1) {
        if (((iVar2 == -4) || (iVar2 == -2)) || (iVar2 == -8)) {
          iVar1 = FUN_42016264(param_1);
        }
        else {
          *(undefined4 *)(param_1 + 0xc) = 0xfffffff0;
        }
      }
    }
    else {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  return iVar1;
}