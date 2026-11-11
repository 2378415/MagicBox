// 4200c204  FUN_4200c204  FUN_4200c204  size=242

void FUN_4200c204(int param_1,int param_2,char param_3,undefined4 param_4,uint param_5,int param_6,
                 byte param_7)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  bVar1 = *(byte *)(param_1 + 0xc);
  iVar2 = param_2 * 0x20;
  memw();
  *(uint *)(*(int *)(param_1 + 8) + iVar2 + 0x510) =
       param_5 & 0x7ffff | param_6 << 0x13 | (param_7 & 3) << 0x1d;
  if (param_3 < '\0') {
    *(undefined1 *)(DAT_42000af8 + param_2 * 0x18 + (uint)bVar1 * 0xc4 + 0xe) = 1;
  }
  else {
    *(undefined1 *)(DAT_42000af8 + param_2 * 0x18 + (uint)bVar1 * 0xc4 + 0xe) = 0;
  }
  memw();
  *(undefined4 *)(iVar2 + *(int *)(param_1 + 8) + 0x514) = param_4;
  memw();
  uVar3 = *(uint *)(*(int *)(param_1 + 8) + 0x408);
  puVar4 = (uint *)(iVar2 + *(int *)(param_1 + 8) + 0x500);
  memw();
  memw();
  *puVar4 = *puVar4 & DAT_420003d4;
  puVar4 = (uint *)(iVar2 + *(int *)(param_1 + 8) + 0x500);
  memw();
  memw();
  *puVar4 = *puVar4 | ((uVar3 ^ 0xffffffff) & 1) << 0x1d;
  puVar4 = (uint *)(iVar2 + *(int *)(param_1 + 8) + 0x500);
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  *puVar4 = *puVar4 & DAT_420003e4 | DAT_42000afc;
  return;
}


