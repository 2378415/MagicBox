void usb_event_handler(int *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  int *piVar5;
  char *pcVar6;
  undefined1 uVar7;
  int iVar8;
  int iVar9;
  undefined1 *local_30;
  undefined1 auStack_2c [4];
  int aiStack_28 [10];
  
  if ((param_1 != (int *)0x0) && (param_1[1] != 0)) {
    bVar1 = *(byte *)(param_1[1] + 2);
    uVar4 = bVar1 & 0xf;
    if ((bVar1 & 8) == 0) {
      pcVar6 = (char *)(DAT_42000d6c + uVar4);
      memw();
      memw();
      if (*pcVar6 != '\0') {
        piVar5 = (int *)(uVar4 * 4 + DAT_42000d70);
        memw();
        memw();
        if ((int *)*piVar5 == param_1) {
          bVar2 = *(byte *)(uVar4 * 0x24 + DAT_42000d68 + 0x20);
          local_30 = *(undefined1 **)((uVar4 * 9 + (uint)bVar2) * 4 + DAT_42000d68);
          if (param_2 < 1) {
            if (param_2 == -10) {
              memw();
              memw();
              if (*pcVar6 != '\0') {
                memw();
                memw();
                if ((int *)*piVar5 == param_1) {
                  iVar8 = param_1[1];
                  uVar3 = *(ushort *)(iVar8 + 4);
                  param_1[5] = *param_1;
                  param_1[6] = iVar8;
                  param_1[8] = 0;
                  param_1[9] = (int)(local_30 + 8);
                  param_1[10] = (uint)uVar3;
                  param_1[0xd] = 0;
                  param_1[0x11] = (int)PTR_FUN_42000d74;
                  param_1[0x12] = (int)param_1;
                  if (*(byte *)(*param_1 + 3) < 3) {
                    uVar7 = *(undefined1 *)(iVar8 + 6);
                  }
                  else {
                    uVar7 = (undefined1)(1 << 0x20 - (0x20 - (*(byte *)(iVar8 + 6) - 1 & 0x1f)));
                  }
                  *(undefined1 *)((int)param_1 + 0x1d) = uVar7;
                  usb_xfer_submit(param_1 + 3);
                }
              }
            }
          }
          else {
            *local_30 = 0x5a;
            local_30[1] = 0xa2;
            local_30[4] = *(undefined1 *)((int)param_1 + 0x8f);
            local_30[5] = bVar1;
            local_30[6] = (char)param_2;
            local_30[7] = 0;
            *(ushort *)(local_30 + 2) = ((ushort)param_2 & 0xff) + 4;
            *(byte *)(uVar4 * 0x24 + DAT_42000d68 + 0x20) = bVar2 + 1 & 7;
            aiStack_28[0] = 0;
            while (iVar8 = (*(code *)PTR_FUN_42000d78)(*(undefined4 *)(uVar4 * 4 + DAT_42000d64)),
                  iVar8 == 0) {
              (*(code *)PTR_FUN_42000b68)(*(undefined4 *)(uVar4 * 4 + DAT_42000d64),auStack_2c,0);
            }
            memw();
            memw();
            if (*DAT_42000d48 != '\0') {
              (*(code *)PTR_FUN_420008a8)
                        (*(undefined4 *)(uVar4 * 4 + DAT_42000d64),&local_30,aiStack_28,0);
            }
            if (aiStack_28[0] == 1) {
              (*(code *)PTR_FUN_420008ac)();
            }
            iVar8 = *(int *)((uVar4 * 9 + (uint)*(byte *)(uVar4 * 0x24 + DAT_42000d68 + 0x20)) * 4 +
                            DAT_42000d68);
            memw();
            memw();
            if (*pcVar6 != '\0') {
              memw();
              memw();
              if ((int *)*piVar5 == param_1) {
                iVar9 = param_1[1];
                uVar3 = *(ushort *)(iVar9 + 4);
                param_1[5] = *param_1;
                param_1[6] = iVar9;
                param_1[8] = 0;
                param_1[9] = iVar8 + 8;
                param_1[10] = (uint)uVar3;
                param_1[0xd] = 0;
                param_1[0x11] = (int)PTR_FUN_42000d74;
                param_1[0x12] = (int)param_1;
                if (*(byte *)(*param_1 + 3) < 3) {
                  uVar7 = *(undefined1 *)(iVar9 + 6);
                }
                else {
                  uVar7 = (undefined1)(1 << 0x20 - (0x20 - (*(byte *)(iVar9 + 6) - 1 & 0x1f)));
                }
                *(undefined1 *)((int)param_1 + 0x1d) = uVar7;
                usb_xfer_submit(param_1 + 3);
              }
            }
          }
        }
      }
    }
  }
  return;
}