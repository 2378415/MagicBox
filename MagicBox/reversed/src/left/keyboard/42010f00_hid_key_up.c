void hid_key_up(int param_1,ushort param_2)

{
  ushort uVar1;
  int iVar2;
  undefined1 *puVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  
  if ((param_1 != 0) && (iVar2 = *(int *)(param_1 + 0x214), iVar2 != 0)) {
    uVar6 = (uint)*(byte *)(iVar2 + 0x58);
    if (uVar6 != 0) {
      piVar4 = (int *)(iVar2 + 8);
      puVar3 = (undefined1 *)(iVar2 + 0x48);
      uVar5 = 0;
      do {
        if (*piVar4 != 0) {
          uVar1 = hid_report_get_bits(param_1 + 0x219,*piVar4,*puVar3,*(undefined4 *)(param_1 + 0x31c));
          if ((uVar1 & 0xff) == param_2) {
            hid_report_set_bits(param_1 + 0x219,*piVar4,*puVar3,0,*(int *)(param_1 + 0x31c) << 3);
          }
          uVar6 = (uint)*(byte *)(iVar2 + 0x58);
        }
        uVar5 = uVar5 + 1;
        piVar4 = piVar4 + 1;
        puVar3 = puVar3 + 1;
      } while ((uVar5 < uVar6) && (uVar5 != 6));
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