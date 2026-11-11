// 4200fcb4  FUN_4200fcb4  FUN_4200fcb4  size=342

undefined4 FUN_4200fcb4(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  undefined1 uVar6;
  uint uVar7;
  int iVar8;
  
  if (((param_1 == 0) || (piVar4 = *(int **)(param_1 + 0x210), piVar4 == (int *)0x0)) ||
     (0xff < param_3 - 1)) {
LAB_4200fcb9:
    uVar1 = 0;
  }
  else {
    uVar3 = (uint)*(byte *)(param_1 + 0x20c);
    if ((param_3 == uVar3) || (*(char *)(param_2 + uVar3) == '\0')) {
      memw();
      memw();
      memw();
      if ((char)piVar4[0x7b] != '\0') goto LAB_4200fcb9;
      memw();
      memw();
      *(char *)(piVar4 + 0x7b) = '\x01';
      memw();
      memw();
      memw();
      *(undefined1 *)((int)piVar4 + 0x1ed) = 0;
      memw();
      memw();
      memw();
      piVar4[0x7a] = 0;
      memw();
    }
    else {
      iVar2 = FUN_4202d108(param_2,param_3,uVar3,piVar4);
      iVar8 = uVar3 * 8;
      do {
        uVar7 = (uint)*(byte *)(param_2 + uVar3);
        uVar5 = iVar8 + *piVar4;
        if (uVar3 == uVar5 >> 3) {
          uVar7 = 1 << 0x20 - (0x20 - (uVar5 & 7)) & uVar7 ^ uVar7;
        }
        if (uVar7 != 0) {
          memw();
          memw();
          uVar6 = 0;
          memw();
          goto LAB_4200fdb4;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 != param_3);
      memw();
      memw();
      memw();
      if (piVar4[0x7a] == iVar2) {
        memw();
        memw();
        memw();
        if (*(char *)((int)piVar4 + 0x1ed) != '\0') goto LAB_4200fcb9;
        memw();
        memw();
        *(char *)((int)piVar4 + 0x1ed) = '\x01';
        memw();
        memw();
        memw();
        *(undefined1 *)(piVar4 + 0x7b) = 0;
        memw();
      }
      else {
        uVar6 = 1;
LAB_4200fdb4:
        memw();
        memw();
        *(undefined1 *)(piVar4 + 0x7b) = 0;
        memw();
        memw();
        memw();
        *(undefined1 *)((int)piVar4 + 0x1ed) = uVar6;
        memw();
        memw();
        memw();
        piVar4[0x7a] = iVar2;
        memw();
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}


