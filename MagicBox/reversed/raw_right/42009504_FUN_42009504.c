// 42009504  FUN_42009504  FUN_42009504  size=132

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_42009504(undefined4 param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  
  while( true ) {
    memw();
    if ((DAT_42000190[1] & 2) != 0) {
      bVar1 = false;
      while ((!bVar1 && (memw(), (DAT_42000190[1] & 2) != 0))) {
        memw();
        *DAT_42000190 = param_2 & 0xff;
        bVar1 = true;
      }
      if (param_2 == 10) {
        memw();
        memw();
        DAT_42000190[1] = DAT_42000190[1] | 1;
      }
      uVar3 = (*(code *)PTR_FUN_4200074c)();
      *(undefined8 *)(PTR_DAT_42000920 + 0x28) = uVar3;
      return;
    }
    uVar3 = (*(code *)PTR_FUN_4200074c)();
    iVar2 = (int)((ulonglong)uVar3 >> 0x20) - *(int *)(PTR_DAT_42000920 + 0x2c);
    if ((uint)uVar3 < *(uint *)(PTR_DAT_42000920 + 0x28)) {
      iVar2 = iVar2 + -1;
    }
    if (0 < iVar2) break;
    if ((iVar2 == 0) && (DAT_42000924 < (uint)uVar3 - *(uint *)(PTR_DAT_42000920 + 0x28))) {
      return;
    }
  }
  return;
}


