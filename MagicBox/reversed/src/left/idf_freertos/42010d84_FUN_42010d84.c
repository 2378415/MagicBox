void FUN_42010d84(int param_1,int param_2)

{
  undefined *puVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int local_30;
  
  if (((param_1 != 0) && (*(char *)(param_1 + 2) != '\0')) &&
     (*(char *)(*(int *)(param_2 + 0x214) + 0x61) == *(char *)(param_1 + 2))) {
    (*DAT_42000094)(param_2 + 0x636,0,0x100);
    iVar4 = *(int *)(param_2 + 0x214);
    uVar6 = (uint)*(byte *)(iVar4 + 0x58);
    if (uVar6 != 0) {
      piVar3 = (int *)(iVar4 + 8);
      uVar5 = 0;
      do {
        local_30 = param_1 + 4;
        if (*piVar3 != 0) {
          bVar2 = hid_report_get_bits(local_30,*piVar3,*(undefined1 *)(iVar4 + uVar5 + 0x48),
                               *(undefined1 *)(param_1 + 2));
          if (bVar2 != 0) {
            *(undefined1 *)(param_2 + (uint)bVar2 + 0x636) = 1;
          }
          uVar6 = (uint)*(byte *)(iVar4 + 0x58);
        }
        uVar5 = uVar5 + 1;
        piVar3 = piVar3 + 1;
      } while (uVar5 < uVar6);
    }
    puVar1 = PTR_DAT_42000ec8;
    local_30 = param_1 + 4;
    (*(code *)PTR_FUN_420004dc)(PTR_DAT_42000ec8,0xffffffff);
    (*DAT_42000064)(param_2 + 0x52e,local_30,*(undefined1 *)(param_1 + 2));
    *(uint *)(param_2 + 0x630) = (uint)*(byte *)(param_1 + 2);
    memw();
    memw();
    *(undefined1 *)(param_2 + 0x52d) = 1;
    memw();
    (*(code *)PTR_FUN_420004e0)(puVar1);
    memw();
    if (param_2 != *DAT_42000dc4) {
      memw();
      *DAT_42000dc4 = param_2;
    }
    memw();
    memw();
    *DAT_42000ecc = 1;
    memw();
    if (*DAT_42000ed0 != 0) {
      (*(code *)PTR_FUN_42000484)(*DAT_42000ed0,0,0,2);
    }
  }
  return;
}