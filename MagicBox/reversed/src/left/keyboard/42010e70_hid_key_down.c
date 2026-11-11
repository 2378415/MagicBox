void hid_key_down(int param_1,undefined2 param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  
  if ((param_1 != 0) && (iVar2 = *(int *)(param_1 + 0x214), iVar2 != 0)) {
    uVar5 = (uint)*(byte *)(iVar2 + 0x58);
    if (uVar5 != 0) {
      piVar3 = (int *)(iVar2 + 8);
      uVar4 = 0;
      do {
        if (*piVar3 != 0) {
          cVar1 = hid_report_get_bits(param_1 + 0x219,*piVar3,*(undefined1 *)(iVar2 + uVar4 + 0x48),
                               *(undefined4 *)(param_1 + 0x31c));
          if (cVar1 == '\0') {
            hid_report_set_bits(param_1 + 0x219,*(undefined4 *)(uVar4 * 4 + iVar2 + 8),
                         *(undefined1 *)(iVar2 + uVar4 + 0x48),param_2,
                         *(int *)(param_1 + 0x31c) << 3);
            break;
          }
          uVar5 = (uint)*(byte *)(iVar2 + 0x58);
        }
        uVar4 = uVar4 + 1;
        piVar3 = piVar3 + 1;
        if ((uVar5 <= uVar4) || (uVar4 == 6)) break;
      } while( true );
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