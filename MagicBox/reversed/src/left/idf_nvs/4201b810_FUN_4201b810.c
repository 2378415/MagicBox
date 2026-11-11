int FUN_4201b810(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined1 *puVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uStack_50;
  int iStack_4c;
  undefined4 auStack_48 [4];
  byte bStack_38;
  int aiStack_30 [12];
  
  iVar1 = FUN_4201de98(param_1 + 0x10,*(undefined4 *)(param_1 + 8),param_2,param_3);
  if (iVar1 == 0) {
    while (piVar7 = *(int **)(param_1 + 0x38), piVar7 != (int *)0x0) {
      iVar1 = *piVar7;
      piVar7 = (int *)piVar7[1];
      if (iVar1 == 0) {
        *(int **)(param_1 + 0x38) = piVar7;
      }
      else {
        *(int **)(iVar1 + 4) = piVar7;
      }
      if (piVar7 == (int *)0x0) {
        *(int *)(param_1 + 0x3c) = iVar1;
      }
      else {
        *piVar7 = iVar1;
      }
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + -1;
      (*(code *)PTR_FUN_42000570)();
    }
    puVar6 = (undefined1 *)(param_1 + 0x44);
    iVar1 = 0x20;
    do {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    for (iVar1 = *(int *)(param_1 + 0x10); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
      aiStack_30[0] = 0;
      while (iVar3 = FUN_4201d244(iVar1,0,1,0,aiStack_30,&uStack_50,0xff,0xff), iVar3 == 0) {
        puVar2 = (undefined4 *)(*(code *)PTR_FUN_4200056c)(0x1c);
        if (puVar2 == (undefined4 *)0x0) goto LAB_4201b950;
        *puVar2 = 0;
        puVar2[1] = 0;
        (*DAT_42000da8)(puVar2 + 2,auStack_48,0x10);
        *(undefined1 *)((int)puVar2 + 0x17) = 0;
        if (uStack_50._1_1_ != '\x01') {
          (*(code *)PTR_FUN_42000570)(puVar2);
          return -1;
        }
        iVar8 = *(int *)(param_1 + 0x3c);
        iVar3 = (uint)(bStack_38 >> 5) * 4 + param_1;
        *(uint *)(iVar3 + 0x44) = *(uint *)(iVar3 + 0x44) | 1 << 0x20 - (0x20 - (bStack_38 & 0x1f));
        *(byte *)(puVar2 + 6) = bStack_38;
        if (iVar8 == 0) {
          uVar9 = 0;
        }
        else {
          *(undefined4 **)(iVar8 + 4) = puVar2;
          uVar9 = *(undefined4 *)(param_1 + 0x3c);
        }
        iVar3 = *(int *)(param_1 + 0x38);
        *puVar2 = uVar9;
        puVar2[1] = 0;
        *(undefined4 **)(param_1 + 0x3c) = puVar2;
        if (iVar3 == 0) {
          *(undefined4 **)(param_1 + 0x38) = puVar2;
        }
        aiStack_30[0] = aiStack_30[0] + ((uint)uStack_50 >> 0x10 & 0xff);
        *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
      }
    }
    uVar5 = *(uint *)(param_1 + 0x60) | DAT_420014c0;
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 1;
    *(uint *)(param_1 + 0x60) = uVar5;
    iStack_4c = 0;
    uStack_50 = (int *)0x0;
    auStack_48[0] = 0;
    iVar1 = FUN_4201b498(param_1,&uStack_50);
    if (iVar1 == 0) {
      FUN_4201b544(param_1,&uStack_50);
      piVar7 = uStack_50;
      FUN_4201b704(param_1,&uStack_50);
      if (piVar7 != (int *)0x0) {
        while( true ) {
          while( true ) {
            iVar1 = *piVar7;
            piVar4 = (int *)piVar7[1];
            if (iVar1 == 0) break;
            *(int **)(iVar1 + 4) = piVar4;
            if (piVar4 == (int *)0x0) {
              iStack_4c = iVar1;
              (*(code *)PTR_FUN_42000570)();
            }
            else {
              *piVar4 = iVar1;
              (*(code *)PTR_FUN_42000570)();
            }
          }
          if (piVar4 == (int *)0x0) break;
          *piVar4 = 0;
          (*(code *)PTR_FUN_42000570)();
          piVar7 = piVar4;
        }
        (*(code *)PTR_FUN_42000570)(piVar7);
      }
      *(undefined4 *)(param_1 + 100) = 1;
      iVar1 = 0;
    }
    else {
LAB_4201b950:
      *(undefined4 *)(param_1 + 100) = 0;
      iVar1 = 0x101;
    }
  }
  else {
    *(undefined4 *)(param_1 + 100) = 0;
  }
  return iVar1;
}