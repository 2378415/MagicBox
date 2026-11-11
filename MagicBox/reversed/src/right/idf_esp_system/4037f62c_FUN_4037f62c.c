undefined4 FUN_4037f62c(int *param_1,int param_2)

{
  char cVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  puVar2 = (uint *)param_1[1];
  iVar5 = param_1[5];
  cVar1 = *(char *)(param_2 + 0x16);
  if ((*(uint *)(param_2 + 0x10) & 2) != 0) {
    iVar5 = *(int *)(param_2 + 0x18);
  }
  (**(code **)(*param_1 + 0x3c))
            (param_1,*(undefined2 *)(param_2 + 0x14),*(undefined1 *)(param_2 + 3),cVar1,iVar5);
  uVar3 = (uint)*(byte *)(param_2 + 3);
  if (uVar3 == 0x20) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0xffffffff >> (uVar3 & 0x1f);
  }
  memw();
  puVar2[1] = *(int *)(param_2 + 4) << 0x20 - (0x20 - (-(uVar3 - 0x20) & 0x1f)) | uVar4;
  if (*(char *)(param_2 + 2) == '\0') {
    memw();
    memw();
    puVar2[4] = puVar2[4] & DAT_403747e0 | (uint)(cVar1 != '\0') << 0x1d;
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    puVar2[5] = puVar2[5] & 0xffffff00 | (uint)(byte)(cVar1 - 1);
  }
  uVar3 = (uint)*(byte *)(param_2 + 1);
  memw();
  memw();
  puVar2[4] = puVar2[4] & DAT_403747e4 | (uint)(uVar3 != 0) << 0x1b;
  if (uVar3 != 0) {
    memw();
    memw();
    puVar2[7] = puVar2[7] & 0xfffc0000 | uVar3 * 8 - 1 & 0x3ffff;
  }
  FUN_4037f2d0(puVar2,*(undefined4 *)(param_2 + 8),*(undefined1 *)(param_2 + 1));
  uVar3 = (uint)*(byte *)(param_2 + 2);
  memw();
  memw();
  puVar2[4] = puVar2[4] & DAT_403747e8 | (uint)(uVar3 != 0) << 0x1c;
  if (uVar3 != 0) {
    memw();
    memw();
    puVar2[7] = puVar2[7] & 0xfffc0000 | uVar3 * 8 - 1 & 0x3ffff;
  }
  memw();
  memw();
  *puVar2 = *puVar2 | DAT_403749a0;
  do {
    memw();
  } while ((*puVar2 & 0x800000) != 0);
  memw();
  memw();
  *puVar2 = *puVar2 | DAT_40374890;
  (**(code **)(*param_1 + 0x40))(param_1);
  if (*(char *)(param_2 + 2) != '\0') {
    FUN_4037f310(puVar2,*(undefined4 *)(param_2 + 0xc));
  }
  return 0;
}