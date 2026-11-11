// 4201ddd0  FUN_4201ddd0  FUN_4201ddd0  size=198

int FUN_4201ddd0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  
  iVar1 = DAT_42001a94;
  if (param_1[5] != 0) {
    if (param_1[5] == 1) {
      piVar5 = (int *)*param_1;
      iVar1 = DAT_42001a5c;
      if (piVar5 != (int *)0x0) {
        piVar2 = (int *)0x0;
        uVar6 = 0;
        do {
          if (uVar6 < -(*(ushort *)(piVar5 + 0x10) - 0x7e)) {
            piVar2 = piVar5;
            uVar6 = -(*(ushort *)(piVar5 + 0x10) - 0x7e);
          }
          piVar5 = (int *)piVar5[1];
        } while (piVar5 != (int *)0x0);
        if ((uVar6 != 0) && (iVar1 = FUN_4201dd60(param_1), iVar1 == 0)) {
          iVar3 = param_1[1];
          iVar4 = piVar2[0x10];
          iVar1 = FUN_4201dcbc(piVar2);
          if ((iVar1 == 0) &&
             (((iVar1 = FUN_4201cdc0(piVar2,iVar3), iVar1 == 0 || (iVar1 == DAT_420011bc)) &&
              (iVar1 = FUN_4201dc84(piVar2), iVar1 == 0)))) {
            if (*(short *)(iVar3 + 0x40) == (short)iVar4) {
              iVar4 = *piVar2;
              piVar5 = (int *)piVar2[1];
              if (iVar4 == 0) {
                *param_1 = piVar5;
              }
              else {
                *(int **)(iVar4 + 4) = piVar5;
              }
              if (piVar5 == (int *)0x0) {
                param_1[1] = iVar4;
              }
              else {
                *piVar5 = iVar4;
              }
              iVar4 = param_1[4];
              param_1[2] = param_1[2] + -1;
              if (iVar4 != 0) {
                *(int **)(iVar4 + 4) = piVar2;
              }
              piVar2[1] = 0;
              *piVar2 = iVar4;
              param_1[4] = piVar2;
              if (param_1[3] == 0) {
                param_1[3] = piVar2;
              }
              param_1[5] = param_1[5] + 1;
            }
            else {
              iVar1 = -1;
            }
          }
        }
      }
    }
    else {
      iVar1 = FUN_4201dd60(param_1);
    }
  }
  return iVar1;
}


