// 42014610  FUN_42014610  FUN_42014610  size=344

void FUN_42014610(int param_1)

{
  char cVar1;
  undefined *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  undefined1 auStack_70 [112];
  
  iVar4 = FUN_42015380(0);
  if (iVar4 != 0) {
    FUN_4200f8a0(*(undefined1 *)(param_1 + 1));
    iVar4 = DAT_42001334;
    piVar3 = DAT_42001330;
    cVar1 = *(char *)(param_1 + 1);
    iVar5 = *DAT_42001330;
    if (iVar5 < 1) {
      iVar7 = DAT_42001334 + iVar5 * 0x120;
      pcVar9 = DAT_42001340 + iVar5;
      *(undefined4 *)(iVar7 + 0x118) = 0;
      *piVar3 = iVar5 + 1;
      *pcVar9 = cVar1;
      *(undefined4 *)(iVar7 + 0x110) = 0;
      *(undefined4 *)(iVar7 + 0x114) = 0;
      *(undefined4 *)(iVar7 + 0x11c) = 4;
      if (iVar5 != 0) {
        return;
      }
      iVar7 = 0;
    }
    else if (*DAT_42001340 == cVar1) {
      if (*(int *)(DAT_42001334 + 0x11c) <= *(int *)(DAT_42001334 + 0x118)) {
        FUN_42014480(DAT_42001334,auStack_70);
      }
      iVar5 = 0;
      iVar7 = 0;
    }
    else {
      if (iVar5 == 6) {
        return;
      }
      iVar8 = DAT_42001334 + iVar5 * 0x120;
      DAT_42001340[iVar5] = cVar1;
      iVar7 = iVar5 << 3;
      *(undefined4 *)(iVar8 + 0x110) = 0;
      *(undefined4 *)(iVar8 + 0x114) = 0;
      *(undefined4 *)(iVar8 + 0x118) = 0;
      *(undefined4 *)(iVar8 + 0x11c) = 4;
      *piVar3 = iVar5 + 1;
    }
    (*(code *)PTR_FUN_420004dc)(PTR_DAT_4200132c,0xffffffff);
    iVar8 = (iVar7 + iVar5) * 0x20;
    iVar7 = iVar4 + iVar8;
    iVar5 = *(int *)(iVar7 + 0x118);
    if (iVar5 < *(int *)(iVar7 + 0x11c)) {
      uVar6 = *(uint *)(iVar7 + 0x110);
      (*DAT_42000064)(iVar4 + uVar6 * 0x44 + iVar8,param_1,0x44);
      puVar2 = PTR_DAT_4200132c;
      *(uint *)(iVar7 + 0x110) = uVar6 + 1 & 3;
      *(int *)(iVar7 + 0x118) = iVar5 + 1;
      (*(code *)PTR_FUN_420004e0)(puVar2);
      if (*DAT_42001344 != 0) {
        (*(code *)PTR_FUN_42000484)(*DAT_42001344,0,0,2);
      }
    }
    else {
      (*(code *)PTR_FUN_420004e0)(PTR_DAT_4200132c);
    }
  }
  return;
}


