undefined4 FUN_420158f0(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_30;
  uint uStack_2c;
  
  iVar3 = *(int *)((param_1 & 0xff) * 8 + DAT_420013e0 + 4);
  memw();
  memw();
  *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) | 1;
  uVar2 = DAT_4200141c;
  memw();
  memw();
  *(uint *)(iVar3 + 0x804) = *(uint *)(iVar3 + 0x804) | 2;
  memw();
  *(undefined4 *)(iVar3 + 0x908) = uVar2;
  memw();
  *(undefined4 *)(iVar3 + 0xb08) = uVar2;
  memw();
  *(undefined4 *)(iVar3 + 0x810) = 0;
  memw();
  *(undefined4 *)(iVar3 + 0x814) = 0;
  memw();
  *(undefined4 *)(iVar3 + 0x81c) = 0;
  uVar1 = DAT_42001408;
  memw();
  local_30 = 0;
  do {
    memw();
    local_30 = local_30 + 1;
    memw();
    if (DAT_42001408 < local_30) goto LAB_42015995;
    memw();
  } while (-1 < *(int *)(iVar3 + 0x10));
  memw();
  local_30 = 0;
  memw();
  *(undefined4 *)(iVar3 + 0x10) = 0x420;
  do {
    memw();
    local_30 = local_30 + 1;
    memw();
    if (uVar1 < local_30) break;
    memw();
  } while ((*(uint *)(iVar3 + 0x10) & 0x20) != 0);
LAB_42015995:
  memw();
  uStack_2c = 0;
  do {
    memw();
    uStack_2c = uStack_2c + 1;
    memw();
    if (uVar1 < uStack_2c) goto LAB_420159db;
    memw();
  } while (-1 < *(int *)(iVar3 + 0x10));
  memw();
  uStack_2c = 0;
  memw();
  *(undefined4 *)(iVar3 + 0x10) = 0x10;
  do {
    memw();
    uStack_2c = uStack_2c + 1;
    memw();
    if (uVar1 < uStack_2c) break;
    memw();
  } while ((*(uint *)(iVar3 + 0x10) & 0x10) != 0);
LAB_420159db:
  FUN_42016a08();
  return 0;
}