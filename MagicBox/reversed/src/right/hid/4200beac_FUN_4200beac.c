// strings: Fail to alloc hid_class | HID descriptor not found | HID report descriptor not found | HID interface not found | /dev/input%d

undefined4 FUN_4200beac(int param_1,byte param_2)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  uVar3 = (uint)param_2;
  piVar1 = (int *)FUN_4200be20();
  if (piVar1 == (int *)0x0) {
    (*DAT_42000634)(PTR_DAT_42000ad8);
    (*DAT_42000634)(PTR_s_Fail_to_alloc_hid_class_42000adc);
    (*DAT_42000634)(PTR_DAT_42000ae0);
    uVar2 = 0xffffffff;
  }
  else {
    *piVar1 = param_1;
    *(byte *)((int)piVar1 + 0x8f) = param_2;
    *(int **)(uVar3 * 0x144 + param_1 + 0x3c) = piVar1;
    for (pbVar4 = *(byte **)(param_1 + 0xa54); *pbVar4 != 0; pbVar4 = pbVar4 + *pbVar4) {
      if ((pbVar4[1] == 4) && (uVar3 == pbVar4[2])) {
        *(byte *)((int)piVar1 + 0x8e) = pbVar4[7];
        if (pbVar4[10] != 0x21) {
          (*DAT_42000634)(PTR_DAT_42000ad8);
          (*DAT_42000634)(PTR_s_HID_descriptor_not_found_42000ae4);
          (*DAT_42000634)(PTR_DAT_42000ae0);
          return 0xfffffffe;
        }
        if (pbVar4[0xf] != 0x22) {
          (*DAT_42000634)(PTR_DAT_42000ad8);
          (*DAT_42000634)(PTR_s_HID_report_descriptor_not_found_42000ae8);
          (*DAT_42000634)(PTR_DAT_42000ae0);
          return 0xfffffffe;
        }
        *(undefined2 *)(piVar1 + 0x23) = *(undefined2 *)(pbVar4 + 0x10);
        for (uVar6 = 0; uVar6 < *(byte *)(uVar3 * 0x144 + param_1 + 0x44); uVar6 = uVar6 + 1 & 0xff)
        {
          iVar5 = uVar3 * 0x144 + uVar6 * 7;
          iVar7 = param_1 + iVar5 + 0x49;
          if (*(char *)(param_1 + iVar5 + 0x4b) < '\0') {
            piVar1[1] = iVar7;
          }
          else {
            piVar1[2] = iVar7;
          }
        }
        FUN_42017b5c(param_1 + uVar3 * 0x144 + 0x28,0x10,PTR_s__dev_input_d_42000af0,
                     (char)piVar1[0x24]);
        FUN_42010198(piVar1);
        return 0;
      }
    }
    (*DAT_42000634)(PTR_DAT_42000ad8);
    (*DAT_42000634)(PTR_s_HID_interface_not_found_42000aec);
    (*DAT_42000634)(PTR_DAT_42000ae0);
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}