// 4200c0d8  FUN_4200c0d8  FUN_4200c0d8  size=122

int FUN_4200c0d8(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  int iStack_2c;
  uint uStack_28;
  
  uVar6 = (*DAT_4200030c)(param_1);
  iVar5 = (int)((ulonglong)uVar6 >> 0x20);
  if (*DAT_42000c4c == 0) {
    iStack_2c = 0;
  }
  else {
    uStack_28 = 0xffffffff;
    piVar2 = DAT_42000c48 + *DAT_42000c4c;
    iStack_2c = 0;
    piVar3 = DAT_42000c48;
    do {
      iVar1 = *piVar3;
      if ((iVar1 != 0) && (uVar4 = *(uint *)(iVar1 + 0x18), uVar4 <= (uint)uVar6)) {
        if (uVar4 == 0xffffffff) {
          iVar5 = 1;
        }
        if (iVar5 == 0) {
          uVar7 = (*DAT_42000114)(param_1,iVar1 + 8,uVar4);
          iVar5 = (int)((ulonglong)uVar7 >> 0x20);
          if ((int)uVar7 == 0) {
            if (iStack_2c != 0 || uVar4 != 0) {
              if (((uVar4 < (uint)uVar6) && (*(char *)(param_1 + uVar4) != '/')) ||
                 ((int)uVar4 <= (int)uStack_28)) goto LAB_4200c144;
              uStack_28 = uVar4;
            }
            iStack_2c = iVar1;
          }
        }
      }
LAB_4200c144:
      piVar3 = piVar3 + 1;
    } while (piVar3 != piVar2);
  }
  return iStack_2c;
}


