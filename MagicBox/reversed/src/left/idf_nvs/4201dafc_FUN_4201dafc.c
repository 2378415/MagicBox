int FUN_4201dafc(int param_1,int *param_2,int param_3)

{
  uint *puVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint local_50;
  undefined4 uStack_4c;
  byte bStack_48;
  undefined1 local_47;
  int iStack_34;
  int iStack_30;
  
  puVar1 = DAT_42001aa4;
  if (param_2 == (int *)0x0) {
    iVar3 = 0x102;
  }
  else {
    *(int **)(param_1 + 0x50) = param_2;
    uVar6 = *puVar1;
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(uint *)(param_1 + 8) = param_3 * uVar6;
    local_47 = 0xff;
    iVar3 = (**(code **)(*param_2 + 0xc))(param_2,param_3 * uVar6,&local_50,0x20);
    puVar2 = PTR_DAT_42001aa8;
    if (iVar3 == 0) {
      if (local_50 == 0xffffffff) {
        *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
        piVar4 = (int *)FUN_4201e5b0(0x200,puVar2);
        if (piVar4 == (int *)0x0) {
          return 0x101;
        }
        uVar6 = 0;
        if (*puVar1 != 0) {
          do {
            iStack_30 = (**(code **)(**(int **)(param_1 + 0x50) + 0xc))
                                  (*(int **)(param_1 + 0x50),uVar6 + *(int *)(param_1 + 8),piVar4,
                                   0x200);
            if (iStack_30 != 0) {
              *(undefined4 *)(param_1 + 0xc) = 0;
              FUN_4201e590(piVar4);
              return iStack_30;
            }
            piVar7 = piVar4;
            do {
              if (*piVar7 != -1) {
LAB_4201dbb9:
                if (piVar4 + 0x80 != piVar7) {
                  *(undefined4 *)(param_1 + 0xc) = 0xfffffff0;
                  goto LAB_4201dbcd;
                }
                break;
              }
              if (piVar7[1] != -1) {
                piVar7 = piVar7 + 1;
                goto LAB_4201dbb9;
              }
              if (piVar7[2] != -1) {
                piVar7 = piVar7 + 2;
                goto LAB_4201dbb9;
              }
              if (piVar7[3] != -1) {
                piVar7 = piVar7 + 3;
                goto LAB_4201dbb9;
              }
              piVar7 = piVar7 + 4;
            } while (piVar4 + 0x80 != piVar7);
            uVar6 = uVar6 + 0x200;
          } while (uVar6 < *puVar1);
        }
LAB_4201dbcd:
        FUN_4201e590(piVar4);
        uVar6 = *(uint *)(param_1 + 0xc);
      }
      else {
        iVar5 = (*DAT_42000cd4)(0xffffffff,&uStack_4c,0x18);
        if (iStack_34 == iVar5) {
          *(undefined4 *)(param_1 + 0x10) = uStack_4c;
          *(uint *)(param_1 + 0xc) = local_50;
          if (bStack_48 < 0xfe) {
            return DAT_420011d0;
          }
          *(byte *)(param_1 + 0x14) = bStack_48;
          uVar6 = local_50;
        }
        else {
          local_50 = 0xfffffff0;
          uVar6 = *(uint *)(param_1 + 0xc);
        }
      }
      if (uVar6 != 0xffffffff) {
        if (((uVar6 & 0xfffffffb) == 0xfffffff8) || (uVar6 == 0xfffffffe)) {
          iVar3 = FUN_4201d748(param_1);
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
  return iVar3;
}